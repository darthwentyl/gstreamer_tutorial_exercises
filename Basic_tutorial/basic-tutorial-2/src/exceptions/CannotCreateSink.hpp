#pragma once

#include <stdexcept>
#include <string>

namespace exceptions {

class CannotCreateSink : public std::runtime_error
{
public:
    CannotCreateSink(const std::string& msg) :
        std::runtime_error(msg)
    {}
};

} // exceptions
