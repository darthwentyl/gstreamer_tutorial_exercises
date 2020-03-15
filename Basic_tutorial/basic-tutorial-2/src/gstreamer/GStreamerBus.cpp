#include <gstreamer/GStreamerBus.hpp>
#include <gstreamer/GStreamerDeleter.hpp>
#include <gstreamer/GStreamerPipeline.hpp>

#include <exceptions/LogMsgCreator.hpp>
#include <exceptions/CannotGetBus.hpp>

namespace gstreamer {

using namespace exceptions;

GStreamerBus::GStreamerBus() :
        bus(nullptr, GStreamerDeleter::bus)
{}

void GStreamerBus::create(GStreamerPipeline& pipeline)
{
    bus.reset(gst_element_get_bus(pipeline.get()));
    if (!bus) {
        throw CannotGetBus(LogMsgCreator::createMsg(
                                            std::string(__FILE__),
                                            std::string(__FUNCTION__),
                                            __LINE__,
                                            std::string("Cannot get bus")));
    }
}

} // gstreamer
