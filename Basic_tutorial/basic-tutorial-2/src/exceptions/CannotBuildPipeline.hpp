#pragma once

#include <stdexcept>
#include <string>

namespace exceptions {

class CannotBuildPipeline : public std::runtime_error {
public:
    CannotBuildPipeline(const std::string& msg) :
        std::runtime_error(msg)
    {}
};

} // exceptions
