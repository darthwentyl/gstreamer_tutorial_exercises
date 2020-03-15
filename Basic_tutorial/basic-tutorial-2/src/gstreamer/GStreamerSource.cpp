#include <gstreamer/GStreamerSource.hpp>
#include <gstreamer/GStreamerDeleter.hpp>

#include <exceptions/LogMsgCreator.hpp>
#include <exceptions/CannotCreateSource.hpp>

namespace gstreamer {

using namespace exceptions;

GStreamerSource::GStreamerSource() :
        source(nullptr, GStreamerDeleter::element)
{}

void GStreamerSource::create(const std::string& sourceName)
{
    source.reset(gst_element_factory_make(sourceName.c_str(), "source"));
    if(!source)
    {
        throw CannotCreateSource(LogMsgCreator::createMsg(
                                                    std::string(__FILE__),
                                                    std::string(__FUNCTION__),
                                                    __LINE__,
                                                    std::string("Cannot create source")));
    }
}

void GStreamerSource::changeProperties()
{
    g_object_set(source.get(), "pattern", 0, NULL);
}

GstElement* GStreamerSource::get()
{
    return source.get();
}

} // gstreamer

