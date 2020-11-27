#ifndef __GL_POLYGON_WIDGET_H__
#define __GL_POLYGON_WIDGET_H__ 1
#endif

#include <QGLWidget>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <QtGui>
#include <QtCore/QTime>
#include <GL/glu.h>
#include <QGLWidget>
#include <QtGui>
#include <QtCore/QTime>
#include <cmath>
#include <ctime>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


class ShapeCreator { //
public:
    ShapeCreator();

    void walls(float w, float h, float d, int tX, int tY, int tZ);

    void createTessCube(float width, float height, float depth, int tessX, int tessY, int tessZ);

    void createCube(float w, float h, float d, float x, float y, float z);

    void createSphere(GLdouble radius, GLint slices, GLint stacks);

    void createCylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);

    void createSemiCylinder(float rad, float length, int x, int y, int z);
protected:

private:
};

