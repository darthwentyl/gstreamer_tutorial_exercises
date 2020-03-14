#pragma once

#include <gst/gst.h>

#include <string>
#include <memory>

namespace gstreamer {

class GStreamerLauncher {
public:
    GStreamerLauncher(int argc, char *argv[]);
    ~GStreamerLauncher() = default;

    void createPipeline(const std::string& url);
    void play();
    void waitForFinish();

private:
    void getBus();
    void waitForMsg();
    void setStateNull();

    std::unique_ptr<GstElement, void(*)(GstElement*)> pipeline;
    std::unique_ptr<GstBus, void(*)(GstBus*)> bus;
    std::unique_ptr<GstMessage, void(*)(GstMessage*)> msg;
};

} // gstreamer
