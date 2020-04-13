#include <iostream>
#include <stdexcept>
#include <memory>

#include <gstreamer/GStreamerLauncher.hpp>
#include <gstreamer/GStreamerElement.hpp>

using namespace gstreamer;

int main(int argc, char *argv[])
{
    GStreamerLauncher launcher(argc, argv);
    try {
        launcher.addGstElement(std::make_unique<GStreamerElement>("uridecodebin", "source"));
        launcher.addGstElement(std::make_unique<GStreamerElement>("audioconvert", "convert"));
        launcher.addGstElement(std::make_unique<GStreamerElement>("audioresample", "resample"));
        launcher.addGstElement(std::make_unique<GStreamerElement>("autoaudiosink", "sink"));
        launcher.create("test-pipeline");
        launcher.play("https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm");
        launcher.wait();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
