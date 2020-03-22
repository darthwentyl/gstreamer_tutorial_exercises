#pragma once

#include <gstreamer/GStreamerElementIfc.hpp>

#include <memory>

namespace gstreamer {

class GStreamerFilter : public GStreamerElementIfc {
public:
    GStreamerFilter(const std::string& filterName);

    virtual ~GStreamerFilter() = default;
    GstElement* get() override;

private:
    std::unique_ptr<GstElement, void(*)(GstElement*)> filter;
};

} // gstreamer
