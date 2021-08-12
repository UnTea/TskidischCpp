#pragma once


#include <cmath>
#include <random>
#include <cstdint>


#include "image.hpp"
#include "primitives.hpp"
#include "raytracing.hpp"


const size_t WIDTH = 1024;
const size_t HEIGHT = 780;
const size_t SAMPLE_COUNT = 64;
const size_t FIELD_OF_VIEW = 120;

Image render(std::vector<std::unique_ptr<Primitive>>&, Image&);
void tile(std::vector<std::unique_ptr<Primitive>>&, Image& environment_map, Image& image, size_t line_x, size_t line_y);
float radians(float degree);