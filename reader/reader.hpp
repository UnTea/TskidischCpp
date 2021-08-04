#pragma once


#include <string>
#include <vector>
#include <cstdint>


#include "hdr.hpp"


struct Reader {
    std::vector<uint8_t>& data;
    size_t index;

    explicit Reader(std::vector<uint8_t>& file)
    : data(file)
    , index()
    {}

    std::string read_string_to_line_break();
};
