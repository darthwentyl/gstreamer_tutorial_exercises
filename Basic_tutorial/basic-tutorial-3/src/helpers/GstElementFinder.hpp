#pragma once

#include <gst/gst.h>

#include <gstreamer/GStreamerElement.hpp>

#include <string>
#include <vector>

namespace helpers {

class GstElementFinder {
public:
    static gstreamer::GStreamerElement* find(const std::string& name,
            const std::vector<std::unique_ptr<gstreamer::GStreamerElement>>& elements);
};

} // helpers
