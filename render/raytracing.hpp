#pragma once


#include <memory>
#include <random>
#include <limits>


#include "image.hpp"
#include "linmath.hpp"


class Primitive;

struct Intersection {
    float t;
    Primitive& primitive;
};

class Ray {
public:
    Ray(Vector<float> _origin, Vector<float> _direction)
    : origin(_origin)
    , direction(_direction)
    { }

    Vector<float> origin;
    Vector<float> direction;
};

Vector<float> random_unit_vector_in_hemisphere(Vector<float> normal, std::mt19937&);
Vector<float> trace_ray(std::vector<std::unique_ptr<Primitive>>&, Ray&, Image&, std::mt19937&);
