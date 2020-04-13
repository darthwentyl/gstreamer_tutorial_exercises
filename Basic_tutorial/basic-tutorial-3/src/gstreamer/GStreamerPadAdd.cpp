#include <gstreamer/GStreamerPadAdd.hpp>

#include <cstdio>
#include <cstdlib>

namespace gstreamer {

void GStreamerPadAdd::padAdd(GstElement* src, GstPad* new_pad, GstElement* convert)
{
    GstPad *sink_pad = gst_element_get_static_pad(convert, "sink");
    GstPadLinkReturn ret;
    GstCaps *new_pad_caps = nullptr;
    GstStructure *new_pad_struct = nullptr;
    const gchar *new_pad_type = nullptr;

    printf("Received new pad '%s' from '%s':\n", GST_PAD_NAME (new_pad), GST_ELEMENT_NAME (src));

    /* If our converter is already linked, we have nothing to do here */
    if(gst_pad_is_linked (sink_pad)) {
        printf("We are already linked. Ignoring.\n");
        goto exit;
    }

    /* Check the new pad's type */
    new_pad_caps = gst_pad_get_current_caps (new_pad);
    new_pad_struct = gst_caps_get_structure (new_pad_caps, 0);
    new_pad_type = gst_structure_get_name (new_pad_struct);
    if (!g_str_has_prefix (new_pad_type, "audio/x-raw")) {
        g_print ("It has type '%s' which is not raw audio. Ignoring.\n", new_pad_type);
        goto exit;
    }

    /* Attempt the link */
    ret = gst_pad_link (new_pad, sink_pad);
    if (GST_PAD_LINK_FAILED (ret)) {
        printf("Type is '%s' but link failed.\n", new_pad_type);
    } else {
        printf("Link succeeded (type '%s').\n", new_pad_type);
    }

    exit:
        /* Unreference the new pad's caps, if we got them */
        if (new_pad_caps != NULL)
            gst_caps_unref (new_pad_caps);

        /* Unreference the sink pad */
        gst_object_unref (sink_pad);
}

} // gstreamer



