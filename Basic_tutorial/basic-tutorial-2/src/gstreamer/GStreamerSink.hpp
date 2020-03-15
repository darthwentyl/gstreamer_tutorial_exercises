#pragma once

#include <gst/gst.h>

#include <memory>

namespace gstreamer {

class GStreamerSink {
public:
    GStreamerSink();
    void create(const std::string& sourceName);
    GstElement* get();

private:
    std::unique_ptr<GstElement, void(*)(GstElement*)> sink;
};

} // gstreamer
