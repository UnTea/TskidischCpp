#include "hdr.hpp"
#include "reader.hpp"


#include <string>
#include <fstream>
#include <stdexcept>


struct Header {
    size_t width
         , height;

    Header(size_t width, size_t height)
    : width(width)
    , height(height)
    {};
};

std::vector<std::string> split_string_by_delimiter(const std::string &string, const std::string& delimiter) {
    size_t start
         , end = 0;
    std::vector<std::string> words{};

    while ((start = string.find_first_not_of(delimiter, end)) != std::string::npos) {
        end = string.find(delimiter, start);
        words.push_back(string.substr(start, end - start));
    }

    return words;
}

Header parse_header(Reader& reader) {
    std::string signature = reader.read_string_to_line_break();

    if (signature != "#?RADIANCE") {
        throw std::runtime_error("Is not a *.hdr file");
    }

    while (true) {
        std::string string = reader.read_string_to_line_break();

        if (string.empty()) {
            break;
        }

        if (!string.starts_with("FORMAT")) {
            continue;
        }

        std::vector<std::string> words = split_string_by_delimiter(string, "=");

        if (words[1] != "32-bit_rle_rgbe") {
            throw std::runtime_error("Does not match 32-bit_rle_rgbe format");
        }
    }

    std::string string = reader.read_string_to_line_break()
              , delimiter = " ";
    std::vector<std::string> resolution = split_string_by_delimiter(string, delimiter);

    if (resolution.empty()) {
        throw std::runtime_error("An incorrect environment map resolution ");
    }

    size_t height = stoi(resolution[1])
         , width = stoi(resolution[3]);

    return {width, height};
}

Vector<float> decode_rgbe(float r, float g, float b, float e) {
    float diff = 128.0f + 8.0f;
    float exp = std::pow(2.0f, e - diff);
    float r_decoded = r * exp;
    float g_decoded = g * exp;
    float b_decoded = b * exp;

    return Vector<float>(r_decoded, g_decoded, b_decoded);
}

void unpack_rle(size_t y, Reader& reader, Image& image) {
    std::vector<std::uint8_t> red(image.get_width())
                            , green(image.get_width())
                            , blue(image.get_width())
                            , exp(image.get_width());

    std::uint16_t new_rle_indicator = reader.read_uint16_t();

    if (new_rle_indicator != 0x0202) {
        throw std::runtime_error("Only new RLE HDRs are supported!");
    }

    std::uint16_t scanline_width = reader.read_uint16_t();

    if (scanline_width != image.get_width()) {
        throw std::runtime_error("Bad scanline width!");
    }

    for (size_t i = 0; i < 4; i++) {
        size_t x = 0;
        std::vector<std::vector<std::uint8_t>> color {red, green, blue, exp};

        while (x < image.get_width()) {
            std::uint8_t count = reader.read_uint8_t();

            if (count > 128) {
                count &= 0x7F;
                std::uint8_t value = reader.read_uint8_t();

                for (size_t j = 0; j < count; j++) {
                    color[i][x] = value;
                    x++;
                }
            } else {
                for (size_t j = 0; j < count; j++) {
                    color[i][x] = reader.read_uint8_t();
                    x++;
                }
            }
        }
    }

    for (size_t x = 0; x < image.get_width(); x++) {
        Vector<float> color = decode_rgbe(red[x], green[x], blue[x], exp[x]);
        image.set_pixel(x, y, color);
    }
}

Image load_hdr(const std::filesystem::path& path) {
    std::vector<uint8_t> buffer;
    std::ifstream file(path);

    if (file.fail()) {
        throw std::runtime_error("Couldn't open the file!");
    }

    file.seekg(0, std::ios::end);
    buffer.resize(file.tellg());
    file.seekg(0);
    file.read(reinterpret_cast<char*>(buffer.data()), buffer.size());

    Reader reader(buffer);
    Header header = parse_header(reader);

    Image image {header.width, header.height};

    for (size_t y = 0; y < image.get_height(); y++) {
        unpack_rle(y, reader, image);
    }

    return image;
}
