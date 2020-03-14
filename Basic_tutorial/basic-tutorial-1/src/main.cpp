#include <iostream>

#include <gstreamer/GStreamerLauncher.hpp>

using namespace gstreamer;

int main(int argc, char *argv[])
{
    GStreamerLauncher launcher(argc, argv);
    const std::string url = "https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm";
    try {
        launcher.createPipeline(url);
        launcher.play();
        launcher.waitForFinish();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
