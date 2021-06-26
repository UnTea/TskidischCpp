#include "linmath.hpp"


float radians(float degree) {
    return PI * degree / float(180.0);
}


int main() {
    Vector vector1(1.1, 2.2, 3.3);

    std::cout << vector1 << std::endl;

    return 0;
}
