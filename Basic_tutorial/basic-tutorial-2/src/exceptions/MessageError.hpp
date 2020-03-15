#pragma once

#include <stdexcept>
#include <string>

namespace exceptions {

class MessageError : public std::runtime_error {
public:
    MessageError(const std::string& msg) :
        std::runtime_error(msg)
    {}
};

} // exceptions
