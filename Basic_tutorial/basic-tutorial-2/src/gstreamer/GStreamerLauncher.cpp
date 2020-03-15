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
    try {
        source.create(sourceName);
        sink.create(sinkName);
        pipeline.create(pipelineName);
        pipeline.build(source, sink);
        source.changeProperties();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw CriticalError();
    }
}

void GStreamerLauncher::play()
{
    try {
        pipeline.play();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw CriticalError();
    }
}

void GStreamerLauncher::wait()
{
    try {
        bus.create(pipeline);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw CriticalError();
    }
}

} // gstreamer
