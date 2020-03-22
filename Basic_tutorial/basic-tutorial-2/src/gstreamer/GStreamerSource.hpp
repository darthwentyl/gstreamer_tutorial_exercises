#pragma once

#include <gstreamer/GStreamerElementIfc.hpp>

#include <memory>

namespace gstreamer {

class GStreamerSource : public GStreamerElementIfc {
public:
    GStreamerSource(const std::string& sourceName);
    virtual ~GStreamerSource() = default;

    GstElement* get() override;

    void changeProperties();
private:
    std::unique_ptr<GstElement, void(*)(GstElement*)> source;
};

} // gstreamer
