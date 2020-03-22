#pragma once

#include <gst/gst.h>

#include <memory>
#include <vector>

#include <gstreamer/GStreamerElementIfc.hpp>

namespace gstreamer {

class GStreamerPipeline {
public:
    GStreamerPipeline();
    ~GStreamerPipeline();

    void create(const std::string& pipelineName);
    void build(const std::vector<std::unique_ptr<GStreamerElementIfc>>& elements);
    void play();
    GstElement* get();

private:
    std::unique_ptr<GstElement, void(*)(GstElement*)> pipeline;
};

} // gstreamer
