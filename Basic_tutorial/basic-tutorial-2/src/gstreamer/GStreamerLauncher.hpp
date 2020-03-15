#pragma once

#include <gst/gst.h>

#include <gstreamer/GStreamerSource.hpp>
#include <gstreamer/GStreamerSink.hpp>
#include <gstreamer/GStreamerPipeline.hpp>
#include <gstreamer/GStreamerBus.hpp>
#include <gstreamer/GStreamerMessage.hpp>

namespace gstreamer {

class GStreamerLauncher {
public:
    GStreamerLauncher(int argc, char *argv[]);
    ~GStreamerLauncher() = default;

    void create(const std::string& sourceName,
                const std::string& sinkName,
                const std::string& pipelineName);

    void play();

    void wait();
private:
    GStreamerSource source;
    GStreamerSink sink;
    GStreamerPipeline pipeline;
    GStreamerBus bus;
    GStreamerMessage message;
};

} // gstreamer
