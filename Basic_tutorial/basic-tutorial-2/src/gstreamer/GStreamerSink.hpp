#pragma once

#include <gstreamer/GStreamerElementIfc.hpp>

#include <memory>

namespace gstreamer {

class GStreamerSink : public GStreamerElementIfc {
public:
    GStreamerSink(const std::string& sinkName);
    virtual ~GStreamerSink() = default;

    GstElement* get() override;

private:
    std::unique_ptr<GstElement, void(*)(GstElement*)> sink;
};

} // gstreamer
