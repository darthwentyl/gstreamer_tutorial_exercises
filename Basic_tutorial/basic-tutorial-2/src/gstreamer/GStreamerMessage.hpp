#pragma once

#include <gst/gst.h>

#include <memory>

namespace gstreamer {

class GStreamerMessage
{
public:
    GStreamerMessage();

private:
    std::unique_ptr<GstMessage, void(*)(GstMessage*)> msg;

};

} // gstreamer
