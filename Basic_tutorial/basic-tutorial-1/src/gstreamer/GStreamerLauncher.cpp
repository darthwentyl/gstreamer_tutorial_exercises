#include <gstreamer/GStreamerLauncher.hpp>

#include <exceptions/CannotCreatePipeline.hpp>
#include <exceptions/LogMsgCreator.hpp>
#include <exceptions/CannotGetBus.hpp>

#include <sstream>
#include <iostream>

namespace gstreamer {

using namespace exceptions;

namespace {

void gst_element_deleter(GstElement* element)
{
    gst_object_unref(element);
}

void gst_bus_deleter(GstBus* bus)
{
    gst_object_unref(bus);
}

void gst_msg_deleter(GstMessage* msg)
{
    gst_message_unref(msg);
}

} // anonymous

GStreamerLauncher::GStreamerLauncher(int argc, char *argv[])
: pipeline(nullptr, gst_element_deleter)
, bus(nullptr, gst_bus_deleter)
, msg(nullptr, gst_msg_deleter)
{
    gst_init(&argc, &argv);
}

void GStreamerLauncher::createPipeline(const std::string& url)
{
    std::ostringstream description;
    description << "playbin uri=" << url;
    pipeline.reset(gst_parse_launch(description.str().c_str(), nullptr));
    if (!pipeline) {
        throw CannotCreatePipeline(LogMsgCreator::createMsg(
                                                    std::string(__FILE__),
                                                    std::string(__FUNCTION__),
                                                    __LINE__,
                                                    std::string("Cannot create pipeline")));
    }
}

void GStreamerLauncher::play()
{
    gst_element_set_state(pipeline.get(), GST_STATE_PLAYING);
}

void GStreamerLauncher::waitForFinish()
{
    getBus();
    waitForMsg();
    setStateNull();
}

void GStreamerLauncher::getBus()
{
    bus.reset(gst_element_get_bus(pipeline.get()));
    if (!bus) {
        throw CannotGetBus(LogMsgCreator::createMsg(
                                                    std::string(__FILE__),
                                                    std::string(__FUNCTION__),
                                                    __LINE__,
                                                    std::string("Cannot create pipeline")));
    }
}

void GStreamerLauncher::waitForMsg()
{
    msg.reset(gst_bus_timed_pop_filtered(
            bus.get(), GST_CLOCK_TIME_NONE,
            (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS)));
}

void GStreamerLauncher::setStateNull()
{
    gst_element_set_state(pipeline.get(), GST_STATE_NULL);
}

} // gstreamer
