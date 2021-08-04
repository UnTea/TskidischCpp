#include "hdr.hpp"
#include "reader.hpp"


#include <string>
#include <cstdint>
#include <fstream>
#include <stdexcept>


struct Header {
    size_t width;
    size_t height;

    Header(size_t width, size_t height)
    : width(width)
    , height(height)
    {};
};

std::vector<std::string> split_string_by_delimiter(const std::string &string, const std::string& delimiter) {
    size_t start, end = 0;
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

    std::string string = reader.read_string_to_line_break();
    std::string delimiter = " ";
    std::vector<std::string> resolution = split_string_by_delimiter(string, delimiter);

    if (resolution.empty()) {
        throw std::runtime_error("An incorrect environment map resolution ");
    }

    size_t height = stoi(resolution[1]);
    size_t width = stoi(resolution[3]);

    return {width, height};
}

//TODO unpack_rle, read_u16, read_u8
void unpack_rle(size_t y, Reader& reader, Image& image) {
    std::vector<uint8_t> red(image.get_width())
                       , green(image.get_width())
                       , blue(image.get_width())
                       , exp(image.get_width());
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
