#include <GL/glu.h>
#include <QGLWidget>
#include <QtGui>
#include <QtCore/QTime>
#include <cmath>
#include <ctime>
#include "SceneWidget.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

// constructor
SceneWidget::SceneWidget(QWidget *parent)
        : QGLWidget(parent) { // constructor
    double frame = 0;
    shapeCreator = new ShapeCreator();
} // constructor

// called when OpenGL context is set up
void SceneWidget::initializeGL() { // initializeGL()
    // set the widget background colour
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_NORMALIZE);
//    float fog_colour[4] = {1, 1, 1, 1};
//    glEnable(GL_FOG);
//    glFogf(GL_FOG_MODE,GL_EXP2);
//    glFogfv(GL_FOG_COLOR,fog_colour);
//    glFogf(GL_FOG_DENSITY,0.05);
//    glHint(GL_FOG_HINT,GL_NICEST);
//    glFogf(GL_FOG_START,10);
//    glFogf(GL_FOG_END,100);

    GLfloat mambient[] = {0.0f, 0.0f, 0.8f, 0.0f};
    GLfloat mdiff[] = {0.8f, 0.8f, 0.8f, 0.0f};
    glLoadIdentity();
    GLfloat mspec[] = {0.f, .8f, .8f, 0.0f};
    GLfloat shininess2[] = {50};
    glEnable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mdiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mspec);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);
//    GLfloat shininess2[] = {50};
//    glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);
    GLfloat light_ambient[] = {0.1, 0.1, 0.1, 0.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 0.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {0.0, 5, 0.0, 1.0};
    GLfloat shininess[] = {100.0};

//    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glLightfv(GL_LIGHT0, GL_SHININESS, shininess);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

//    GLfloat mcyan[] = {0.0f, .8f, .8f, 1.f};
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, mcyan);
    GLfloat light1_ambient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat light1_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light1_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light1_position[] = {-2.0, 2.0, 1.0, 1.0};
    GLfloat spot_direction[] = {-1.0, -1.0, 0.0};

//    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
//    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
//    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
//    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
//    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
//    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
//    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);
//
//    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
//    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
//    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
//
//    glEnable(GL_LIGHT1);


//    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

} // initializeGL()

// called every time the widget is resized
void SceneWidget::resizeGL(int w, int h) { // resizeGL()
    // set the viewport to the entire widget
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float width = w;
    float height = h;
    gluPerspective(90, -width / height, 0.01, sqrt(pow(30, 2) + pow(10, 2)) + pow(20, 2));
} // resizeGL()

void SceneWidget::keyPressEvent(QKeyEvent *key) {
    qDebug() << key;
    const float cameraSpeed = 0.1f; // adjust accordingly
    const float turningSpeed = 0.05f;

    //Keep yaw between -pi/2 and pi/2
    qDebug() << camX;
    if (camX < 0) {
        yaw = (M_PI + yaw);
    }
    if (key->key() == Qt::Key_E) {
        float newYaw = yaw - M_PI / 2;
        cameraPosition[2] += sin(newYaw) * cameraSpeed;
        cameraDirection[2] += sin(newYaw) * cameraSpeed;
        cameraPosition[0] += cos(newYaw) * cameraSpeed;
        cameraDirection[0] += cos(newYaw) * cameraSpeed;
    }
    if (key->key() == Qt::Key_Q) {
        float newYaw = yaw + M_PI / 2;
        cameraPosition[2] += sin(newYaw) * cameraSpeed;
        cameraDirection[2] += sin(newYaw) * cameraSpeed;
        cameraPosition[0] += cos(newYaw) * cameraSpeed;
        cameraDirection[0] += cos(newYaw) * cameraSpeed;
    }


    if (key->key() == Qt::Key_W) {
        cameraPosition[0] += cos(yaw) * cameraSpeed;
        cameraDirection[0] += cos(yaw) * cameraSpeed;
        cameraPosition[2] += sin(yaw) * cameraSpeed;
        cameraDirection[2] += sin(yaw) * cameraSpeed;
    }
    if (key->key() == Qt::Key_S) {
        cameraPosition[0] -= cos(yaw) * cameraSpeed;
        cameraDirection[0] -= cos(yaw) * cameraSpeed;
        cameraPosition[2] -= sin(yaw) * cameraSpeed;
        cameraDirection[2] -= sin(yaw) * cameraSpeed;
    }

    if (key->key() == Qt::Key_D) {
        turningNumber += turningSpeed;
    }
    if (key->key() == Qt::Key_A) {
        turningNumber -= turningSpeed;
    }
    camX = sin(turningNumber) * radius;
    camZ = cos(turningNumber) * radius;
    cameraDirection[0] = cameraPosition[0] - camX;
    cameraDirection[2] = cameraPosition[2] - camZ;
    if (camX != 0) {
        yaw = atan(camZ / camX);
//        if (camX < 0) {
//            yaw = -1 * atan(camZ / camX);
//        }
    } else {
        if (camZ == 1) {
            yaw = M_PI_2;
        } else {
            yaw = 3 * M_PI_2;
        }
    }
    if (key->key() == Qt::Key_R) {

        cameraPosition[1] += 0.2;
        cameraDirection[1] += 0.2;
//            updateGL();

    }
    if (key->key() == Qt::Key_T) {

        cameraPosition[1] -= 0.2;
        cameraDirection[1] -= 0.2;
//            updateGL();

    }
    if (key->key() == Qt::Key_F) {

//        cameraPosition[1] += 0.2;
        cameraDirection[1] += 0.2;
//            updateGL();

    }
    if (key->key() == Qt::Key_G) {

//        cameraPosition[1] -= 0.2;
        cameraDirection[1] -= 0.2;
//            updateGL();

    }

    if (key->key() == Qt::Key_Control) {
        while (cameraPosition[1] > 4) {

            cameraPosition[1] -= 0.2;
            cameraDirection[1] -= 0.3;
            updateGL();

        }
    }
    if (jumping || falling) {
        key->ignore();
        return;
    }
    if (key->key() == Qt::Key_Shift && !jumping && !falling && !key->isAutoRepeat()) {
        qDebug() << jumping;
        while (cameraPosition[1] < 6.5) {

            cameraPosition[1] += 0.2;
            cameraDirection[1] += 0.2;
            cameraPosition[1] -= 1.0 / 16;
            cameraDirection[1] -= 1.0 / 16;
            updateGL();
            jumping = true;
        }
        while (cameraPosition[1] > 5) {

            cameraPosition[1] -= 1.0 / 16;
            cameraDirection[1] -= 1.0 / 16;
            updateGL();
            falling = true;
        }
        cameraPosition[1] = 5;
        cameraDirection[1] = 5;
        jumping = false;
        falling = false;
    }
    qDebug() << "pos" << cameraPosition[0] << cameraPosition[1] << cameraPosition[2];
    qDebug() << "dir" << cameraDirection[0] << cameraDirection[1] << cameraDirection[2] << camZ << camX;
    qDebug() << "yaw" << yaw << fmod((yaw / M_2_PI) * 360, 360);
    updateGL();
}


