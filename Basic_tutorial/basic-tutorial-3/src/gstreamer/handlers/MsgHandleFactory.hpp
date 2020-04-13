#pragma once

#include <gst/gst.h>
#include <memory>
#include <map>

namespace gstreamer { namespace handlers {

class MsgHandleIfc;

class MsgHandleFactory {
public:
     void create(std::map<GstMessageType, std::unique_ptr<MsgHandleIfc>>& handlerMap);
};

} } // gstreamer::handlers
