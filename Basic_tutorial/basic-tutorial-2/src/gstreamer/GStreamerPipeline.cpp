#include <gstreamer/GStreamerPipeline.hpp>
#include <gstreamer/GStreamerDeleter.hpp>
#include <gstreamer/GStreamerSource.hpp>
#include <gstreamer/GStreamerSink.hpp>
#include <gstreamer/GStreamerFilter.hpp>

#include <exceptions/LogMsgCreator.hpp>

namespace gstreamer {

using namespace exceptions;

GStreamerDynamicPipeline::GStreamerDynamicPipeline() :
        pipeline(nullptr, GStreamerDeleter::element)
{}

GStreamerDynamicPipeline::~GStreamerDynamicPipeline()
{
    gst_element_set_state(pipeline.get(), GST_STATE_NULL);
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

void GStreamerDynamicPipeline::build(const std::vector<std::unique_ptr<GStreamerElementIfc>>& elements)
{
    for (const auto& element : elements) {
        gst_bin_add(GST_BIN(pipeline.get()), element->get());
    }

    for (size_t i = 0; i < elements.size() - 1; ++i) {
        if (gst_element_link(elements[i]->get(), elements[i+1]->get()) != TRUE) {
            throw std::runtime_error(LogMsgCreator::createMsg(
                                                    std::string(__FILE__),
                                                    std::string(__FUNCTION__),
                                                    __LINE__,
                                                    std::string("Cannot build pipeline")));
        }
    }
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
