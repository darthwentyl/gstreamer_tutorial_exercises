#pragma once

#include <gst/gst.h>

#include <memory>

namespace gstreamer {

class GStreamerSource {
public:
    GStreamerSource();
    void create(const std::string& sourceName);
    void changeProperties();
    GstElement* get();

private:
    std::unique_ptr<GstElement, void(*)(GstElement*)> source;
};

} // gstreamer
