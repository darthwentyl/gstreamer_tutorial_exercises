#include <gstreamer/GStreamerDeleter.hpp>

#include <iostream>

namespace gstreamer {

void GStreamerDeleter::pipeline(GstElement* pipeline)
{
    gst_object_unref(pipeline);
}

void GStreamerDeleter::element(GstElement* element)
{
    std::cout << __FUNCTION__ << ":" << __LINE__
              << " [INFO] pipeline manage memory of object "
              << GST_OBJECT(element)->name << std::endl;
//    gst_object_unref(element);
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
