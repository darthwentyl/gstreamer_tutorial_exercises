#include <gstreamer/handlers/MsgHandleFactory.hpp>

#include <gstreamer/handlers/MsgHandleIfc.hpp>
#include <gstreamer/handlers/MsgHandleEos.hpp>
#include <gstreamer/handlers/MsgHandleError.hpp>

namespace gstreamer { namespace handlers {

void MsgHandleFactory::create(std::map<GstMessageType, std::unique_ptr<MsgHandleIfc>>& handlerMap)
{
    handlerMap[GST_MESSAGE_EOS] = std::make_unique<MsgHandleEos>();
    handlerMap[GST_MESSAGE_ERROR] =  std::make_unique<MsgHandleError>();
}

} } // gstreamer::handlers
