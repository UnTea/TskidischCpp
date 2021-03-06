#include "hdr.hpp"
#include "image.hpp"
#include "lodepng.h"
#include "render.hpp"
#include "linmath.hpp"
#include "primitives.hpp"
#include "raytracing.hpp"

#include <chrono>


int main() {
    std::vector<std::unique_ptr<Primitive>> primitives {};
    primitives.push_back(std::make_unique<Sphere>(
    Vector<float> (0.0f, 0.0f, 1.0f),
    0.35f,
    Vector<float> (1.0f, 1.0f, 1.0f)
    ));

    auto start = std::chrono::high_resolution_clock::now();

    try {
        Image environment_map = load_hdr("../comfy_cafe_16k.hdr");
        //Image environment_map = load_hdr("../wooden_lounge_1k.hdr");
        Image output = render(primitives, environment_map);
        //environment_map.save("../test_normal.png");
        output.save("../test.png");
    } catch (std::bad_alloc &error) {
        std::cout << error.what() << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> total = end - start;
    std::cout << total << '\n';

    return 0;
}
