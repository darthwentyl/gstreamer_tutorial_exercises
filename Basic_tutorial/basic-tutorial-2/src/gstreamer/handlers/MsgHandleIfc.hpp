#pragma once

#include <gst/gst.h>

namespace gstreamer { namespace handlers {

class MsgHandleIfc {
public:
    virtual ~MsgHandleIfc() = default;
    virtual void handle(GstMessage& msg) = 0;
};

} } // gstreamer::handlers
