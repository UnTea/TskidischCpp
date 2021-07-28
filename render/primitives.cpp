#include "primitives.hpp"


float Plane::ray_intersect(Ray ray) {
    auto denominator = m_normal.dot(ray.direction);

    if (std::abs(denominator) > EPSILON) {
        float t = ((m_point - ray.origin).dot(m_normal)) / denominator;

        if (t >= EPSILON) {
            return t;
        }
    }

    return -1.0f;
}

Vector<float> Plane::normal(Vector<float>) {
    return m_normal;
}

Vector<float> Plane::albedo() {
    return m_albedo;
}

float Sphere::ray_intersect(Ray ray) {
    Vector<float> oc = ray.origin - m_center;
    float b = oc.dot(ray.direction);
    float c = oc.dot(oc) - m_radius * m_radius;
    float h = b * b - c;

    if (h < 0.0f) {
        return -1.0f; // no intersection
    }

    h = std::sqrt(h);

    if (-b - h > EPSILON) {
        return -b - h; // t is -b - h
    }

    if (-b + h > EPSILON) {
        return -b + h;
    }

    return -1.0f;
}

Vector<float> Sphere::albedo() {
    return m_albedo;
}

Vector<float> Sphere::normal(Vector<float> intersection) {
    return (intersection - m_center).normal();
}