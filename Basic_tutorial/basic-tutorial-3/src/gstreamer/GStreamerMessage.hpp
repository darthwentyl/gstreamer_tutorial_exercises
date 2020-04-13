#pragma once

#include <gst/gst.h>

#include <memory>
#include <map>

#include <gstreamer/handlers/MsgHandleIfc.hpp>

namespace gstreamer {

class GStreamerBus;

class GStreamerMessage {
public:
    GStreamerMessage();

    void wait(GStreamerBus& bus);

private:
    std::unique_ptr<GstMessage, void(*)(GstMessage*)> msg;
    std::map<GstMessageType, std::unique_ptr<handlers::MsgHandleIfc>> handlerMap;
};

} // gstreamer
