#pragma once

#include <gst/gst.h>

#include <memory>
#include <vector>

#include <gstreamer/GStreamerElement.hpp>

namespace gstreamer {

class GStreamerDynamicPipeline {
public:
    GStreamerDynamicPipeline();
    ~GStreamerDynamicPipeline();

    void create(const std::string& pipelineName);
    void addGstElement(std::unique_ptr<GStreamerElement> element);
    void createBin();
    void linkElements();
    void setUrl(const std::string& url);
    void registerHandler();
    void play();
    GstElement* get();

private:
    std::unique_ptr<GstElement, void(*)(GstElement*)> pipeline;
    std::vector<std::unique_ptr<GStreamerElement>> elements;
};

} // gstreamer
