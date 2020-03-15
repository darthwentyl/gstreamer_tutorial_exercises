#include <gstreamer/handlers/MsgHandleError.hpp>
#include <gstreamer/GStreamerMessage.hpp>
#include <gstreamer/GStreamerDeleter.hpp>

#include <exceptions/LogMsgCreator.hpp>
#include <exceptions/MessageError.hpp>

#include <gst/gst.h>

#include <memory>
#include <sstream>

namespace gstreamer { namespace handlers {

using namespace exceptions;

void MsgHandleError::handle(GstMessage& msg)
{
    std::ostringstream ss;
    ss << "Error received from element " << GST_OBJECT_NAME(msg.src);
    throw MessageError(LogMsgCreator::createMsg(
                                            std::string(__FILE__),
                                            std::string(__FUNCTION__),
                                            __LINE__,
                                            ss.str()));
}

} } // gstreamer::handlers
