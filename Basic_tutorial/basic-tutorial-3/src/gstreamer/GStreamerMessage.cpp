#include <gstreamer/GStreamerMessage.hpp>
#include <gstreamer/GStreamerDeleter.hpp>
#include <gstreamer/GStreamerBus.hpp>

#include <gstreamer/handlers/MsgHandleFactory.hpp>

#include <exceptions/LogMsgCreator.hpp>

namespace gstreamer {

using namespace exceptions;
using namespace handlers;

GStreamerMessage::GStreamerMessage() :
        msg(nullptr, GStreamerDeleter::msg)
{
    MsgHandleFactory factory;
    factory.create(handlerMap);
}

void GStreamerMessage::wait(GStreamerBus& bus)
{
    msg.reset(gst_bus_timed_pop_filtered(bus.get(), GST_CLOCK_TIME_NONE,
                         (GstMessageType)(GST_MESSAGE_ERROR|GST_MESSAGE_EOS)));
    if (!msg) {
        throw std::runtime_error(LogMsgCreator::createMsg(
                                                std::string(__FILE__),
                                                std::string(__FUNCTION__),
                                                __LINE__,
                                                std::string("Cannot create pipeline")));
    }

    auto iter = handlerMap.find(GST_MESSAGE_TYPE(msg.get()));
    if (iter != handlerMap.end()) {
        iter->second->handle(*msg.get());
    } else {
        throw std::runtime_error(LogMsgCreator::createMsg(
                                                std::string(__FILE__),
                                                std::string(__FUNCTION__),
                                                __LINE__,
                                                std::string("Unexpected message received")));
    }
}

} // gstreamer
