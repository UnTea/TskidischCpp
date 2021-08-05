#include "image.hpp"


#include <cstdint>


void Image::set_pixel(size_t x, size_t y, Vector<float> color) {
    m_pixels[x + y * m_width] = color;
}

Vector<float>& Image::get_pixel(size_t x, size_t y) {
    return m_pixels[x + y * m_width];
}

Vector<float>& Image::get_pixel_uv(float u, float v) {
    size_t x = int(float(m_width) * (1.0f - u));
    size_t y = int(float(m_height) * (1.0f - v));

    return get_pixel(x, y);
}

Vector<float>& Image::get_pixel_by_spherical_coordinates(float phi, float theta) {
    float u = (phi + PI) / (2 * PI);
    float v = (theta + PI / 2) / PI;

    return get_pixel_uv(u, v);
}

void Image::save(const std::filesystem::path& path) {
    auto buffer = std::vector<uint8_t>(3 * m_width * m_height, 0);

    for (size_t y = 0; y < m_height; y++) {
        for (size_t x = 0; x < m_width; x++) {
            auto vector = clamp(power(get_pixel(x, y), 1.0f / 2.2f), 0.0f, 1.0f);

            buffer[3 * (x + y * m_width) + 0] = uint8_t(vector.x * 255.0f);
            buffer[3 * (x + y * m_width) + 1] = uint8_t(vector.y * 255.0f);
            buffer[3 * (x + y * m_width) + 2] = uint8_t(vector.z * 255.0f);
        }
    }

    size_t error = lodepng::encode(path.string(), buffer, m_width, m_height, LCT_RGB);

    if (error) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}

size_t Image::get_width() const {
    return m_width;
}

size_t Image::get_height() const {
    return m_height;
}

Vector<float> aces_film(Vector<float> color) {
    float a = 2.51f;
    Vector<float> b = Vector(0.03f, 0.03f, 0.03f);
    float c = 2.43f;
    Vector<float> d = Vector(0.59f, 0.59f, 0.59f);
    Vector<float> e = Vector(0.14f, 0.14f, 0.14f);
    Vector<float> nominator = color * (color * a + b);
    Vector<float> denominator = color * (color * c + d) + e;

    return nominator / denominator;
}
