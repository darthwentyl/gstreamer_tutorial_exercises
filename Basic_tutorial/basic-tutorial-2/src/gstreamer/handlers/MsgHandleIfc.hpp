#pragma once

namespace gstreamer { namespace handlers {

class MsgHandleIfc
{
public:
    virtual ~MsgHandleIfc() = default;
    virtual void handle() = 0;
};

} } // gstreamer::handlers
