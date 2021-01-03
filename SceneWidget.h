#ifndef SCENE_SceneWidget_H
#define SCENE_SceneWidget_H

#include <QGLWidget>
#include <QGLFunctions>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <QtGui>
#include <QtCore/QTime>
#include <QTimer>
#include <QApplication>
#include <QObject>

#include <GL/glu.h>
#include <QGLWidget>
#include <QtGui>
#include <QtCore/QTime>
#include <cmath>
#include <ctime>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ShapeCreator.h"
#include "TextureCreator.h"
#include <experimental/filesystem>
#include "limits.h"


using namespace std;


class SceneWidget : public QGLWidget, protected QGLFunctions { //
Q_OBJECT
public:
    SceneWidget(QWidget *parent);
    unsigned long long frameDifference;
    ShapeCreator *shapeCreator;
    float turnTableRotationSpeed = 1;


protected:
    // called when OpenGL context is set up
    void initializeGL();

    // called every time the widget is resized
    void resizeGL(int w, int h);

    // called every time the widget needs painting
    void paintGL();

    void updateFrameActions();

    void keyPressEvent(QKeyEvent *key);

    void keyReleaseEvent(QKeyEvent *key);


    float *getShadowMatrix(float p[4], float l[4]);

    unsigned long long frame;
    unsigned long long lastFrameRecorded;
    float cameraPosition[3] = {0, 5, 0};
    float light0Position[4] = {0, 15, -500, 1};
    float cameraUp[3] = {0, 6, 0};
    float fov = 90;
    float radius = 0.1;
    float turningNumber = 0;
    float yaw = M_PI_2;
    float camX = sin(turningNumber) * radius;
    float camZ = cos(turningNumber) * radius;
    float cameraDirection[3] = {cameraPosition[0] - 0, 5, cameraPosition[2] - radius};
    bool jumping = false;
    bool falling = false;
    static constexpr float roomDepth = 50.0;
    static constexpr float roomWidth = 70.0;
    static constexpr float roomHeight = 30.0;
    float light1Position[4] = {0, 1, -roomDepth/2+3, 1};

    float geishaPosition[3] = {0,3,-1};
    float geishaRotation = 0;

    GLuint geishaFrameBuffer;


    long unsigned int appleVertNumber;
    float vertexFloatArray[48519]; // Update if vert number updates

    float rotateCube = 0;
    GLfloat shadowMatrix1[16];


    TextureCreator *textureCreator;
    QWidget *window;

public slots:
    unsigned long long getFrameRate();
    void changeScreenTexture(int i);


private:
    void walls();
    void placeTerrain();

    void drawPC();

    void testLight();

    void drawShadows();

    void drawGeisha(bool black);

    void drawFire();

}; // class GLPolygonWidget

#endif