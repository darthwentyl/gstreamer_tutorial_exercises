#pragma once

#include <stdexcept>
#include <string>

namespace exceptions {

class CannotCreateMessage : public std::runtime_error {
public:
    CannotCreateMessage(const std::string& msg) :
        std::runtime_error(msg)
    {}
};

} // exceptions
