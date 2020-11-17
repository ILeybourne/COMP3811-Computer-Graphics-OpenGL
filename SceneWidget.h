#ifndef __GL_POLYGON_WIDGET_H__
#define __GL_POLYGON_WIDGET_H__ 1

#include <QGLWidget>
#include <cstdio>
//#include <stdin>
#include <ctime>
#include <cmath>
#include <QtGui>
#include <QtCore/QTime>


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

    void walls(float w,float h, float d ,int tX, int tY, int tZ);
    void createTessCube(float width, float height, float depth, int tessX, int tessY, int tessZ);
    void createCube(float w,float h, float d, float x, float y, float z);
    void createSphere(GLdouble radius, GLint slices, GLint stacks);
    void createCylinder(GLdouble base, GLdouble top,GLdouble height, GLint slices, GLint stacks);
    void createSemiCylinder(float rad, float length, int x, int y, int z) ;

    double frame;
    float cameraPosition[3] = {0, 5, 0};
    float cameraUp[3] = {0, 6, 0};
    float radius = 1;
    float turningNumber = 0;
    float yaw = M_PI_2;
    float camX = sin(turningNumber) * radius;
    float camZ = cos(turningNumber) * radius;
    float cameraDirection[3] = {cameraPosition[0] - 0, 5, cameraPosition[2] - radius};
    bool jumping = false;
    bool falling = false;
private:
    void walls();
}; // class GLPolygonWidget

#endif
