//#define GL_GLEXT_PROTOTYPES
//#include <GL/glew.h>
#include <GL/glu.h>
#include <QGLWidget>
#include <QtGui>
#include <QtCore/QTime>
#include <cmath>
#include <ctime>
#include "SceneWidget.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
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
#include "ShapeCreator.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>


// constructor
SceneWidget::SceneWidget(QWidget *parent)
        : QGLWidget(parent) { // constructor
    double frame = 0;
    shapeCreator = new ShapeCreator(this);
} // constructor

// called when OpenGL context is set up
void SceneWidget::initializeGL() { // initializeGL()
    //Enable anti-alias
    glEnable(GL_MULTISAMPLE);
    //Normalize normals upon transformations
    glEnable(GL_NORMALIZE);
    // set the widget background colour
    glClearColor(0.8, 0.3, 0.3, 0.0);

    initializeGLFunctions();

    ////Fog
//    float fog_colour[4] = {1, 1, 1, 1};
//    glEnable(GL_FOG);
//    glFogf(GL_FOG_MODE,GL_EXP2);
//    glFogfv(GL_FOG_COLOR,fog_colour);
//    glFogf(GL_FOG_DENSITY,0.05);
//    glHint(GL_FOG_HINT,GL_NICEST);
//    glFogf(GL_FOG_START,10);
//    glFogf(GL_FOG_END,100);

//    GLfloat mambient[] = {0.0f, 0.0f, 0.8f, 0.0f};
//    GLfloat mdiff[] = {0.8f, 0.8f, 0.8f, 0.0f};

    ////Light parameters
    GLfloat mambient[] = {0.0f, 0.0f, 0.8f, 0.0f};
    GLfloat mdiff[] = {0.8f, 0.8f, 0.8f, 0.0f};
    glLoadIdentity();
    GLfloat mspec[] = {0.f, .8f, .8f, 0.0f};
    GLfloat shininess2[] = {100};

    ////Material parameters
    glEnable(GL_COLOR_MATERIAL);
//    glMaterialfv(GL_FRONT, GL_AMBIENT, mambient);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, mdiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mspec);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);

//    GLfloat shininess2[] = {50};
//    glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);

    GLfloat shininess[] = {100.0};
    GLfloat shininess3[] = {5.0};


    ////Light 0
    GLfloat light_0_ambient[] = {0.3, 0.2, 0.25, 0.0};
    GLfloat light_0_diffuse[] = {1.0, 1.0, 1.0, 0.0};
    GLfloat light_0_specular[] = {1.0, 1.0, 1.0, 1.0};
//    GLfloat light_position[] = {0.0, 5, 0.0, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_0_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glLightfv(GL_LIGHT0, GL_SHININESS, shininess3);
    glEnable(GL_LIGHT0);


    ////Light 1
    GLfloat light_1_ambient[] = {0.1, 0.1, 0.1, 0.0};
    GLfloat light_1_diffuse[] = {1.0, 1.0, 1.0, 0.0};
    GLfloat light_1_specular[] = {1.0, 1.0, 1.0, 1.0};
//    GLfloat light_position[] = {0.0, 5, 0.0, 1.0};
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_1_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
    glLightfv(GL_LIGHT1, GL_SHININESS, shininess);
    glEnable(GL_LIGHT1);

    glShadeModel(GL_SMOOTH);
//    glLightModel(GL_LIGHT_MODEL_AMBIENT, )
    glEnable(GL_LIGHTING);

    glEnable(GL_CULL_FACE);

    ////Cull back of faces
    glCullFace(GL_BACK);


    ////Load Apple pc info
    bool res = shapeCreator->getOBJData("/AppleIIe4.obj", shapeCreator->vertices3, shapeCreator->uvs3,
                                        shapeCreator->normals3);
    qDebug() << res;

    qDebug() << shapeCreator->vertices3.size() << shapeCreator->uvs3.size();

//    appleVertNumber = shapeCreator->vertices.size() * 3;
//    static const long unsigned int appleVertNumberConst = appleVertNumber;
//    qDebug() << vertSize3;
//    vertexFloatArray[appleVertNumberConst];
//    for (int i = 0; i < shapeCreator->vertices.size(); i++) {
//        vertexFloatArray[i * 3 + 0] = shapeCreator->vertices[i][0];
//        vertexFloatArray[i * 3 + 1] = shapeCreator->vertices[i][1];
//        vertexFloatArray[i * 3 + 2] = shapeCreator->vertices[i][2];
//    }


    QStringList textureStrings = {
//            "./textureinternet/wall.jpg"
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_0_Front+Z.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_1_Back-Z.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_2_Left+X.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_3_Right-X.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_4_Up+Y.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_5_Down-Y.jpg",
            "./textureinternet/appleIIe.jpg"
    };

//    QStringList appleTextureString = { "./textureinternet/appleIIe.jpg"};

    ////Load textures
    shapeCreator->imageLoader(textureStrings);

//    ////Pc vertex data
//    glGenBuffers(1, &vertexbuffer);
//    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//    glBufferData(GL_ARRAY_BUFFER, shapeCreator->vertices.size() * sizeof(glm::vec3), &shapeCreator->vertices[0],
//                 GL_STATIC_DRAW);
//
////    glBindTexture(GL_TEXTURE_2D, shapeCreator->MyTexture[6]);
//    ////Pc uv data
//    glGenBuffers(1, &uvbuffer);
//    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
//    glBufferData(GL_ARRAY_BUFFER, shapeCreator->uvs.size() * sizeof(glm::vec2), &shapeCreator->uvs[0],
//                 GL_STATIC_DRAW);
//
//    ////Pc normal data
//    glGenBuffers(1, &normalbuffer);
//    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
//    glBufferData(GL_ARRAY_BUFFER, shapeCreator->normals.size() * sizeof(glm::vec3), &shapeCreator->normals[0],
//                 GL_STATIC_DRAW);


    ////Wireframe mode
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
    gluPerspective(this->fov, -width / height, 0.01, sqrt(pow(1000, 2) + pow(1000, 2)) + pow(1000, 2));
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

//TODO call once
float *SceneWidget::getShadowMatrix(float p[4], float l[4]) {
    static float shadowMatrix[16];

    float wall[4] = {0, 0, 0, 0};
    wall[0] = p[0];
    wall[1] = p[1];
    wall[2] = p[2];
    wall[3] = p[3];

    float light[4] = {0, 0, 0, 0};
    light[0] = l[0];
    light[1] = l[1];
    light[2] = l[2];
    light[3] = l[3];

//    float wall[4] = {0, 0, -1, 15 - 0.01};

//    float width= ;
//    float height= ;
//    float depth= ;
//
//    glm::vec3 p1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
//    glm::vec3 p2 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
//    glm::vec3 p3 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
//    glm::vec3 p4 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};

//    plane[0] = ((p2[1]-p1[1])*(p3[2]-p1[2]))-
//               ((p2[2]-p1[2])*(p3[1]-p1[1]));
//    plane[1] = ((p2[2]-p1[2])*(p3[0]-p1[0]))-
//               ((p2[0]-p1[0])*(p3[2]-p1[2]));
//    plane[2] = ((p2[0]-p1[0])*(p3[1]-p1[1]))-
//               ((p2[1]-p1[1])*(p3[0]-p1[0]));
//    plane[3] = -(plane[0]*p1[0] + plane[1]*p1[1] + plane[2]*p1[2]);



    float dot = wall[0] * light[0] +
                wall[1] * light[1] +
                wall[2] * light[2] +
                wall[3] * light[3];

    shadowMatrix[0] = dot - light[0] * wall[0];
    shadowMatrix[4] = 0.0 - light[0] * wall[1];
    shadowMatrix[8] = 0.0 - light[0] * wall[2];
    shadowMatrix[12] = 0.0 - light[0] * wall[3];

    shadowMatrix[1] = 0.0 - light[1] * wall[0];
    shadowMatrix[5] = dot - light[1] * wall[1];
    shadowMatrix[9] = 0.0 - light[1] * wall[2];
    shadowMatrix[13] = 0.0 - light[1] * wall[3];

    shadowMatrix[2] = 0.0 - light[2] * wall[0];
    shadowMatrix[6] = 0.0 - light[2] * wall[1];
    shadowMatrix[10] = dot - light[2] * wall[2];
    shadowMatrix[14] = 0.0 - light[2] * wall[3];

    shadowMatrix[3] = 0.0 - light[3] * wall[0];
    shadowMatrix[7] = 0.0 - light[3] * wall[1];
    shadowMatrix[11] = 0.0 - light[3] * wall[2];
    shadowMatrix[15] = dot - light[3] * wall[3];

    return shadowMatrix;
}

// called every time the widget needs painting
void SceneWidget::paintGL() { // paintGL()
    // clear the widget
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

//    glPushMatrix();
//    glTranslatef(0, 9, 0);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();
//    glPushMatrix();
//    glTranslatef(0, 11, 0);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(3, 9, 0);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(-3, 9, 0);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(0, 9, 3);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();
//    glPushMatrix();
//    glTranslatef(0, 9, -3);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(0, 5, 0);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(0, 2, 0);
//    shapeCreator->createTessCube(100, 1, 1, 10, 10, 10);
//    glPopMatrix();

    glEnable(GL_LIGHT1);
    glDisable(GL_LIGHT0);
    glPushMatrix();
    shapeCreator->walls(50.0, 20.0, 30.0, 50, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(light1Position[0], light1Position[1], light1Position[2]);
//    glRotatef(rotateCube,0,1,0);
//    glTranslatef(3,0,0);
    shapeCreator->createCube(1, 1, 1, 0, 0, 0, false);
    glPopMatrix();

    float shadowMat[16];
    float ground[4] = {0, 0, -1, 15 - 0.01};
    float wall[4] = {0, 0, -1, 15 - 0.01};


//    glm::vec3 p1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
//    glm::vec3 p2 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
//    glm::vec3 p3 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
//    glm::vec3 p4 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};

//    plane[0] = ((p2[1]-p1[1])*(p3[2]-p1[2]))-
//               ((p2[2]-p1[2])*(p3[1]-p1[1]));
//    plane[1] = ((p2[2]-p1[2])*(p3[0]-p1[0]))-
//               ((p2[0]-p1[0])*(p3[2]-p1[2]));
//    plane[2] = ((p2[0]-p1[0])*(p3[1]-p1[1]))-
//               ((p2[1]-p1[1])*(p3[0]-p1[0]));
//    plane[3] = -(plane[0]*p1[0] + plane[1]*p1[1] + plane[2]*p1[2]);

    float dot = ground[0] * light1Position[0] +
                ground[1] * light1Position[1] +
                ground[2] * light1Position[2] +
                ground[3] * light1Position[3];

    shadowMat[0] = dot - light1Position[0] * ground[0];
    shadowMat[4] = 0.0 - light1Position[0] * ground[1];
    shadowMat[8] = 0.0 - light1Position[0] * ground[2];
    shadowMat[12] = 0.0 - light1Position[0] * ground[3];

    shadowMat[1] = 0.0 - light1Position[1] * ground[0];
    shadowMat[5] = dot - light1Position[1] * ground[1];
    shadowMat[9] = 0.0 - light1Position[1] * ground[2];
    shadowMat[13] = 0.0 - light1Position[1] * ground[3];

    shadowMat[2] = 0.0 - light1Position[2] * ground[0];
    shadowMat[6] = 0.0 - light1Position[2] * ground[1];
    shadowMat[10] = dot - light1Position[2] * ground[2];
    shadowMat[14] = 0.0 - light1Position[2] * ground[3];

    shadowMat[3] = 0.0 - light1Position[3] * ground[0];
    shadowMat[7] = 0.0 - light1Position[3] * ground[1];
    shadowMat[11] = 0.0 - light1Position[3] * ground[2];
    shadowMat[15] = dot - light1Position[3] * ground[3];

//    ////Cubes
//    glPushMatrix();
//    glTranslatef(0, 3, 0);
//    glRotatef(rotateCube, 0, 1, 0);
//    shapeCreator->createCube(1, 1, 1, 0, 0, 0, false);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0, 3, 2);
//    glRotatef(rotateCube + M_PI, 0, 1, 0);
//    shapeCreator->createCube(1, 1, 1, 0, 0, 0, false);
//    glPopMatrix();

//    ////Figure
//    glDisable(GL_CULL_FACE);
//    glPushMatrix();
//    glTranslatef(0, 4, 3);
//    shapeCreator->createFigurine();
//    glPopMatrix();
//    glEnable(GL_CULL_FACE);

    ////shadow 2
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND); //Enable blending.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
    float *shadowMatrix;
    wall[3] -= 0.01; // neg z and increase to stop cross blending
    shadowMatrix = getShadowMatrix(wall, light1Position);
    glMultMatrixf(shadowMatrix);
    glTranslatef(0, 3, 2);
    glRotatef(rotateCube, 0, 1, 0);
    shapeCreator->createCube(1, 1, 1, 0, 0, 0, true);
    glEnable(GL_LIGHTING);
    glDisable(GL_BLEND);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);

    ////cube shadow 1
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND); //Enable blending.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
    wall[3] += 0.01;
    shadowMatrix = getShadowMatrix(wall, light1Position);
    glMultMatrixf(shadowMatrix);
    glTranslatef(0, 3, 0);
    glRotatef(rotateCube, 0, 1, 0);
    shapeCreator->createCube(1, 1, 1, 0, 0, 0, true);
    glEnable(GL_LIGHTING);
    glDisable(GL_BLEND);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, shapeCreator->MyTexture[6]);
    glColor3f(1.0, 1.0, 1.0);

    ////Apple PC
    glDisable(GL_CULL_FACE);
