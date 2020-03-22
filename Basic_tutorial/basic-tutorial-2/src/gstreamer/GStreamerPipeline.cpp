#include <gstreamer/GStreamerPipeline.hpp>
#include <gstreamer/GStreamerDeleter.hpp>
#include <gstreamer/GStreamerSource.hpp>
#include <gstreamer/GStreamerSink.hpp>
#include <gstreamer/GStreamerFilter.hpp>

#include <exceptions/LogMsgCreator.hpp>

namespace gstreamer {

using namespace exceptions;

GStreamerPipeline::GStreamerPipeline() :
        pipeline(nullptr, GStreamerDeleter::element)
{}

GStreamerPipeline::~GStreamerPipeline()
{
    gst_element_set_state(pipeline.get(), GST_STATE_NULL);
}

void GStreamerPipeline::create(const std::string& pipelineName)
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

void GStreamerPipeline::build(GStreamerSource& source, GStreamerSink& sink, GStreamerFilter& filter)
{
    gst_bin_add_many(GST_BIN(pipeline.get()), source.get(), filter.get(), sink.get(), nullptr);
    if (gst_element_link_many(source.get(), filter.get(), sink.get(), nullptr) != TRUE) {
        throw std::runtime_error(LogMsgCreator::createMsg(
                                                std::string(__FILE__),
                                                std::string(__FUNCTION__),
                                                __LINE__,
                                                std::string("Cannot build pipeline")));
    }
}

void GStreamerPipeline::play()
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

GstElement* GStreamerPipeline::get()
{
    return pipeline.get();
}


} // gstreamer
