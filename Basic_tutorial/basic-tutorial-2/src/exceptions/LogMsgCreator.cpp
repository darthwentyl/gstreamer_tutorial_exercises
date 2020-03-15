#include <exceptions/LogMsgCreator.hpp>

#include <sstream>

namespace exceptions {

std::string LogMsgCreator::createMsg(const std::string& file,
                                     const std::string& func,
                                     const unsigned line,
                                     const std::string& msg)
{
    std::ostringstream logMsg;
    logMsg << file << ":" << func << ":" << line << " " << msg;
    return logMsg.str();
}

} // exceptions
