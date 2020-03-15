#include <gstreamer/GStreamerSink.hpp>
#include <gstreamer/GStreamerDeleter.hpp>

#include <exceptions/LogMsgCreator.hpp>
#include <exceptions/CannotCreateSink.hpp>

namespace gstreamer {

using namespace exceptions;

GStreamerSink::GStreamerSink() :
        sink(nullptr, GStreamerDeleter::element)
{}

void GStreamerSink::create(const std::string& sinkName)
{
    sink.reset(gst_element_factory_make(sinkName.c_str(), "sink"));
    if(!sink)
    {
        throw CannotCreateSink(LogMsgCreator::createMsg(
                                                    std::string(__FILE__),
                                                    std::string(__FUNCTION__),
                                                    __LINE__,
                                                    std::string("Cannot create sink")));
    }
}

GstElement* GStreamerSink::get()
{
    return sink.get();
}

} // gstreamer
