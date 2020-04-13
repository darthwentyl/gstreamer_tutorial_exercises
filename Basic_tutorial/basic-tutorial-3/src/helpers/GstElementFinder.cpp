#include <helpers/GstElementFinder.hpp>

#include <iostream>

namespace helpers {

using namespace gstreamer;

GStreamerElement* GstElementFinder::find(const std::string& name,
            const std::vector<std::unique_ptr<GStreamerElement>>& elements)
{
    for (const auto& element : elements) {
        if (element->getName() == name) {
            return element.get();
        }
    }
    std::cerr << __FUNCTION__ << ":" << __LINE__ << " [ERR] cannot find " << name.c_str() << std::endl;
    return nullptr;
}

} // helpers




