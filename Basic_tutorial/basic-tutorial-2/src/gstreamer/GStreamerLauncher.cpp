#include <gstreamer/GStreamerLauncher.hpp>

#include <sstream>
#include <iostream>

namespace gstreamer {

GStreamerLauncher::GStreamerLauncher(int argc, char *argv[])
{
    gst_init(&argc, &argv);
}

void GStreamerLauncher::addGstElement(std::unique_ptr<GStreamerElementIfc> element) {
    pipelineElements.emplace_back(std::move(element));
}

void GStreamerLauncher::create(const std::string& pipelineName)
{
    pipeline.create(pipelineName);
    pipeline.build(pipelineElements);
}

void GStreamerLauncher::play()
{
    pipeline.play();
}

void GStreamerLauncher::wait()
{
    bus.create(pipeline);
    message.wait(bus);
}

} // gstreamer
