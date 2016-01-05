#include "CubeObject.h"

CubeObject::CubeObject(Qt3D::QEntity *parent):
    Qt3D::QEntity(parent),
    cuboidScale(new Qt3D::QScaleTransform()),
    cuboidTranslation (new Qt3D::QTranslateTransform()),
    cuboidTransforms (new Qt3D::QTransform()),
    torusRotation (new Qt3D::QRotateTransform()),
    cuboidMaterial (new Qt3D::QPhongMaterial())
{
    mCube = new Qt3D::QCuboidMesh();

    cuboidScale->setScale3D(QVector3D(2.0f, 2.0f, 2.0f));
    cuboidTranslation->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    cuboidTransforms->addTransform(cuboidTranslation);
    cuboidTransforms->addTransform(cuboidScale);

    cuboidMaterial->setDiffuse(QColor(QRgb(0x665423)));

    addComponent(mCube);
    addComponent(cuboidMaterial);
    addComponent(cuboidTransforms);

}

CubeObject::~CubeObject(){
    delete mCube;
    delete cuboidTranslation;
    delete cuboidTransforms;
    delete torusRotation;
    delete cuboidMaterial;
}


void CubeObject::setRotation(float v, QVector3D vector){
    /*previously has this problem: corrupted double-linked list:*/
    torusRotation->setAngleDeg(v);
    torusRotation->setAxis(QVector3D(0, 0, 1));
    cuboidTransforms->addTransform(torusRotation);
}
