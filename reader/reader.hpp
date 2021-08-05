#pragma once


#include <vector>
#include <cstdint>


#include "hdr.hpp"


struct Reader {
    std::vector<std::uint8_t>& data;
    size_t index;

    explicit Reader(std::vector<std::uint8_t>& file)
    : data(file)
    , index()
    {}

    std::uint8_t read_uint8_t();
    std::uint16_t read_uint16_t();
    std::string read_string_to_line_break();
};
