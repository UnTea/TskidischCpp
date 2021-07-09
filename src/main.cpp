#include "lodepng.h"
#include "image.hpp"
#include "linmath.hpp"


float radians(float degree) {
    return PI * degree / float(180.0);
}

Vector<float> red {255.0, 0.0, 0.0};

int main() {
    Image image(40, 40);
    image.set_pixel(5,5, red);

    image.save("../test.png");

    return 0;
}
