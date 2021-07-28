#pragma once


#include <cmath>


#include "linmath.hpp"
#include "raytracing.hpp"


class Primitive {
public:
    virtual float ray_intersect(Ray) = 0;
    virtual Vector<float> albedo() = 0;
    virtual Vector<float> normal(Vector<float>) = 0;
};

class Sphere : public Primitive {
public:
    Sphere(Vector<float> center, float radius, Vector<float> albedo)
    : m_center(center)
    , m_radius(radius)
    , m_albedo(albedo)
    {}

    float ray_intersect(Ray ray) override;
    Vector<float> albedo() override;
    Vector<float> normal(Vector<float> intersection) override;

private:
    Vector<float> m_center;
    float m_radius;
    Vector<float> m_albedo;
};

class Plane : public Primitive {
public:
    Plane(Vector<float> point, Vector<float> normal, Vector<float> albedo)
    : m_point(point)
    , m_normal(normal)
    , m_albedo(albedo)
    {}

    float ray_intersect(Ray ray) override;
    Vector<float> albedo() override;
    Vector<float> normal(Vector<float> intersection) override;

private:
    Vector<float> m_point;
    Vector<float> m_normal;
    Vector<float> m_albedo;
};
