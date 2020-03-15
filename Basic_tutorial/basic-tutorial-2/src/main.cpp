#include <iostream>
#include <stdexcept>

#include <gstreamer/GStreamerLauncher.hpp>

using namespace gstreamer;

int main(int argc, char *argv[])
{
    GStreamerLauncher launcher(argc, argv);
    try {
        launcher.create("videotestsrc", "autovideosink", "test-pipeline");
        launcher.play();
        launcher.wait();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
