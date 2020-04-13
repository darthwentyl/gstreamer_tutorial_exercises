#pragma once

#include <gstreamer/handlers/MsgHandleIfc.hpp>

namespace gstreamer { namespace handlers {

class MsgHandleError : public MsgHandleIfc {
public:
    virtual ~MsgHandleError() = default;
    virtual void handle(GstMessage& msg) override;
};

} } // gstreamer::handlers