//    glDisable(GL_LIGHTING);
    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnableClientState(GL_TEXTURE_COORD_ARRAY_EXT);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY); //enable normal array

    glPushMatrix();
    glTranslatef(0, 3, 4);
    glScalef(1,1,1.2);


    glVertexPointer(3, GL_FLOAT, 0, shapeCreator->vertices3.data());
//    qDebug() << shapeCreator->uvs3[2] << shapeCreator->uvs3[3];
    glTexCoordPointer(2, GL_FLOAT, 0, shapeCreator->uvs3.data());

    glNormalPointer(GL_FLOAT,0, shapeCreator->normals3.data());


    glDrawArrays(GL_TRIANGLES, 0, shapeCreator->vertices3.size() / 3);
//    glDrawElements(GL_TRIANGLES, shapeCreator->vertexIndices.size(), GL_UNSIGNED_INT, shapeCreator->vertexIndices.data());
    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glRotatef(2, 1, 0, 0);
    glTranslatef(-2.1, -0.4, 0.61);
    glScalef(1.8, 1.2, 1);
    shapeCreator->drawTexture(0, 0, 2, 2, 0, 0, 1, 1);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
    glPopMatrix();
    glDisableClientState(GL_VERTEX_ARRAY); //disable the client states again
    glDisableClientState(GL_NORMAL_ARRAY);
