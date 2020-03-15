#pragma once

#include <stdexcept>
#include <string>

namespace exceptions {

class UnexpectedMessage : public std::runtime_error {
public:
    UnexpectedMessage(const std::string& msg) :
        std::runtime_error(msg)
    {}
};

} // exceptions
