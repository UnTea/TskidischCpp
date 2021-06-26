#include <iostream>
#include "linmath.hpp"

float radians(float degree) {
    return PI * degree / float(180.0);
}

int main() {
    Vector vector1(8.25, 1, 1);

    vector1 = power(vector1, 2);

    std::cout << vector1 << std::endl;

    return 0;
}