//    glDisableClientState(GL_TEXTURE_COORD_ARRAY_EXT);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

//    glEnable(GL_LIGHTING);

    glEnable(GL_CULL_FACE);
    glBindTexture(GL_TEXTURE_2D, 0);
//    glBindTexture(GL_TEXTURE_2D, shapeCreator->MyTexture[1]);
//    glBindTexture(GL_TEXTURE_2D, shapeCreator->MyTexture[0]);





//        glPushMatrix();
//            glPushAttrib(GL_CURRENT_BIT);
//            glLoadIdentity();
//                glRotatef(rotateCube, 0, 1, 0);

//    glMultMatrixf((const GLfloat *) shadowMat);
//    glTranslatef(0,0,1);
//    shapeCreator->createCube(1, 1, 1, 0, 0, 0);
//            glPopAttrib();
//        glPopMatrix();
//    glPopMatrix();


//    myShadowMatrix(float ground[4], float light[4])
//    {
//        float  dot;
//        float  shadowMat[4][4];
//
//
//
//        dot = ground[0] * light[0] +
//              ground[1] * light[1] +
//              ground[2] * light[2] +
//              ground[3] * light[3];
//
//        shadowMat[0][0] = dot - light[0] * ground[0];
//        shadowMat[1][0] = 0.0 - light[0] * ground[1];
//        shadowMat[2][0] = 0.0 - light[0] * ground[2];
//        shadowMat[3][0] = 0.0 - light[0] * ground[3];
//
//        shadowMat[0][1] = 0.0 - light[1] * ground[0];
//        shadowMat[1][1] = dot - light[1] * ground[1];
//        shadowMat[2][1] = 0.0 - light[1] * ground[2];
//        shadowMat[3][1] = 0.0 - light[1] * ground[3];
//
//        shadowMat[0][2] = 0.0 - light[2] * ground[0];
//        shadowMat[1][2] = 0.0 - light[2] * ground[1];
//        shadowMat[2][2] = dot - light[2] * ground[2];
//        shadowMat[3][2] = 0.0 - light[2] * ground[3];
//
//        shadowMat[0][3] = 0.0 - light[3] * ground[0];
//        shadowMat[1][3] = 0.0 - light[3] * ground[1];
//        shadowMat[2][3] = 0.0 - light[3] * ground[2];
//        shadowMat[3][3] = dot - light[3] * ground[3];
//
//        glMultMatrixf((const GLfloat*)shadowMat);
//    }

