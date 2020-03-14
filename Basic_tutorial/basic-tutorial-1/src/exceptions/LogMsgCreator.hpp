#pragma once

#include <string>

namespace exceptions {

class LogMsgCreator
{
public:
    static std::string createMsg(const std::string& file,
                                 const std::string& func,
                                 const unsigned line,
                                 const std::string& msg);
};

} // exceptions
