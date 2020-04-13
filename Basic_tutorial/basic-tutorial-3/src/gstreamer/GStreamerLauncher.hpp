#pragma once

#include <gst/gst.h>

#include <memory>
#include <vector>

#include <gstreamer/GStreamerElement.hpp>
#include <gstreamer/GStreamerBus.hpp>
#include <gstreamer/GStreamerMessage.hpp>
#include <gstreamer/GStreamerDynamicPipeline.hpp>

namespace gstreamer {

class GStreamerLauncher {
public:
    GStreamerLauncher(int argc, char *argv[]);
    ~GStreamerLauncher() = default;

    void addGstElement(std::unique_ptr<GStreamerElement> element);

    void create(const std::string& pipelineName);

    void play(const std::string& url);

    void wait();
private:
    GStreamerDynamicPipeline pipeline;
    GStreamerBus bus;
    GStreamerMessage message;
};

} // gstreamer
