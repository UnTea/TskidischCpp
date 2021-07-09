#pragma once


#include <vector>
#include <fstream>
#include <filesystem>


#include "lodepng.h"
#include "linmath.hpp"


class Image {
public:
    Image(unsigned width, unsigned height)
    : width(width)
    , height(height)
    , pixels(width * height)
    {}

    void set_pixel(unsigned, unsigned, Vector<float>);
    Vector<float>& get_pixel(unsigned, unsigned);
    Vector<float>& get_pixel_uv(float, float);
    Vector<float>& get_pixel_by_spherical_coordinates(float, float);
    void save(const std::filesystem::path&);

    ~Image() = default;

private:
    unsigned width;
    unsigned height;
    std::vector<Vector<float>> pixels;
};

void Image::set_pixel(unsigned x, unsigned y, Vector<float> color) {
    pixels[x + y * width] = color;
}

Vector<float>& Image::get_pixel(unsigned x, unsigned y) {
    return pixels[x + y * width];
}

Vector<float>& Image::get_pixel_uv(float u, float v) {
    size_t x = int(float(width) * (1.0f - u));
    size_t y = int(float(height) * (1.0f - v));

    return get_pixel(x, y);
}

Vector<float>& Image::get_pixel_by_spherical_coordinates(float phi, float theta) {
    float u = (phi + PI) / (2 * PI);
    float v = (theta + PI / 2) / PI;

    return get_pixel_uv(u, v);
}

void Image::save(const std::filesystem::path& path) {
    auto buffer = std::vector<uint8_t>(3 * width * height, 0);

    for (size_t y = 0; y < height; y++) {
        for (size_t x = 0; x < width; x++) {
            auto vector = clamp(power(get_pixel(x, y), 1.0f / 2.2f), 0.0f, 1.0f);

            buffer[3 * (x + y * width) + 0] = uint8_t(vector.x * 255.0f);
            buffer[3 * (x + y * width) + 1] = uint8_t(vector.y * 255.0f);
            buffer[3 * (x + y * width) + 2] = uint8_t(vector.z * 255.0f);
        }
    }

    unsigned error = lodepng::encode(path.string(), buffer, width, height, LCT_RGB);

    if (error) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}

Vector<float> aces_film(Vector<float> color) {
    float a = 2.51f;
    Vector b = Vector(0.03f, 0.03f, 0.03f);
    float c = 2.43f;
    Vector d = Vector(0.59f, 0.59f, 0.59f);
    Vector e = Vector(0.14f, 0.14f, 0.14f);
    Vector nominator = color * (color * a + b);
    Vector denominator = color * (color * c + d) + e;

    return nominator / denominator;
}
