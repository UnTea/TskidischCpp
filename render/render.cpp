#include "render.hpp"


float radians(float degree) {
    return PI * degree / 180.0f;
}


Image render(std::vector<std::unique_ptr<Primitive>>& primitives, Image& environment_map) {
    Image image(WIDTH, HEIGHT);

    for (size_t y = 0; y < image.get_height() / 100 + 1; y++) {
        for (size_t x = 0; x < image.get_width() / 100 + 1; x++) {
            tile(primitives, environment_map, image, x, y);
        }
    }

    return image;
}

void tile(
    std::vector<std::unique_ptr<Primitive>>& primitives,
    Image& environment_map,
    Image& image,
    size_t tile_x,
    size_t tile_y)
{
    float aspect_ratio = float(image.get_width()) / float(image.get_height());
    std::random_device random_device;
    std::mt19937 random(random_device());
    std::uniform_real_distribution<float> dis (0.0f, 1.0f);

    for (size_t relative_x = 0; relative_x < 100; relative_x++) {
        for (size_t relative_y = 0; relative_y < 100; relative_y++) {
            size_t x = tile_x * 100 + relative_x;
            size_t y = tile_y * 100 + relative_y;

            if (x >= image.get_width() || y >= image.get_height()) {
                continue;
            }

            Vector<float> sum {};

            for (size_t i = 0; i < SAMPLE_COUNT; i++) {
                float u = 2.0f * (float(x) + dis(random)) / float(image.get_width()) - 1.0f;
                float v = -(2.0f * (float(y) + dis(random)) / float(image.get_height()) - 1.0f);

                float film_u = u * std::tan(radians(FIELD_OF_VIEW) / 2) * aspect_ratio;
                float film_v = v * std::tan(radians(FIELD_OF_VIEW) / 2);

                Vector<float> direction = Vector(film_u, film_v, 1.0f).normal();
                Ray ray = Ray(Vector<float> {}, direction);

                Vector<float> color = trace_ray(primitives, ray, environment_map, random);
                sum += color;
            }

            image.set_pixel(x, y, sum / SAMPLE_COUNT);
        }
    }
}
