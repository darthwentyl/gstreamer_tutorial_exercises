#pragma once

#include <stdexcept>
#include <string>

namespace exceptions {

class CannotCreateFilter : public std::runtime_error {
public:
    CannotCreateFilter(const std::string& msg) :
        std::runtime_error(msg)
    {}
};

} // exceptions

