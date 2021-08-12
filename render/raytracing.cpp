#include <cmath>
#include <optional>


#include "raytracing.hpp"
#include "primitives.hpp"


Vector<float> point_at(Ray& ray, float t) {
    return ray.origin + ray.direction * t;
}

std::optional<Intersection> find_intersection(
    const std::vector<std::unique_ptr<Primitive>>& primitives,
    Ray& ray)
{
    float min_t = std::numeric_limits<float>::max();
    size_t index = 0;

    for (size_t i = 0; i < primitives.size(); i++) {
        float t = primitives[i]->ray_intersect(ray);

        if (t == -1.0f) {
            continue;
        }

        if (t < min_t) {
            min_t = t;
            index = i;
        }

        return Intersection {.t = min_t, .primitive = *primitives[index]};
    }

    return std::nullopt;
}

Vector<float> trace_ray(
    std::vector<std::unique_ptr<Primitive>>& primitives
    , Ray& ray
    , Image& environment_map
    , std::mt19937& random)
{
    std::optional<Intersection> intersection = find_intersection(primitives, ray);

    if (!intersection) {
        float phi = std::atan2(ray.direction.z, ray.direction.x);
        float omega = std::sqrt(ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z);
        float theta = std::atan2(ray.direction.y, omega);

        return environment_map.get_pixel_by_spherical_coordinates(phi, theta);
    }

    auto origin = point_at(ray, intersection->t),
         direction = random_unit_vector_in_hemisphere(intersection->primitive.normal(point_at(ray, intersection->t)), random);

    ray = Ray(
        origin,
        direction
    );

    Vector<float> color = intersection->primitive.albedo() * trace_ray(primitives, ray, environment_map, random);

    return color;
}

Vector<float> random_unit_vector_in_hemisphere(Vector<float> normal, std::mt19937& random) {
    Vector<float> random_vector {};
    std::uniform_real_distribution<float> dis(0.0f, 1.0f); //FIXME possible error in future

    for(;;) {
        random_vector = Vector<float> {
            float(dis(random)),
            float(dis(random)),
            float(dis(random)),
        };

        random_vector = random_vector * 2.0f + Vector(-1.0f);

        if (random_vector.dot(random_vector) > 1.0f) {
            continue;
        }

        if (random_vector.dot(normal) >= 0.0f) {
            return random_vector.normal();
        }

        return -random_vector.normal();
    }
}