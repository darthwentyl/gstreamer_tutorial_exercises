#pragma once

#include <gst/gst.h>

namespace gstreamer {

class GStreamerPadAdd {
public:
    static void padAdd(GstElement* src, GstPad* new_pad, GstElement* convert);
};

} // gstreamer
