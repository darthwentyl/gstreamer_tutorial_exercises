#pragma once

#include <string>
#include <gst/gst.h>

namespace gstreamer {

class GStreamerElementIfc {
public:
    virtual ~GStreamerElementIfc() = default;
    virtual GstElement* get() = 0;
};

} // gstreamer
