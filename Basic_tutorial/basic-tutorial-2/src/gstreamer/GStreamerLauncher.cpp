#include <gstreamer/GStreamerLauncher.hpp>

#include <exceptions/CriticalError.hpp>

#include <sstream>
#include <iostream>

namespace gstreamer {

using namespace exceptions;


GStreamerLauncher::GStreamerLauncher(int argc, char *argv[])
{
    gst_init(&argc, &argv);
}

void GStreamerLauncher::create(const std::string& sourceName,
                               const std::string& sinkName,
                               const std::string& pipelineName)
{
    source.create(sourceName);
    sink.create(sinkName);
    filter.create("vertigotv");
    pipeline.create(pipelineName);
    pipeline.build(source, sink, filter);
    source.changeProperties();
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
