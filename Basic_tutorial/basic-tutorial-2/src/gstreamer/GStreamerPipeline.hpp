#pragma once

#include <gst/gst.h>

#include <memory>

namespace gstreamer {

class GStreamerSource;
class GStreamerSink;
class GStreamerFilter;

class GStreamerPipeline {
public:
    GStreamerPipeline();
    ~GStreamerPipeline();

    void create(const std::string& pipelineName);
    void build(GStreamerSource& source, GStreamerSink& sink, GStreamerFilter& filter);
    void play();
    GstElement* get();

private:
    std::unique_ptr<GstElement, void(*)(GstElement*)> pipeline;
};

} // gstreamer
