#include "config.h"
#include "GLSharedContext.h"
#include <stdio.h>

namespace WebCore {

QOpenGLContext* GLSharedContext::context()
{
    if (!m_context)
        initialize();
    return m_context;
}

QOffscreenSurface* GLSharedContext::surface()
{
    if (!m_surface)
        initialize();
    return m_surface;
}

void GLSharedContext::setSharingContext(QOpenGLContext *sharing) {
    m_sharing = sharing;
}

QOpenGLContext* GLSharedContext::sharingContext() {
    return m_sharing;
}

void GLSharedContext::makeCurrent() {
    if (!m_context)
        initialize();

    if (QOpenGLContext::currentContext() != m_context) {
        m_context->makeCurrent(m_surface);
    }
}

void GLSharedContext::initialize()
{
    m_surface = new QOffscreenSurface();
    m_surface->create();
    m_context = new QOpenGLContext();
    m_context->setShareContext(m_sharing);
    m_context->create();
    makeCurrent();
}

QOffscreenSurface* GLSharedContext::m_surface = 0;
QOpenGLContext* GLSharedContext::m_context = 0;
QOpenGLContext* GLSharedContext::m_sharing = 0;
}
