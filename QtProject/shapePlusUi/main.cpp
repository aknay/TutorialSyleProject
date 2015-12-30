#include "scenemodifier.h"
#include "mainwindow.h"
#include <QApplication>
#include <view3d.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    View3D view3D;
    w.add3DView(view3D);

    Qt3D::QAspectEngine engine;
    engine.registerAspect(new Qt3D::QRenderAspect());
    Qt3D::QInputAspect *input = new Qt3D::QInputAspect;
    engine.registerAspect(input);
    engine.initialize();
    QVariantMap data;
    data.insert(QStringLiteral("surface"), QVariant::fromValue(static_cast<QSurface *>(&view3D)));
    data.insert(QStringLiteral("eventSource"), QVariant::fromValue(&view3D));
    engine.setData(data);

    // Root entity
    Qt3D::QEntity *rootEntity = new Qt3D::QEntity();

    // Camera
    Qt3D::QCamera *cameraEntity = new Qt3D::QCamera(rootEntity);
    cameraEntity->setObjectName(QStringLiteral("cameraEntity"));

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 0, -20.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));
    input->setCamera(cameraEntity);

    // FrameGraph
    Qt3D::QFrameGraph *frameGraph = new Qt3D::QFrameGraph();
    Qt3D::QForwardRenderer *forwardRenderer = new Qt3D::QForwardRenderer();

    forwardRenderer->setCamera(cameraEntity);
    forwardRenderer->setClearColor(QColor(QRgb(0x4d4d4f)));
    frameGraph->setActiveFrameGraph(forwardRenderer);

    // Setting the FrameGraph
    rootEntity->addComponent(frameGraph);

    // Scenemodifier
    SceneModifier *modifier = new SceneModifier(rootEntity);

    // Set root object of the scene
    engine.setRootEntity(rootEntity);

    w.show();
    return a.exec();
}
