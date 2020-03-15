#pragma once

#include <stdexcept>
#include <string>

namespace exceptions {

class CannotSetPlayState : public std::runtime_error {
public:
    CannotSetPlayState(const std::string& msg) :
        std::runtime_error(msg)
    {}
};

} // exceptions
