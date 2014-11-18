#include <QOpenGLContext>
#include <QOffscreenSurface>
#include <QOpenGLContext>

#ifndef GLSharedContext_h
#define GLSharedContext_h

namespace WebCore {

class GLSharedContext {
public:
    static QOpenGLContext* context();
    static QOffscreenSurface* surface();
    static void setSharingContext(QOpenGLContext *sharing);
    static QOpenGLContext* sharingContext();
    static void makeCurrent();

private:
    static void initialize();

    static QOffscreenSurface *m_surface;
    static QOpenGLContext *m_context;
    static QOpenGLContext *m_sharing;
};

}

#endif
