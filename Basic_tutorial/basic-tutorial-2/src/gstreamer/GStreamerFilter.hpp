#pragma once

#include <gst/gst.h>

#include <memory>

namespace gstreamer {

class GStreamerFilter {
public:
    GStreamerFilter();
    void create(const std::string& filterName);
    GstElement* get();

private:
    std::unique_ptr<GstElement, void(*)(GstElement*)> filter;
};

} // gstreamer
