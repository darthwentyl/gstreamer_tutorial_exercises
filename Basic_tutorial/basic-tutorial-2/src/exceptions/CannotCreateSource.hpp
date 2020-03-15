#pragma once

#include <stdexcept>
#include <string>

namespace exceptions {

class CannotCreateSource : public std::runtime_error
{
public:
    CannotCreateSource(const std::string& msg) :
        std::runtime_error(msg)
    {}
};

} // exceptions
