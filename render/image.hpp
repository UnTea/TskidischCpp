#pragma once


#include <cstdio>
#include <vector>
#include <cstdint>
#include <fstream>
#include <filesystem>

#include "lodepng.h"
#include "linmath.hpp"


class Image {
public:
    Image(size_t width, size_t height)
    : m_width(width)
    , m_height(height)
    , m_pixels(width * height)
    {}

    void save(const std::filesystem::path&);
    void set_pixel(size_t, size_t, Vector<float>);

    [[nodiscard]] size_t get_width() const;
    [[nodiscard]] size_t get_height() const;

    Vector<float>& get_pixel(size_t, size_t);
    Vector<float>& get_pixel_uv(float, float);
    Vector<float>& get_pixel_by_spherical_coordinates(float, float);

private:
    size_t m_width;
    size_t m_height;
    std::vector<Vector<float>> m_pixels;
};

Vector<float> aces_film(Vector<float> color);
