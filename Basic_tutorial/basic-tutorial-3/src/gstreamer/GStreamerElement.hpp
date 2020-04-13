#pragma once

#include <gst/gst.h>

#include <string>
#include <memory>

namespace gstreamer {

class GStreamerElement
{
public:
    GStreamerElement(const std::string& factoryName, const std::string& name);

    GstElement* getGstElem();
    std::string getName();

private:
    std::unique_ptr<GstElement, void(*)(GstElement*)> elem;

};

} // gstreamer
