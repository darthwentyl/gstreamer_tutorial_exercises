#include <gstreamer/handlers/MsgHandleEos.hpp>
#include <gstreamer/GStreamerMessage.hpp>

#include <gst/gst.h>

#include <iostream>

namespace gstreamer { namespace handlers {

void MsgHandleEos::handle(GstMessage& msg)
{
    std::cout << "End of stream reached" << std::endl;
}

} } // gstreamer::handlers