//    glPushMatrix();
//    glTranslatef(0, 2, 3);
//    glRotatef(rotateCube, 0, 1, 0);
//    shapeCreator->createCube(1, 1, 1, 0, 0, 0);
//
//        // Do the projective stuff
//        glPushMatrix();
//        glPushAttrib(GL_CURRENT_BIT);
//
//        glTranslatef(light1Position[0], light1Position[1], light1Position[2]);
//        glMultMatrixf(shadowMatrix1);
//        glTranslatef(-light1Position[0], -light1Position[1], -light1Position[2]);
//
//
//        glColor3f(0., 0., 0.);
//        shapeCreator->createCube(1, 1, 1, 0, 0, 0);
//        glPopMatrix();
//        glPopAttrib();
//
//    glPopMatrix();

    glDisable(GL_LIGHT1);
    glEnable(GL_LIGHT0);

//    glPushMatrix();
//    glTranslatef(0, 3, -3);
//   shapeCreator->createCube(2, 2, 2, 0, 0, 0);
//    glPopMatrix();

    ////Skybox
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glTranslatef(0, -500, 0);
    shapeCreator->sky(1000.0, 1000.0, 1000.0, 1, 1, 1);
    glPopMatrix();
    glEnable(GL_LIGHTING);

    ////Terrain
