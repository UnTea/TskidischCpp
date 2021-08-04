#include "hdr.hpp"
#include "image.hpp"
#include "lodepng.h"
#include "render.hpp"
#include "linmath.hpp"
#include "primitives.hpp"
#include "raytracing.hpp"


int main() {
    std::vector<std::unique_ptr<Sphere>> vector {};
    vector.push_back(std::make_unique<Sphere>(
    Vector<float> (0.0f, 0.0f, 1.0f),
    0.35f,
    Vector<float> (1.0f, 1.0f, 1.0f)
    ));

    //load_hdr("../comfy_cafe_16k.hdr");
    load_hdr("../wooden_lounge_1k.hdr");

    return 0;
}
