//#define GL_GLEXT_PROTOTYPES
//#include <GL/glew.h>
#include <GL/glu.h>
#include <QGLWidget>
#include <QtGui>
#include <QtCore/QTime>
#include <cmath>
#include "SceneWidget.h"
#include <glm/glm.hpp>
#include "ShapeCreator.h"
#include "TextureCreator.h"
#include <vector>


// constructor
SceneWidget::SceneWidget(QWidget *parent)
        : QGLWidget(parent) { // constructor
//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()) , SLOT(update()));
//    timer->start(1000);
//
    window = parent;
    double frame = 0;
    shapeCreator = new ShapeCreator(this);
    textureCreator = new TextureCreator(this);
} // constructor

// called when OpenGL context is set up
void SceneWidget::initializeGL() { // initializeGL()
    ////Enable anti-alias
    glEnable(GL_MULTISAMPLE);
    ////Normalize normals upon transformations (especially scaling)
    glEnable(GL_NORMALIZE);
    ////Set Identitity matrix
    glLoadIdentity();
    ////Set Background colour
    glClearColor(0.8, 0.3, 0.3, 0.0);
    ////Access some more GL Functions via QT //TODO ?
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

    ////Material parameters
    glEnable(GL_COLOR_MATERIAL);
//    GLfloat mambient[] = {0.0f, 0.0f, 0.8f, 0.0f};
//    GLfloat mdiff[] = {0.8f, 0.8f, 0.8f, 0.0f};
//    glMaterialfv(GL_FRONT, GL_AMBIENT, mambient);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, mdiff);
    GLfloat mambient[] = {0.0f, 0.0f, 0.8f, 0.0f};
    GLfloat mdiff[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat mspec[] = {1, 1, 1, 1.0f};
//    GLfloat shininess2[] = {100};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mdiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mspec);
//    glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);
    GLfloat shininess2[] = {50};
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);
    GLfloat shininess[] = {100.0};
    GLfloat shininess3[] = {5.0};

    ////Light parameters
    ////Light 0
    GLfloat light_0_ambient[] = {0.3, 0.2, 0.25, 0.0};
    GLfloat light_0_diffuse[] = {1.0, 1.0, 1.0, 0.0};
    GLfloat light_0_specular[] = {1, 1, 1, 0.0};
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
//    GLfloat light_1_specular[] = {1.0, 1.0, 1.0, 0.0};
    GLfloat light_1_specular[] = {1, 1, 1, 0.0};

//    GLfloat light_position[] = {0.0, 5, 0.0, 1.0};
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_1_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
    glLightfv(GL_LIGHT1, GL_SHININESS, shininess);
    glEnable(GL_LIGHT1);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);

    ////Cull back of faces
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    ////Load Apple pc info
    bool loadedPC = shapeCreator->getOBJData("/AppleIIe4.obj", shapeCreator->verticesPC, shapeCreator->uvsPC,
                                             shapeCreator->normalsPC);


    bool loadedGeisha = shapeCreator->getOBJData("/geisha2.obj", shapeCreator->verticesGeisha, shapeCreator->uvsGeisha,
                                                 shapeCreator->normalsGeisha);

    qDebug() << "loaded" << loadedGeisha;

//    glGenFramebuffers(1, &geishaFrameBuffer);
//    glBindFramebuffer(GL_FRAMEBUFFER, geishaFrameBuffer);

//    qDebug() << res;

//    QStringList textureStrings = {
//            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_0_Front+Z.jpg",
//            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_1_Back-Z.jpg",
//            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_2_Left+X.jpg",
//            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_3_Right-X.jpg",
//            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_4_Up+Y.jpg",
//            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_5_Down-Y.jpg",
//            "./textureinternet/appleIIe.jpg",
//            "./textureinternet/mario2.png"
//    };
//
//    QStringList textureStrings2 = {
//            "./textureinternet/mario2.png"
//    };

    glEnable(GL_TEXTURE_2D);

    ////Load textures
//    shapeCreator->imageLoader(textureStrings , textureCreator->MyTextures);
    textureCreator->swapActiveTexture(0);
    textureCreator->imageLoader(textureCreator->textureStrings, textureCreator->textures);

//    glActiveTexture(GL_TEXTURE6 );
//    textureCreator->swapActiveTexture(1);
//    textureCreator->imageLoader(textureCreator->objTextureStrings, textureCreator->objTextures);
//    textureCreator->swapActiveTexture(1);


//    textureCreator->swapActiveTexture(2);
//    textureCreator->imageLoader(textureCreator->fireTextureStrings, textureCreator->fireTextures);
    shapeCreator->textureCreator = textureCreator;
    qDebug() << "loaded Texture!!s";
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
    gluPerspective(this->fov, width / height, 0.01, sqrt(pow(1000, 2) + pow(1000, 2)) + pow(1000, 2));
} // resizeGL()

