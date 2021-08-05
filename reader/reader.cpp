#include "reader.hpp"


#include <stdexcept>


std::string Reader::read_string_to_line_break() {
    std::string string;

    while (index < data.size() && data[index] != '\n') {
        string += data[index];
        index++;
    }

    index++;

    return string;
}

std::uint8_t Reader::read_uint8_t() {
    if (index >= data.size()) {
        throw std::out_of_range("Out of reader range!");
    }

    std::uint8_t byte = data[index];
    index++;

    return byte;
}

std::uint16_t Reader::read_uint16_t() {
    std::uint16_t a = read_uint8_t();
    std::uint16_t b = read_uint8_t();

    return (a << 8) | b;
}
