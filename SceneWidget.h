#ifndef __GL_POLYGON_WIDGET_H__
#define __GL_POLYGON_WIDGET_H__ 1
#endif

#include <QGLWidget>
#include <cstdio>
//#include <stdin>
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
#include "ShapeCreator.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class SceneWidget : public QGLWidget { //
public:
    SceneWidget( QWidget *parent);
protected:
    // called when OpenGL context is set up
    void initializeGL();
    // called every time the widget is resized
    void resizeGL(int w, int h);
    // called every time the widget needs painting
    void paintGL();
    void keyPressEvent(QKeyEvent *key);
    void keyReleaseEvent(QKeyEvent *key);

    double frame;
    float cameraPosition[3] = {0, 5, 0};
    float light0Position[4] = {0, 15, 0,1};
    float cameraUp[3] = {0, 6, 0};
    float radius = 1;
    float turningNumber = 0;
    float yaw = M_PI_2;
    float camX = sin(turningNumber) * radius;
    float camZ = cos(turningNumber) * radius;
    float cameraDirection[3] = {cameraPosition[0] - 0, 5, cameraPosition[2] - radius};
    bool jumping = false;
    bool falling = false;

    ShapeCreator *shapeCreator;

private:
    void walls();
}; // class GLPolygonWidget

