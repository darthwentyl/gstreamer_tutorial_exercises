#pragma once

#include <stdexcept>
#include <string>

namespace exceptions {

class CannotGetBus : public std::runtime_error
{
public:
    CannotGetBus(const std::string& msg) :
        std::runtime_error(msg)
    {}
};

} // exceptions
