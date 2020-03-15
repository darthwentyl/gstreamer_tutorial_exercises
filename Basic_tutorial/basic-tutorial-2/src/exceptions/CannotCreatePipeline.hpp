#pragma once

#include <stdexcept>
#include <string>

namespace exceptions {

class CannotCreatePipeline : public std::runtime_error {
public:
    CannotCreatePipeline(const std::string& msg) :
        std::runtime_error(msg)
    {}
};

} // exceptions
