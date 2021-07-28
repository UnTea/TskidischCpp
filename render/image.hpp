#pragma once


#include <vector>
#include <fstream>
#include <filesystem>

#include "lodepng.h"
#include "linmath.hpp"


class Image {
public:
    Image(unsigned width, unsigned height)
    : m_width(width)
    , m_height(height)
    , m_pixels(width * height)
    {}

    void save(const std::filesystem::path&);
    void set_pixel(unsigned, unsigned, Vector<float>);

    Vector<float>& get_pixel(unsigned, unsigned);
    Vector<float>& get_pixel_uv(float, float);
    Vector<float>& get_pixel_by_spherical_coordinates(float, float);

private:
    unsigned m_width;
    unsigned m_height;
    std::vector<Vector<float>> m_pixels;
};

Vector<float> aces_film(Vector<float>);
