#include <gstreamer/GStreamerSource.hpp>
#include <gstreamer/GStreamerDeleter.hpp>

#include <exceptions/LogMsgCreator.hpp>

namespace gstreamer {

using namespace exceptions;

GStreamerSource::GStreamerSource(const std::string& sourceName) :
        source(nullptr, GStreamerDeleter::element)
{
    source.reset(gst_element_factory_make(sourceName.c_str(), "source"));
    if (!source) {
        throw std::runtime_error(LogMsgCreator::createMsg(
                                                std::string(__FILE__),
                                                std::string(__FUNCTION__),
                                                __LINE__,
                                                std::string("Cannot create source")));
    }
    g_object_set(source.get(), "pattern", 0, NULL);
}

void GStreamerSource::changeProperties()
{

}

GstElement* GStreamerSource::get()
{
    return source.get();
}

} // gstreamer

