#pragma once

#include <gstreamer/handlers/MsgHandleIfc.hpp>

namespace gstreamer { namespace handlers {

class MsgHandleEos : public MsgHandleIfc {
public:
    virtual ~MsgHandleEos() = default;
    virtual void handle(GstMessage& msg) override;
};

} } // gstreamer::handlers
