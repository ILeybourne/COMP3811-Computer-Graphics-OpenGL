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
#include <vector>
#include "ShapeCreator.h"
#include "TextureCreator.h"

// #ifdef __cpp_lib_filesystem
//     #include <filesystem>
//     using fs = std::filesystem;
// #elif __cpp_lib_experimental_filesystem
//     #include <experimental/filesystem>
//     using fs = std::experimental::filesystem;
// #else
// //    #error "no filesystem support ='("
// #endif
#include "limits.h"


using namespace std;


class SceneWidget : public QGLWidget, protected QGLFunctions { //
Q_OBJECT
public:
    SceneWidget(QWidget *parent);

    unsigned long long frameDifference = 0;
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

//    void keyReleaseEvent(QKeyEvent *key);


    float *getShadowMatrix(float p[4], float l[4]);

    unsigned long long frame = 0;
    unsigned long long lastFrameRecorded = 0;
    float lowestTerrain = 100;

    float cameraPosition[3] = {0, 5 - lowestTerrain - roomHeight, 0};
    float cameraStartPosition[3] = {cameraPosition[0], cameraPosition[1], cameraPosition[2]};
    float cameraUp[3] = {0, 6, 0};
    float fov = 60;
    float radius = 0.1;
    float turningNumber = 0;
    float startingTurningNumber = turningNumber;
    float yaw = M_PI_2;
    float startingYaw = yaw;
    float camX = sin(turningNumber) * radius;
    float camZ = cos(turningNumber) * radius;
    float cameraDirection[3] = {cameraPosition[0] - 0, cameraPosition[1], cameraPosition[2] - radius};
    float cameraStartDirection[3] = {cameraDirection[0], cameraDirection[1], cameraDirection[2]};

    bool jumping = false;
    bool falling = false;

    static constexpr float roomDepth = 50.0;
    static constexpr float roomWidth = 70.0;
    static constexpr float roomHeight = 30.0;

    ////Right of tunnel
    float cosPiOver3 = cos(M_PI / 3);
    float sinPiOver3 = sin(M_PI / 3);
    ////Left of tunnel
    float negCosPiOver3 = cos(-M_PI / 3);
    float negSinPiOver3 = sin(-M_PI / 3);

    float light0Position[4] = {0, 15, -500, 1};
    float light1Position[4] = {0, 3 - lowestTerrain - roomHeight, -roomDepth / 2 + 5, 1};
    float light2Position[4] = {roomWidth - roomWidth / 3,
                               roomDepth / 2 * negCosPiOver3 - roomDepth / 10 - lowestTerrain - roomHeight,
                               roomDepth / 2 * negSinPiOver3, 1};
    float light3Position[4] = {roomWidth, roomDepth / 2 * cosPiOver3 - roomDepth / 10 - lowestTerrain - roomHeight,
                               roomDepth / 2 * sinPiOver3, 1};
    float light4Position[4] = {roomWidth + roomWidth / 3,
                               roomDepth / 2 * negCosPiOver3 - roomDepth / 10 - lowestTerrain - roomHeight,
                               roomDepth / 2 * negSinPiOver3, 1};

    float geishaPosition[3] = {5, 2.5, -3};
    bool moveLeft = true;
    bool moveRight = false;
    bool turningLeft = false;
    bool turningRight = false;
    int geishaRotation = 270;
    float geishaBop = 0;

    float rotateCube = 0;

    QWidget *window;

public slots:

    unsigned long long getFrameRate();

    void changeScreenTexture(int i);

    void changeGyroTexture(int i);

    void resetCamera();

    void changeTerrainSeed(QString seed);

private:
    void walls();

    void placeTerrain();

    void testLight();

    void drawShadows();

    void drawGeishas(bool black);

    void drawFire();

};

#endif
