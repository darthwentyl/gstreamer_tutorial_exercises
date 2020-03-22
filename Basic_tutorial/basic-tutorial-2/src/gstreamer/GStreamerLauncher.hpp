#pragma once

#include <gst/gst.h>

#include <memory>
#include <vector>

#include <gstreamer/GStreamerElementIfc.hpp>
#include <gstreamer/GStreamerPipeline.hpp>
#include <gstreamer/GStreamerBus.hpp>
#include <gstreamer/GStreamerMessage.hpp>

namespace gstreamer {

class GStreamerLauncher {
public:
    GStreamerLauncher(int argc, char *argv[]);
    ~GStreamerLauncher() = default;

    void addGstElement(std::unique_ptr<GStreamerElementIfc> element);

    void create(const std::string& pipelineName);

    void play();

    void wait();
private:
    std::vector<std::unique_ptr<GStreamerElementIfc>> pipelineElements;
    GStreamerPipeline pipeline;
    GStreamerBus bus;
    GStreamerMessage message;
};

} // gstreamer