void SceneWidget::keyPressEvent(QKeyEvent *key) {
    qDebug() << key;
    const float cameraSpeed = 0.1f;
    const float turningSpeed = 0.05f;
    //Keep yaw between -pi/2 and pi/2
    qDebug() << camX;
    if (camX < 0) {
        yaw = (M_PI + yaw);
    }
    if (key->key() == Qt::Key_Q) {
        float newYaw = yaw - M_PI / 2;
        cameraPosition[2] += sin(newYaw) * cameraSpeed;
        cameraDirection[2] += sin(newYaw) * cameraSpeed;
        cameraPosition[0] += cos(newYaw) * cameraSpeed;
        cameraDirection[0] += cos(newYaw) * cameraSpeed;
    }
    if (key->key() == Qt::Key_E) {
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

    if (key->key() == Qt::Key_A) {
        turningNumber += turningSpeed;
    }
    if (key->key() == Qt::Key_D) {
        turningNumber -= turningSpeed;
    }
    camX = sin(turningNumber) * radius;
    camZ = cos(turningNumber) * radius;
    cameraDirection[0] = cameraPosition[0] - camX;
    cameraDirection[2] = cameraPosition[2] - camZ;
    if (camX != 0) {
        yaw = atan(camZ / camX);
    } else {
//        if (camZ == 1) {
//            yaw = M_PI_2;
//        } else {
//            yaw = 3 * M_PI_2;
//        }
    }
    if (key->key() == Qt::Key_R) {
        cameraPosition[1] += 0.2;
        cameraDirection[1] += 0.2;
    }
    if (key->key() == Qt::Key_T) {
        cameraPosition[1] -= 0.2;
        cameraDirection[1] -= 0.2;
    }
    if (key->key() == Qt::Key_F) {
        cameraDirection[1] += 0.2;

    }
    if (key->key() == Qt::Key_G) {
        cameraDirection[1] -= 0.2;
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
//            updateGL();
            jumping = true;
        }
        while (cameraPosition[1] > 5) {

            cameraPosition[1] -= 1.0 / 16;
            cameraDirection[1] -= 1.0 / 16;
//            updateGL();
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
//    updateGL();
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

//TODO if lights dont move call once
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

    shadowMatrix[3] = 0.0 - light[3] * wall[0];
    shadowMatrix[7] = 0.0 - light[3] * wall[1];
    shadowMatrix[11] = 0.0 - light[3] * wall[2];
    shadowMatrix[15] = dot - light[3] * wall[3];

    return shadowMatrix;
}

void SceneWidget::placeTerrain() {
    glPushMatrix();
    glScaled(1.0 / shapeCreator->planeWidth * 1000, 10, 1.0 / shapeCreator->planeDepth * 1000);
    glTranslatef(-shapeCreator->planeWidth / 2.0, -10, -shapeCreator->planeDepth / 2.0);
    shapeCreator->createTessTriPlane(shapeCreator->planeWidth, shapeCreator->planeDepth, shapeCreator->planeXTess,
                                     shapeCreator->planeZTess);
    glPopMatrix();
}

void SceneWidget::updateFrameActions() {
    ////Rotation variable of cubes
    rotateCube += 0.5;
    shapeCreator->gimbal1Turning += M_PI_2;
    shapeCreator->gimbal2Turning += 1;
    shapeCreator->gyroTurning += 1.618033988749895 * 2;
    shapeCreator->turnTableRotation += turnTableRotationSpeed;
    geishaPosition[2] -= 0.0001;
    geishaRotation += 1;
    ////Update frame number
    frame++;
    if (frame == ULLONG_MAX) {
        frame = 0;
    }

}

void SceneWidget::changeScreenTexture(int i) {
    qDebug() << "you are connected" << i;
    if (i == 0){
        textureCreator->selectedIndex=textureCreator->skyBoxZPlusIndex;
    }
    if (i ==1){
        textureCreator->selectedIndex=textureCreator->marcIndex;
    }
    if (i==2){
        textureCreator->selectedIndex=textureCreator->mapIndex;
    }
}

unsigned long long SceneWidget::getFrameRate() {
//    QTime currentTime = QTime::currentTime();
//    QTime duration = currentTime - startTime;

    frameDifference = frame - lastFrameRecorded;
    qDebug() << frame << lastFrameRecorded;
    lastFrameRecorded = frame;
    qDebug() << QTime::currentTime();
    qDebug() << frameDifference << "fps";

//    this->parentWidget()->

    return frameDifference;
}

void SceneWidget::drawPC() {
    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[6 - 1 + 1]);
    glColor3f(1.0, 1.0, 1.0);
    glColor4f(1.0, 1.0, 1.0, 1.0);
    ////Apple PC
    glDisable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY); //enable normal array
    glPushMatrix();
    glTranslatef(5, 3, -4);
    glScalef(1, 1, 1.2);

    glVertexPointer(3, GL_FLOAT, 0, shapeCreator->verticesPC.data());
    glTexCoordPointer(2, GL_FLOAT, 0, shapeCreator->uvsPC.data());
    glNormalPointer(GL_FLOAT, 0, shapeCreator->normalsPC.data());
    glDrawArrays(GL_TRIANGLES, 0, shapeCreator->verticesPC.size() / 3);
//    glDrawElements(GL_TRIANGLES, shapeCreator->vertexIndices.size(), GL_UNSIGNED_INT, shapeCreator->vertexIndices.data());


    ////PC Screen
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glRotatef(-2, 1, 0, 0);
    glTranslatef(-1.33, -0.4, -0.62);
    glScalef(1.8, 1.2, 1);
    shapeCreator->drawTexture(0, 0, 2, 2, 0, 0, 1, 1, true, textureCreator->textures[textureCreator->selectedIndex]);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
    glPopMatrix();
    glDisableClientState(GL_VERTEX_ARRAY); //disable the client states again
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
}

