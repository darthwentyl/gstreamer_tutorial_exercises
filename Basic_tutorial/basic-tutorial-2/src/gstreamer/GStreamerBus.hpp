#pragma once

#include <gst/gst.h>

#include <memory>

namespace gstreamer {

class GStreamerPipeline;

class GStreamerBus
{
public:
    GStreamerBus();

    void create(GStreamerPipeline& pipeline);

private:
    std::unique_ptr<GstBus, void(*)(GstBus*)> bus;
};

} // gstreamer
