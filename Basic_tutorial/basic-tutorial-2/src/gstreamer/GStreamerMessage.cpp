#include <gstreamer/GStreamerMessage.hpp>
#include <gstreamer/GStreamerDeleter.hpp>

namespace gstreamer {

GStreamerMessage::GStreamerMessage() :
        msg(nullptr, GStreamerDeleter::msg)
{}

} // gstreamer
