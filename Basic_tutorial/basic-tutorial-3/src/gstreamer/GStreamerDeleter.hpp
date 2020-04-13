#pragma once

#include <gst/gst.h>

namespace gstreamer {

class GStreamerDeleter {
public:
    static void pipeline(GstElement* pipeline);
    static void element(GstElement* element);
    static void bus(GstBus* bus);
    static void msg(GstMessage* msg);
};

} // gstreamer