void SceneWidget::testLight() {
    ////Lighting testcubes
//    glEnable(GL_LIGHT1);
//    glDisable(GL_LIGHT0);
//    glPushMatrix();
//    glTranslatef(0, 9, 0);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();
//    glPushMatrix();
//    glTranslatef(0, 11, 0);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(3, 9, 0);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(-3, 9, 0);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0, 9, 3);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();
//    glPushMatrix();
//    glTranslatef(0, 9, -3);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0, 5, 0);
//    shapeCreator->createTessCube(1, 1, 1, 10, 10, 10);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(0, 2, 0);
//    shapeCreator->createTessCube(100, 1, 1, 10, 10, 10);
//    glPopMatrix();
}

void SceneWidget::drawShadows() {
    float wall[4] = {0, 0, -1, (roomDepth/2) - 0.2};

    //    ////shadow 2
//    glPushMatrix();
//    glDisable(GL_LIGHTING);
//    glEnable(GL_BLEND); //Enable blending.
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
//    float *shadowMatrix;
//    wall[3] -= 0; // neg z and increase to stop cross blending
//    shadowMatrix = getShadowMatrix(wall, light1Position);
//    glMultMatrixf(shadowMatrix);
//    glTranslatef(0, 3, 2);
//    glRotatef(rotateCube, 0, 1, 0);
//    shapeCreator->createCube(1, 1, 1, 0, 0, 0, true);
//    glEnable(GL_LIGHTING);
//    glDisable(GL_BLEND);
//    glPopMatrix();
//    glEnable(GL_DEPTH_TEST);
//
//    ////cube shadow 1
//    glPushMatrix();
//    glDisable(GL_LIGHTING);
//    glEnable(GL_BLEND); //Enable blending.
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
//    wall[3] += 0.01;
//    shadowMatrix = getShadowMatrix(wall, light1Position);
//    glMultMatrixf(shadowMatrix);
//    glTranslatef(0, 3, 0);
//    glRotatef(rotateCube, 0, 1, 0);
//    shapeCreator->createCube(1, 1, 1, 0, 0, 0, true);
    glDisable(GL_LIGHTING);
//    glPopMatrix();

    glColor3f(0, 0, 0);
    glColor4f(0, 0, 0, 1);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
    ////Geisha shadow
//    glEnable(GL_BLEND);
//    glBindTexture(GL_TEXTURE_2D, textureCreator->MyTextures[8]);
//    glDisable(GL_CULL_FACE);
//    glDisable(GL_DEPTH_TEST);
//    glDepthFunc(GL_GEQUAL);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY); //enable normal array
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPushMatrix();
    wall[3] += 0.02;
    float *shadowMatrix = getShadowMatrix(wall, light1Position);
    glMultMatrixf(shadowMatrix);
    drawGeisha(true);
    glPopMatrix();
    glEnable(GL_LIGHTING);

//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LESS);
//    glDisable(GL_BLEND);
}

void SceneWidget::drawGeisha(bool black) {
    glPushMatrix();
    glTranslatef(geishaPosition[0],geishaPosition[1],geishaPosition[2]);
    glRotatef(geishaRotation,0,1,0);
    shapeCreator->createStickGeisha(black);
    glPopMatrix();
}

