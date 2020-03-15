#include <gstreamer/GStreamerDeleter.hpp>

namespace gstreamer {

void GStreamerDeleter::element(GstElement* element)
{
    gst_object_unref(element);
}

void GStreamerDeleter::bus(GstBus* bus)
{
    gst_object_unref(bus);
}

void GStreamerDeleter::msg(GstMessage* msg)
{
    gst_message_unref(msg);
}

} // gstreamer
