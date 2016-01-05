#include "View3d.h"

View3D::View3D(QScreen *targetScreen) : QWindow(targetScreen){
    setSurfaceType( QSurface::OpenGLSurface );
    QSurfaceFormat format;
    format.setSamples( 4 );
    setFormat( format );
    create( );
}
