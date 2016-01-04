#ifndef TESTCUBE_H
#define TESTCUBE_H

#include <Qt3DCore/QEntity>
#include <Qt3DRenderer/QCuboidMesh>
#include <Qt3DCore/qrotatetransform.h>
#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/QTranslateTransform>
#include <Qt3DCore/qscaletransform.h>
#include <Qt3DRenderer/QPhongMaterial>

class TestCube : public Qt3D::QEntity
{
public:
     ~TestCube();
    TestCube(Qt3D::QEntity *parent = 0);
    void setRotation(float v, QVector3D vector);
private:
    Qt3D::QCuboidMesh *mCube;
    Qt3D::QScaleTransform *cuboidScale;
    Qt3D::QTranslateTransform *cuboidTranslation;
    Qt3D::QTransform *cuboidTransforms;
    Qt3D::QRotateTransform *torusRotation;
    Qt3D::QPhongMaterial *cuboidMaterial;
};

#endif // TESTCUBE_H


/*GOOD ARTICLE TO READ*/

/*
 *
Explanation: We need to initilize as reference memeber (example: class *c = class())
in 'member initilization list because we need to object live as its own (meaning object
will live even its parent is destoryed)

<What is Member Initilization List>
http://stackoverflow.com/questions/1711990/what-is-this-weird-colon-member-syntax-in-the-constructor

<Why we need Member Initilization as Reference member>
http://stackoverflow.com/questions/892133/should-i-prefer-pointers-or-references-in-member-data

<Why Reference member is used as Aggregation>
http://stackoverflow.com/questions/12387239/reference-member-variables-as-class-members?lq=1
http://www.learncpp.com/cpp-tutorial/103-aggregation/
*/
