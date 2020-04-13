#include <gstreamer/GStreamerLauncher.hpp>

#include <sstream>
#include <iostream>

namespace gstreamer {

GStreamerLauncher::GStreamerLauncher(int argc, char *argv[])
{
    gst_init(&argc, &argv);
}

void GStreamerLauncher::addGstElement(std::unique_ptr<GStreamerElement> element)
{
    pipeline.addGstElement(std::move(element));
}

void GStreamerLauncher::create(const std::string& pipelineName)
{
    pipeline.create(pipelineName);
    pipeline.createBin();
    pipeline.linkElements();
}

void GStreamerLauncher::play(const std::string& url)
{
    pipeline.setUrl(url);
    pipeline.play();
}

void GStreamerLauncher::wait()
{
    bus.create(pipeline);
    message.wait(bus);
}

} // gstreamer
