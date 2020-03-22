#include <gstreamer/GStreamerFilter.hpp>
#include <gstreamer/GStreamerDeleter.hpp>

#include <exceptions/LogMsgCreator.hpp>
#include <exceptions/CannotCreateFilter.hpp>

namespace gstreamer {

using namespace exceptions;

GStreamerFilter::GStreamerFilter() :
        filter(nullptr, GStreamerDeleter::element)
{}

void GStreamerFilter::create(const std::string& filterName)
{
    filter.reset(gst_element_factory_make(filterName.c_str(), "filter"));
    if (!filter) {
        throw CannotCreateFilter(LogMsgCreator::createMsg(
                                                    std::string(__FILE__),
                                                    std::string(__FUNCTION__),
                                                    __LINE__,
                                                    std::string("Cannot create filter")));
    }
}

GstElement* GStreamerFilter::get()
{
    return filter.get();
}

} // gstreamer
