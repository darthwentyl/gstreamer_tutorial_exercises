#include <gstreamer/GStreamerSink.hpp>
#include <gstreamer/GStreamerDeleter.hpp>

#include <exceptions/LogMsgCreator.hpp>

namespace gstreamer {

using namespace exceptions;

GStreamerSink::GStreamerSink(const std::string& sinkName) :
        sink(nullptr, GStreamerDeleter::element)
{
    sink.reset(gst_element_factory_make(sinkName.c_str(), "sink"));
    if (!sink) {
        throw std::runtime_error(LogMsgCreator::createMsg(
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
