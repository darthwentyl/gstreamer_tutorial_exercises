#include <gstreamer/GStreamerDeleter.hpp>
#include <gstreamer/GStreamerElement.hpp>
#include <gstreamer/GStreamerDynamicPipeline.hpp>
#include <gstreamer/GStreamerPadAdd.hpp>

#include <helpers/GstElementFinder.hpp>

#include <exceptions/LogMsgCreator.hpp>

#include <iostream>

namespace gstreamer {

using namespace exceptions;
using namespace helpers;

GStreamerDynamicPipeline::GStreamerDynamicPipeline() :
        pipeline(nullptr, GStreamerDeleter::pipeline)
{}

GStreamerDynamicPipeline::~GStreamerDynamicPipeline()
{
    gst_element_set_state(pipeline.get(), GST_STATE_NULL);
}

void GStreamerDynamicPipeline::addGstElement(std::unique_ptr<GStreamerElement> element)
{
    elements.emplace_back(std::move(element));
}

void GStreamerDynamicPipeline::create(const std::string& pipelineName)
{
    pipeline.reset(gst_pipeline_new(pipelineName.c_str()));
    if (!pipeline) {
        throw std::runtime_error(LogMsgCreator::createMsg(
                                                std::string(__FILE__),
                                                std::string(__FUNCTION__),
                                                __LINE__,
                                                std::string("Cannot create pipeline")));
    }
}

void GStreamerDynamicPipeline::createBin()
{
    for (const auto& element : elements) {
        gst_bin_add(GST_BIN(pipeline.get()), element->getGstElem());
    }
}

void GStreamerDynamicPipeline::linkElements()
{
    std::vector<GStreamerElement*> helpVec;
    for (const auto& element : elements) {
        if (element->getName() != "source") {
            helpVec.push_back(element.get());
        }
    }

    for (size_t i = 0; i < helpVec.size() - 1; ++i) {
        if (gst_element_link(helpVec[i]->getGstElem(), helpVec[i+1]->getGstElem()) != TRUE) {
            throw std::runtime_error(LogMsgCreator::createMsg(
                                                    std::string(__FILE__),
                                                    std::string(__FUNCTION__),
                                                    __LINE__,
                                                    std::string("Cannot build pipeline")));
        }
    }
}

void GStreamerDynamicPipeline::registerHandler()
{

}

void GStreamerDynamicPipeline::setUrl(const std::string& url)
{
    auto source = GstElementFinder::find("source", elements)->getGstElem();
    auto convert = GstElementFinder::find("convert", elements)->getGstElem();
    g_object_set(source, "uri", url.c_str(), NULL);
    g_signal_connect(source, "pad-added", G_CALLBACK(&GStreamerPadAdd::padAdd), convert);
}

void GStreamerDynamicPipeline::play()
{
    GstStateChangeReturn ret = GST_STATE_CHANGE_FAILURE;
    ret = gst_element_set_state(pipeline.get(), GST_STATE_PLAYING);
    if(ret == GST_STATE_CHANGE_FAILURE) {
        throw std::runtime_error(LogMsgCreator::createMsg(
                                                std::string(__FILE__),
                                                std::string(__FUNCTION__),
                                                __LINE__,
                                                std::string("Cannot set play state")));
    }
}

GstElement* GStreamerDynamicPipeline::get()
{
    return pipeline.get();
}


} // gstreamer