void SceneWidget::keyReleaseEvent(QKeyEvent *key) {

    if (key->key() == Qt::Key_Control) {
        while (cameraPosition[1] < 5) {
            cameraPosition[1] += 0.2;
            cameraDirection[1] += 0.3;
            updateGL();
        }

        cameraPosition[1] = 5;
        cameraDirection[1] = 5;
    }

}

// called every time the widget needs painting
void SceneWidget::paintGL() { // paintGL()
    // clear the widget
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // You must set the matrix mode to model view directly before enabling the depth test
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST); // comment out depth test to observe the result

    glPushMatrix();
    glTranslatef(0, 11, 0);
    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 9, 0);
    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, 9, 0);
    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 9, 3);
    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 9, -3);
    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 5, 0);
    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 2, 0);
    shapeCreator->createTessCube(100, 1, 1, 10, 10, 10);
    glPopMatrix();

    shapeCreator->walls(10.0, 20.0, 30.0, 100, 100, 100);


//    shapeCreator->createCube(2.0, 3.0, 2.0, 1.0, 0, 0.0);
//    shapeCreator->createCube(2.0, 3.0, 2.0, 1.0, 15, 0.0);
//    shapeCreator->createCube(1, 1, 1, -3, 6, -5);
//    glTranslatef(-3, 3, -5); //move to the desired location
//    GLdouble r = 2;
//    GLint sl = 40;
//    GLint spl = 20;
//    shapeCreator->createSphere(r, sl, spl);
//    shapeCreator->createCylinder(r, r, r * 3, sl, spl);
//    glTranslatef(-2., 3., 5.);
//    shapeCreator->createTessCube(2, 4, 5, 10, 10, 10);
//    glTranslatef(0, 3, 0);
//    shapeCreator->>createCube(2, 4, 5, 0, 0, 0);
//    glTranslatef(0, 3, 0);
//    glScaled(0.5, 0.5, 0.5);
//    shapeCreator->createSemiCylinder(1.0, 1000.0, 10, 10, 10);

    float radius = 1;
//    duration = ( ( clock() - start )/ (double) CLOCKS_PER_SEC) *24;
    float camX = sin(frame / 24) * radius;
    float camZ = cos(frame / 24) * radius;
    float camHeight = 5;
    frame++;
    glLoadIdentity();

    gluLookAt(cameraDirection[0], cameraDirection[1], cameraDirection[2], cameraPosition[0], cameraPosition[1],
              cameraPosition[2], cameraUp[0], cameraUp[1] + 10000000000000, cameraUp[2]);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);

    // flush to screen
    glFlush();
    frame++;
} // paintGL()