//    glPushMatrix();
//    glScaled(1.0 / shapeCreator->planeWidth * 1000, 10, 1.0 / shapeCreator->planeDepth * 1000);
//    glTranslatef(-shapeCreator->planeWidth / 2.0, -10, -shapeCreator->planeDepth / 2.0);
//    shapeCreator->createTessTriPlane(shapeCreator->planeWidth, shapeCreator->planeDepth, shapeCreator->planeXTess,
//                                     shapeCreator->planeZTess);
//    glPopMatrix();

//    shapeCreator->createSphere(3.0, 20, 20);
//    shapeCreator->imageLoader();
//    shapeCreator->drawTextPlane(3,3);
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

//    duration = ( ( clock() - start )/ (double) CLOCKS_PER_SEC) *24;
//    glBitmap(64, 64, 0., 0., 60., 60., shapeCreator->image);
//    glDrawPixels(512,512,GL_RGB, GL_UNSIGNED_BYTE, shapeCreator->image);
//    frame++;

    glLoadIdentity();

    gluLookAt(cameraDirection[0], cameraDirection[1], cameraDirection[2], cameraPosition[0], cameraPosition[1],
              cameraPosition[2], cameraUp[0], cameraUp[1] + 10000000000000, cameraUp[2]);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
    glFlush();
    frame++;
    rotateCube += 0.5;
} // paintGL()
