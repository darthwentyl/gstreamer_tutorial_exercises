#include <gstreamer/GStreamerElement.hpp>
#include <gstreamer/GStreamerDeleter.hpp>

#include <exceptions/LogMsgCreator.hpp>

namespace gstreamer {

using namespace exceptions;

GStreamerElement::GStreamerElement(const std::string& factoryName, const std::string& name) :
        elem(nullptr, GStreamerDeleter::element)
{
    elem.reset(gst_element_factory_make(factoryName.c_str(), name.c_str()));
    if (!elem) {
        throw std::runtime_error(LogMsgCreator::createMsg(
                                                std::string(__FILE__),
                                                std::string(__FUNCTION__),
                                                __LINE__,
                                                std::string("Cannot create source")));
    }
}

GstElement* GStreamerElement::getGstElem()
{
    return elem.get();
}

std::string GStreamerElement::getName()
{
    return std::string(GST_OBJECT(elem.get())->name);
}

} // gstreamer