void SceneWidget::drawFire() {
    glDisable(GL_LIGHTING);
    glDisable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
    glPushMatrix();
    int fireNum = frame % 20 + (6 + 3);
    float fireWidth = 10;
    float fireHeight = 20;

    glPushMatrix();
    glTranslatef(light1Position[0] - fireWidth / 2, -fireHeight / 8, light1Position[2]);
    shapeCreator->drawTexture(0, 0, fireWidth, fireHeight, 0, 0, 1, 1, true, textureCreator->textures[fireNum]);
    glPopMatrix();

    ////Second fire
//    glPushMatrix();
//    glTranslatef(light1Position[0] - fireWidth/2 , -fireHeight/8, light1Position[2]);
//    glRotatef(90, 0, 1, 0);
//    glTranslatef(-5, 0, 5);
//    shapeCreator->drawTexture(0, 0, fireWidth, fireHeight, 0, 0, 1, 1, true, textureCreator->textures[fireNum]);
//    glPopMatrix();

    glPopMatrix();
    glDisable(GL_BLEND);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
}

// called every time the widget needs painting
void SceneWidget::paintGL() { // paintGL()
    ////Clear screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    ////Z Depth test
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    ////Inside
    glDisable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

//    shapeCreator->drawTexture(0,0,30,30,0,0,1,1,0,textureCreator->textures[29]);

    glPushMatrix();
    shapeCreator->walls(roomWidth, roomHeight, roomDepth, 50, 50, 50);
    glPopMatrix();


    ////light 1 cube
    glPushMatrix();
    glTranslatef(light1Position[0], light1Position[1], light1Position[2]);
    shapeCreator->createCube(1, 1, 1, 0, 0, 0, false);
    glPopMatrix();


    ////Spinning Cubes
    glPushMatrix();
    glTranslatef(0, 3, 0);
    glRotatef(rotateCube, 0, 1, 0);
    shapeCreator->createCube(1, 1, 1, 0, 0, 0, false);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 3, 2);
    glRotatef(rotateCube + M_PI, 0, 1, 0);
    shapeCreator->createCube(1, 1, 1, 0, 0, 0, false);
    glPopMatrix();


    drawShadows();

    ////Semicylinder
//    shapeCreator->createSemiCylinder(5,5,3,3,3);

    glBindTexture(GL_TEXTURE_2D, 0);

    ////Draw PC
//    drawPC();

    ////Draw Geisha
//    drawGeisha();
    glPushMatrix();
//    glTranslatef(geishaPosition[0],geishaPosition[1],geishaPosition[2]);
//    shapeCreator->createStickGeisha(false);
    drawGeisha(false);
    glPopMatrix();
    ///Draw Gyro
//    glPushMatrix();
//    glDisable(GL_CULL_FACE);
//    glTranslatef(2, 5, 0);
//    glRotatef(shapeCreator->gyroTurning, 0, 1, 0);
//    glTranslatef(2, 0, 0);
//    glScalef(0.2, 0.2, 0.2);
//    shapeCreator->createGyro();
//    glEnable(GL_CULL_FACE);
//    glPopMatrix();




////TODO LIGGHT2
    glPushMatrix();
    glTranslatef(roomWidth/2,0,0);
    glPushMatrix();
    glTranslatef(20,0,20);
    glRotatef(180,0,1,0);
    ////Draw desk
    shapeCreator->createPopulatedDesk();
    glPopMatrix();
    shapeCreator->createTunnel(roomWidth,roomHeight,roomDepth+10,50,50,50);
    glPopMatrix();



//    textureCreator->swapActiveTexture(0);
    ////Outside
    ////Skybox
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glTranslatef(0, -500, 0);
    shapeCreator->sky(1000.0, 1000.0, 1000.0, 1, 1, 1);
    glPopMatrix();


    glEnable(GL_LIGHTING);
    glDisable(GL_LIGHT1);
    glEnable(GL_LIGHT0);
    glBindTexture(GL_TEXTURE_2D, 0);
    ////Terrain
    placeTerrain();


    ////Inside
    /// Draw Fire (LAST!!!)
    for (float i = 0; i < 10; i++) {
        glPushMatrix();
        glTranslatef(0, 0, (i) / 10);
//        glScalef(1/i,1/i,1/i);
        drawFire();
        glPopMatrix();
    }
    ////Draw image pixels
//    glDrawPixels(textureCreator->pQImage[30].width(),textureCreator->pQImage[30].height(),GL_RGB, GL_UNSIGNED_BYTE, textureCreator->pQImage[30].bits());

    glLoadIdentity();
    gluLookAt(cameraDirection[0], cameraDirection[1], cameraDirection[2], cameraPosition[0], cameraPosition[1],
              cameraPosition[2], cameraUp[0], cameraUp[1] + 10000000000000, cameraUp[2]);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glLightfv(GL_LIGHT1, GL_POSITION, light1Position);



    glFlush();
    updateFrameActions();
} // paintGL()
