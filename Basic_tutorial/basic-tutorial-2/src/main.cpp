#include <iostream>
#include <stdexcept>
#include <memory>

#include <gstreamer/GStreamerLauncher.hpp>

#include <gstreamer/GStreamerSource.hpp>
#include <gstreamer/GStreamerSink.hpp>
#include <gstreamer/GStreamerFilter.hpp>

using namespace gstreamer;

int main(int argc, char *argv[])
{
    GStreamerLauncher launcher(argc, argv);
    try {
        launcher.addGstElement(std::make_unique<GStreamerSource>("videotestsrc"));
        launcher.addGstElement(std::make_unique<GStreamerFilter>("vertigotv"));
        launcher.addGstElement(std::make_unique<GStreamerSink>("autovideosink"));
        launcher.create("test-pipeline");
        launcher.play();
        launcher.wait();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
