#include "reader.hpp"


std::string Reader::read_string_to_line_break() {
    std::string string;

    while (index < data.size() && data[index] != '\n') {
        string += data[index];
        index++;
    }

    index++;

    return string;
}
