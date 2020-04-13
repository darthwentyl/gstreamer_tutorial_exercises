#pragma once

#include <gst/gst.h>

#include <memory>

namespace gstreamer {

class GStreamerDynamicPipeline;

class GStreamerBus {
public:
    GStreamerBus();

    void create(GStreamerDynamicPipeline& pipeline);
    GstBus* get();

private:
    std::unique_ptr<GstBus, void(*)(GstBus*)> bus;
};

} // gstreamer
