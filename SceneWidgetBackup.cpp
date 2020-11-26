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
//    clock_t start = clock() ;


} // constructor

// called when OpenGL context is set up
void SceneWidget::initializeGL() { // initializeGL()
    // set the widget background colour
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_NORMALIZE);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glClearColor(0.8, 0.3, 0.3, 0.0);
//    float fog_colour[4] = {1, 1, 1, 1};
//
////    glEnable(GL_FOG);
////    glFogf(GL_FOG_MODE,GL_EXP2);
////    glFogfv(GL_FOG_COLOR,fog_colour);
////    glFogf(GL_FOG_DENSITY,0.05);
////    glHint(GL_FOG_HINT,GL_NICEST);
////    glFogf(GL_FOG_START,10);
////    glFogf(GL_FOG_END,100);
//
//    GLfloat ambient[] = {0.10, 0.10, 0.10, 1};// {1.0, 10.0, 1.0, 0.0};
//    GLfloat diff[] = {1, 0.11, 0.11, 1.0};// {1.0, 10.0, 1.0, 0.0};
//    GLfloat diff2[] = {0.01, 0.1, 0.1, 1.0};//{1, 1, 1, 0.0};// {1.0, 10.0, 1.0, 0.0};
//    GLfloat specular[] = {1, 1, 1, 1.0};
//    GLfloat shininess[] = {10.0};
//    glShadeModel(GL_SMOOTH);
//    GLfloat lightpos[] = {0, 10, 0, 0.0};
//    GLfloat lightpos2[] = {1, 1, 0};
//    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
//    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
//    glLightfv(GL_LIGHT0, GL_SHININESS, shininess);
//    GLfloat globAmb[] = {0.2,0.2,0.2,1};
//    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);
////    glLightfv(GL_LIGHT0, GL_SHININESS, shininess);
////    glLightfv(GL_LIGHT1, GL_DIFFUSE, diff2);
//    // enable lighting
//    // enable lighting for front
//    glLightModeli( GL_FRONT, GL_TRUE );
//    // material have diffuse and ambient lighting
////    glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
//
////    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
////    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//    GLfloat cyan[] = {1.0f, .8f, .8f, 1.f};
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
////    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    // enable color
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//    // enable light 0
//    glEnable(GL_COLOR_MATERIAL);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
////    glEnable(GL_LIGHT1);
////    GLfloat mat_shin[] = {1000};
////    GLfloat mat_emiss[] = {0.1, 0, 0, 1};
////    GLfloat mat_specular[] = {0.11, 0.1, 0.1, 1};
////    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
////    glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
////    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emiss);
////    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
////    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shin);
    GLfloat mambient[] = {0.0f, 0.0f, 0.8f, 0.0f};
    GLfloat mdiff[] = {0.8f, 0.8f, 0.8f, 0.0f};
    glLoadIdentity();
    GLfloat mspec[] = {0.f, .8f, .8f, 0.0f};
    GLfloat shininess2[] = {50};
    glEnable(GL_COLOR_MATERIAL);
//    glMaterialfv(GL_FRONT, GL_AMBIENT, mambient);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, mdiff);
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
//    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

} // initializeGL()

// called every time the widget is resized
void SceneWidget::resizeGL(int w, int h) { // resizeGL()
    // set the viewport to the entire widget
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
    float width = w;
    float height = h;
    gluPerspective(90, -width / height, 0.01, sqrt(pow(30, 2) + pow(10, 2)) + pow(20, 2));
} // resizeGL()


void SceneWidget::walls(float width, float height, float depth, int tessX, int tessY, int tessZ) {
////   North Wall White
    //Coordinates
    glm::vec3 v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v4 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v3 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    glm::vec3 v2 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    //Normal of rect
    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //tessellate amount
//    float tessX = 10;
//    float tessY = 100;
    float tessXSize = abs(v1[0] - v3[0]) / (tessX);
    float tessYSize = abs(v1[1] - v3[1]) / (tessY);
    glColor3f(1.0, 1.0, 1.0);
    for (float i = v1[0]; i < v3[0]; i += tessXSize) {
        for (float j = v1[1]; j < v3[1]; j += tessYSize) {
            glBegin(GL_POLYGON);
            glVertex3f(i, j, v1[2]);
            glVertex3f(i + tessXSize, j, v2[2]);
            glVertex3f(i + tessXSize, j + tessYSize, v3[2]);
            glVertex3f(i, j + tessYSize, v4[2]);
            glEnd();
        }
    }
//    //North Wall White
//    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_POLYGON);
////    glNormal3f(0, 0, -1);
//    glNormal3fv(glm::value_ptr(normal));
//    glVertex3f(v1[0],v1[1],v1[2]);//1
//    glVertex3f(v2[0],v2[1],v2[2]);//1
//    glVertex3f(v3[0],v3[1],v3[2]);//1
//    glVertex3f(v4[0],v4[1],v4[2]);//1
//    glEnd();
    glColor3f(1.0, 1.0, 1.0);

//    glBegin(GL_POLYGON);
////    glNormal3f(0, 0, -1);
//    glNormal3fv(glm::value_ptr(normal));
//    glVertex3f(v1[0], v1[1], v1[2] - 0.001);//1
//    glVertex3f(v2[0], v2[1] / 2, v2[2] - 0.001);//1
//    glVertex3f(0, v3[1] / 2, v3[2] - 0.001);//1
//    glVertex3f(0, v4[1], v4[2] - 0.001);//1
//    glEnd();
//    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_POLYGON);
////    glNormal3f(0, 0, -1);
//    glNormal3fv(glm::value_ptr(normal));
//    glVertex3f(v1[0], v2[1] / 2, v1[2] - 0.001);//1
//    glVertex3f(v2[0], v2[1], v2[2] - 0.001);//1
//    glVertex3f(0, v3[1], v3[2] - 0.001);//1
//    glVertex3f(0, v2[1] / 2, v4[2] - 0.001);//1
//    glEnd();
//    glBegin(GL_POLYGON);
////    glNormal3f(0, 0, -1);
//    glNormal3fv(glm::value_ptr(normal));
//    glVertex3f(0, v1[1], v1[2] - 0.001);//1
//    glVertex3f(0, v2[1] / 2, v2[2] - 0.001);//1
//    glVertex3f(v3[0], v3[1] / 2, v3[2] - 0.001);//1
//    glVertex3f(v3[0], v4[1], v4[2] - 0.001);//1
//    glEnd();
//    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_POLYGON);
////    glNormal3f(0, 0, -1);
//    glNormal3fv(glm::value_ptr(normal));
//    glVertex3f(0, v2[1] / 2, v1[2] - 0.001);//1
//    glVertex3f(0, v2[1], v2[2] - 0.001);//1
//    glVertex3f(v3[0], v3[1], v3[2] - 0.001);//1
//    glVertex3f(v3[0], v2[1] / 2, v4[2] - 0.001);//1
//    glEnd();



//    glColor3f(0, 0, 0);
//    glBegin(GL_POLYGON);
//    glVertex3f(0 * size, 0.0 * size, 1.0 * size + 1);
//    glVertex3f(1.0 * size, 0.0 * size, 1.0 * size - 1);
//    glVertex3f(1.0 * size, 2.0 * size, 1.0 * size - 1);
//    glVertex3f(0 * size, 2.0 * size, 1.0 * size + 1);
//    glEnd();
//    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    //East Wall Red
    glColor3f(1.0, 0.0, 0.0);
    //Coordinates
    v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v4 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //tessellate amount
//    tessY = 100;
//    float tessZ = 10;
    tessYSize = abs(v1[1] - v3[1]) / (tessY);
    float tessZSize = abs(v1[1] - v3[1]) / (tessZ);
    for (float j = v1[1]; j < v3[1]; j += tessYSize) {
        for (float k = v3[2]; k < v1[2]; k += tessZSize) {
            glBegin(GL_POLYGON);
            glVertex3f(v1[0], j, k);
            glVertex3f(v2[0], j + tessYSize, k);
            glVertex3f(v3[0], j + tessYSize, k + tessZSize);
            glVertex3f(v4[0], j, k + tessZSize);
            glEnd();
        }
    }
    //South Wall Green
    glColor3f(0.0, 1.0, 0.0);
//    glBegin(GL_POLYGON);
//    glNormal3f(0, 0, 1);
//
//    glVertex3f(-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2);
//    glVertex3f(-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2);
//    glVertex3f(1.0 * width / 2, 1.0 * height, -1.0 * depth / 2);
//    glVertex3f(1.0 * width / 2, 0.0 * height, -1.0 * depth / 2);
//    glEnd();

    //Coordinates
    v1 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v2 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //tessellate amount
//    tessX = 10;
//    tessY = 100;
    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessYSize = abs(v1[1] - v3[1]) / (tessY);
    for (float i = v1[0]; i < v3[0]; i += tessXSize) {
        for (float j = v1[1]; j < v3[1]; j += tessYSize) {
            glBegin(GL_POLYGON);
            glVertex3f(i, j, v1[2]);
            glVertex3f(i + tessXSize, j, v2[2]);
            glVertex3f(i + tessXSize, j + tessYSize, v3[2]);
            glVertex3f(i, j + tessYSize, v4[2]);
            glEnd();
        }
    }
//test
    //West Wall Blue
    glColor3f(0.0, 0.0, 1.0);
    //Coordinates
    v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //tessellate amount
//    tessY = 100;
//    tessZ = 10;
    tessYSize = abs(v1[1] - v3[1]) / (tessY);
    tessZSize = abs(v1[1] - v3[1]) / (tessZ);
    for (float j = v1[1]; j < v3[1]; j += tessYSize) {
        for (float k = v3[2]; k < v1[2]; k += tessZSize) {
            glBegin(GL_POLYGON);
            glVertex3f(v1[0], j, k);
            glVertex3f(v2[0], j + tessYSize, k);
            glVertex3f(v3[0], j + tessYSize, k + tessZSize);
            glVertex3f(v4[0], j, k + tessZSize);
            glEnd();
        }
    }

    //Purple Ceil
    glColor3f(1.0, 0.0, 1.0);
//    glBegin(GL_POLYGON);
//    glNormal3f(0, -1, 0);
//
//    glVertex3f(1.0 * width / 2, 1.0 * height, 1.0 * depth / 2);
//    glVertex3f(1.0 * width / 2, 1.0 * height, -1.0 * depth / 2);
//    glVertex3f(-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2);
//    glVertex3f(-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2);
//    glEnd();

    v1 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v4 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //tessellate amount
//    tessX = 100;
//    tessZ = 10;
    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    for (float i = v3[0]; i < v1[0]; i += tessXSize) {
        for (float k = v3[2]; k < v1[2]; k += tessZSize) {
            glBegin(GL_POLYGON);
            glVertex3f(i + tessXSize, v1[1], k + tessZSize);
            glVertex3f(i + tessXSize, v2[1], k);
            glVertex3f(i, v3[1], k);
            glVertex3f(i, v4[1], k + tessZSize);
            glEnd();
        }
    }

    //Yellow floor
    glColor3f(1.0, 1.0, 0.0);
//    glBegin(GL_POLYGON);
//    glNormal3f(0, 1, 0);
//
//    glVertex3f(1.0 * width / 2, 0.0 * height, 1.0 * depth / 2);
//    glVertex3f(1.0 * width / 2, 0.0 * height, -1.0 * depth / 2);
//    glVertex3f(-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2);
//    glVertex3f(-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2);
//    glEnd();
    v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //tessellate amount
//    tessX = 100;
//    tessZ = 10;
    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    for (float i = v3[0]; i < v1[0]; i += tessXSize) {
        for (float k = v3[2]; k < v1[2]; k += tessZSize) {
            glBegin(GL_POLYGON);
            glVertex3f(i + tessXSize, v1[1], k + tessZSize);
            glVertex3f(i + tessXSize, v2[1], k);
            glVertex3f(i, v3[1], k);
            glVertex3f(i, v4[1], k + tessZSize);
            glEnd();
        }
    }
}


void SceneWidget::createTessCube(float width, float height, float depth, int tessX, int tessY, int tessZ) {

////   North Wall White
    //Coordinates
    glm::vec3 v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v2 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v3 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    glm::vec3 v4 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    //Normal of rect
    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //tessellate amount
//    float tessX = 10;
//    float tessY = 100;
    float tessXSize = abs(v1[0] - v3[0]) / (tessX);
    float tessYSize = abs(v1[1] - v3[1]) / (tessY);
    glColor3f(1.0, 1.0, 1.0);
    for (float i = v1[0]; i < v3[0] - tessXSize; i += tessXSize) {
        for (float j = v1[1]; j < v3[1]; j += tessYSize) {
            glBegin(GL_POLYGON);
            glVertex3f(i, j, v1[2]);
            glVertex3f(i + tessXSize, j, v2[2]);
            glVertex3f(i + tessXSize, j + tessYSize, v3[2]);
            glVertex3f(i, j + tessYSize, v4[2]);
            glEnd();
        }
    }
//    //North Wall White
//    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_POLYGON);
////    glNormal3f(0, 0, -1);
//    glNormal3fv(glm::value_ptr(normal));
//    glVertex3f(v1[0],v1[1],v1[2]);//1
//    glVertex3f(v2[0],v2[1],v2[2]);//1
//    glVertex3f(v3[0],v3[1],v3[2]);//1
//    glVertex3f(v4[0],v4[1],v4[2]);//1
//    glEnd();
    glColor3f(1.0, 1.0, 1.0);

//    glBegin(GL_POLYGON);
////    glNormal3f(0, 0, -1);
//    glNormal3fv(glm::value_ptr(normal));
//    glVertex3f(v1[0], v1[1], v1[2] - 0.001);//1
//    glVertex3f(v2[0], v2[1] / 2, v2[2] - 0.001);//1
//    glVertex3f(0, v3[1] / 2, v3[2] - 0.001);//1
//    glVertex3f(0, v4[1], v4[2] - 0.001);//1
//    glEnd();
//    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_POLYGON);
////    glNormal3f(0, 0, -1);
//    glNormal3fv(glm::value_ptr(normal));
//    glVertex3f(v1[0], v2[1] / 2, v1[2] - 0.001);//1
//    glVertex3f(v2[0], v2[1], v2[2] - 0.001);//1
//    glVertex3f(0, v3[1], v3[2] - 0.001);//1
//    glVertex3f(0, v2[1] / 2, v4[2] - 0.001);//1
//    glEnd();
//    glBegin(GL_POLYGON);
////    glNormal3f(0, 0, -1);
//    glNormal3fv(glm::value_ptr(normal));
//    glVertex3f(0, v1[1], v1[2] - 0.001);//1
//    glVertex3f(0, v2[1] / 2, v2[2] - 0.001);//1
//    glVertex3f(v3[0], v3[1] / 2, v3[2] - 0.001);//1
//    glVertex3f(v3[0], v4[1], v4[2] - 0.001);//1
//    glEnd();
//    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_POLYGON);
////    glNormal3f(0, 0, -1);
//    glNormal3fv(glm::value_ptr(normal));
//    glVertex3f(0, v2[1] / 2, v1[2] - 0.001);//1
//    glVertex3f(0, v2[1], v2[2] - 0.001);//1
//    glVertex3f(v3[0], v3[1], v3[2] - 0.001);//1
//    glVertex3f(v3[0], v2[1] / 2, v4[2] - 0.001);//1
//    glEnd();



//    glColor3f(0, 0, 0);
//    glBegin(GL_POLYGON);
//    glVertex3f(0 * size, 0.0 * size, 1.0 * size + 1);
//    glVertex3f(1.0 * size, 0.0 * size, 1.0 * size - 1);
//    glVertex3f(1.0 * size, 2.0 * size, 1.0 * size - 1);
//    glVertex3f(0 * size, 2.0 * size, 1.0 * size + 1);
//    glEnd();
//    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    //East Wall Red
    glColor3f(1.0, 0.0, 0.0);
    //Coordinates
    v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v4 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //tessellate amount
//    tessY = 100;
//    float tessZ = 10;
    tessYSize = abs(v1[1] - v3[1]) / (tessY);
    float tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    for (float k = v3[2]; k < v1[2] - tessZSize; k += tessZSize) {

        for (float j = v1[1]; j < v3[1]; j += tessYSize) {
            glBegin(GL_POLYGON);
            glVertex3f(v1[0], j, k);
            glVertex3f(v2[0], j + tessYSize, k);
            glVertex3f(v3[0], j + tessYSize, k + tessZSize);
            glVertex3f(v4[0], j, k + tessZSize);
            glEnd();
        }
    }
    //South Wall Green
    glColor3f(0.0, 1.0, 0.0);
//    glBegin(GL_POLYGON);
//    glNormal3f(0, 0, 1);
//
//    glVertex3f(-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2);
//    glVertex3f(-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2);
//    glVertex3f(1.0 * width / 2, 1.0 * height, -1.0 * depth / 2);
//    glVertex3f(1.0 * width / 2, 0.0 * height, -1.0 * depth / 2);
//    glEnd();

    //Coordinates
    v1 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v4 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //tessellate amount
//    tessX = 10;
//    tessY = 100;
    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessYSize = abs(v1[1] - v3[1]) / (tessY);
    for (float i = v1[0]; i < v3[0] - tessXSize; i += tessXSize) {
        for (float j = v1[1]; j < v3[1]; j += tessYSize) {
            glBegin(GL_POLYGON);
            glVertex3f(i, j, v1[2]);
            glVertex3f(i + tessXSize, j, v2[2]);
            glVertex3f(i + tessXSize, j + tessYSize, v3[2]);
            glVertex3f(i, j + tessYSize, v4[2]);
            glEnd();
        }
    }
//test
    //West Wall Blue
    glColor3f(0.0, 0.0, 1.0);
    //Coordinates
    v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //tessellate amount
//    tessY = 100;
//    tessZ = 10;
    tessYSize = abs(v1[1] - v3[1]) / (tessY);
    tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    for (float k = v3[2]; k < v1[2] - tessZSize; k += tessZSize) {

        for (float j = v1[1]; j < v3[1]; j += tessYSize) {
            glBegin(GL_POLYGON);
            glVertex3f(v1[0], j, k);
            glVertex3f(v2[0], j + tessYSize, k);
            glVertex3f(v3[0], j + tessYSize, k + tessZSize);
            glVertex3f(v4[0], j, k + tessZSize);
            glEnd();
        }
    }

    //Purple Ceil
    glColor3f(1.0, 0.0, 1.0);
//    glBegin(GL_POLYGON);
//    glNormal3f(0, -1, 0);
//
//    glVertex3f(1.0 * width / 2, 1.0 * height, 1.0 * depth / 2);
//    glVertex3f(1.0 * width / 2, 1.0 * height, -1.0 * depth / 2);
//    glVertex3f(-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2);
//    glVertex3f(-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2);
//    glEnd();

    v1 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v2 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //tessellate amount
//    tessX = 100;
//    tessZ = 10;
    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    for (float i = v3[0]; i < v1[0] - tessXSize; i += tessXSize) {
        for (float k = v3[2]; k < v1[2] -tessZSize; k += tessZSize) {
            glBegin(GL_POLYGON);
            glVertex3f(i + tessXSize, v1[1], k + tessZSize);
            glVertex3f(i + tessXSize, v2[1], k);
            glVertex3f(i, v3[1], k);
            glVertex3f(i, v4[1], k + tessZSize);
            glEnd();
        }
    }

    //Yellow floor
    glColor3f(1.0, 1.0, 0.0);
//    glBegin(GL_POLYGON);
//    glNormal3f(0, 1, 0);
//
//    glVertex3f(1.0 * width / 2, 0.0 * height, 1.0 * depth / 2);
//    glVertex3f(1.0 * width / 2, 0.0 * height, -1.0 * depth / 2);
//    glVertex3f(-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2);
//    glVertex3f(-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2);
//    glEnd();
    v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v4 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //tessellate amount
//    tessX = 100;
//    tessZ = 10;
    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    for (float i = v3[0]; i < v1[0] - tessXSize; i += tessXSize) {
        for (float k = v3[2]; k < v1[2] -tessZSize; k += tessZSize) {
            glBegin(GL_POLYGON);
            glVertex3f(i + tessXSize, v1[1], k + tessZSize);
            glVertex3f(i + tessXSize, v2[1], k);
            glVertex3f(i, v3[1], k);
            glVertex3f(i, v4[1], k + tessZSize);
            glEnd();
        }
    }
}

void SceneWidget::createCube(float w, float h, float d, float x, float y, float z) {
    //North Wall White
    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_POLYGON);
//
//    for (float i = -1.0 * w / 2 + x; i < 1.0 * w / 2 + x -  1.0 / (w * 10); i += 1.0 / (w * 10)) {
//        for (float j = 0.0 * h + y; j < 1.0 * h + y; j += 1.0 / (h * 10)) {
//            glVertex3f(i,                          j,                  1.0 * d / 2 + z);
//            glVertex3f(i + 1.0 / (w * 10),      j,                  1.0 * d / 2 + z);
//            glVertex3f(i + 1.0 / (w * 10),   j + 1.0 / (h * 10), 1.0 * d / 2 + z);
//            glVertex3f(i,                       j + 1.0 / (h * 10), 1.0 * d / 2 + z);
//
//        }
//    }
//    glEnd();
    glBegin(GL_POLYGON);
    glNormal3f(0, 0, 1);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glEnd();
//    glColor3f(1.0, 1.0, 1.0);

//    double xyz1[3] = {-1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z};
//    double xyz2[3] = {1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z};
//    double xyz3[3] = {1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z};
//    double xyz4[3] = {-1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z};
//    GLUtesselator* tObj = gluNewTess();
//    gluTessBeginPolygon(tObj, nullptr);
//    gluTessBeginContour(tObj);
//    gluTessVertex(tObj, xyz1,xyz1);
//    gluTessVertex(tObj, xyz2,xyz2);
//    gluTessVertex(tObj, xyz3,xyz3);
//    gluTessVertex(tObj, xyz4,xyz4);
//    gluTessVertex(tObj, xyz1,xyz1);
//    gluTessEndContour(tObj);
//    gluTessEndPolygon(tObj);
//    gluDeleteTess(tObj);

    //East Wall
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glNormal3f(1, 0, 0);


    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glEnd();

    //South Wall Green
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glNormal3f(0, 0, -1);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glEnd();

    //West Wall Blue
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glNormal3f(-1, 0, 0);

    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glEnd();

    //Purple Ceil
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glNormal3f(0, 1, 0);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glEnd();

    //Yellow floor
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, 0);

    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glEnd();

}


void SceneWidget::createSphere(GLdouble radius, GLint slices, GLint stacks) {
    GLUquadric *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluSphere(quadric, radius, slices, stacks);
}

void SceneWidget::createSemiCylinder(float rad, float length, int tessX, int tessY, int tessZ) {
    int numberOfSide = 100;
    float interiorAngle = (numberOfSide - 2) * (180.0 / numberOfSide);
    float interiorAngleRad = interiorAngle * (M_PI / 180.0);
    glColor3f(1.0, 0.0, 0.0);
    //Coordinates

    glm::vec3 v1 = {-1.0, 2.0, 1.0};
    glm::vec3 v2 = {-1.0, 0.0, 1.0};
    glm::vec3 v3 = {1.0, 0.0, 1.0};
    glm::vec3 v4 = {1.0, 2.0, 1.0};
    for (int j = 0; j < length; j++) {
//        float r =  static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
//        float g =  static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
//        float b =  static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
//        float g = rand();
//        float b = rand();
//        glColor3f(r, g, b);


        glm::vec3 v1 = {0 + (j), 1.0, 1.0};
        glm::vec3 v2 = {0 + (j), 0.0, 1.0};
        glm::vec3 v3 = {1.0 + (j), 0.0, 1.0};
        glm::vec3 v4 = {1.0 + (j), 1.0, 1.0};


        for (int i = 0; i < numberOfSide / 2 + 1; i++) {
            glm::vec3 lastv1 = v1;
            glm::vec3 lastv2 = v2;
            glm::vec3 lastv3 = v3;
            glm::vec3 lastv4 = v4;

            glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
            if (i % 2 == 0) {
                normal = -normal;
            }
            glNormal3fv(glm::value_ptr(normal));
            glBegin(GL_POLYGON);
            glVertex3f(v1[0], v1[1], v1[2]);
            glVertex3f(v2[0], v2[1], v2[2]);
            glVertex3f(v3[0], v3[1], v3[2]);
            glVertex3f(v4[0], v4[1], v4[2]);
            glEnd();

            glm::mat4 xrotationMat(1); // Creates a identity matrix
            xrotationMat = glm::rotate(xrotationMat, interiorAngleRad, glm::vec3({1, 0, 0}));

            v1 = glm::vec3(xrotationMat * glm::vec4(v1, 1.0));
            v2 = glm::vec3(xrotationMat * glm::vec4(v2, 1.0));
            v3 = glm::vec3(xrotationMat * glm::vec4(v3, 1.0));
            v4 = glm::vec3(xrotationMat * glm::vec4(v4, 1.0));

//            if (i != 0 && j >= 1) {
            glm::mat4 transform(1);
            if (i % 2 == 1) {
                transform = glm::translate(transform, lastv2 - v2);
            } else {
                transform = glm::translate(transform, lastv1 - v1);
            }


            v1 = glm::vec3(transform * glm::vec4(v1, 1.0));
            v2 = glm::vec3(transform * glm::vec4(v2, 1.0));
            v3 = glm::vec3(transform * glm::vec4(v3, 1.0));
            v4 = glm::vec3(transform * glm::vec4(v4, 1.0));
        }
    }
}

void SceneWidget::createCylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks) {
    GLUquadric *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluCylinder(quadric, base, top, height, slices, stacks);
}


void SceneWidget::keyPressEvent(QKeyEvent *key) {
    qDebug() << key;
    const float cameraSpeed = 0.1f; // adjust accordingly
    const float turningSpeed = 0.05f;
//    float camX;
//    float camZ;


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

//void SceneWidget::keyPressEvent(QKeyEvent *key) {
//    qDebug() << key;
//    const float cameraSpeed = 0.1f; // adjust accordingly
//    const float turningSpeed = 0.05f;
////    float camX;
////    float camZ;
//
//
//    //Keep yaw between -pi/2 and pi/2
//    qDebug() << camX;
//    if (camX < 0) {
//        yaw = (M_PI + yaw);
//    }
//    if (key->key() == Qt::Key_E) {
//        float newYaw = yaw - M_PI / 2;
//        light0Position[2] += sin(newYaw) * cameraSpeed;
//        cameraPosition[2] += sin(newYaw) * cameraSpeed;
//        cameraDirection[2] += sin(newYaw) * cameraSpeed;
//        light0Position[0] += cos(newYaw) * cameraSpeed;
//        cameraPosition[0] += cos(newYaw) * cameraSpeed;
//        cameraDirection[0] += cos(newYaw) * cameraSpeed;
//    }
//    if (key->key() == Qt::Key_Q) {
//        float newYaw = yaw + M_PI / 2;
//        light0Position[2] += sin(newYaw) * cameraSpeed;
//        cameraPosition[2] += sin(newYaw) * cameraSpeed;
//        cameraDirection[2] += sin(newYaw) * cameraSpeed;
//        light0Position[0] += cos(newYaw) * cameraSpeed;
//        cameraPosition[0] += cos(newYaw) * cameraSpeed;
//        cameraDirection[0] += cos(newYaw) * cameraSpeed;
//    }
//
//
//    if (key->key() == Qt::Key_W) {
//        light0Position[0] += cos(yaw) * cameraSpeed;
//        cameraPosition[0] += cos(yaw) * cameraSpeed;
//        cameraDirection[0] += cos(yaw) * cameraSpeed;
//        light0Position[2] += sin(yaw) * cameraSpeed;
//        cameraPosition[2] += sin(yaw) * cameraSpeed;
//        cameraDirection[2] += sin(yaw) * cameraSpeed;
//    }
//    if (key->key() == Qt::Key_S) {
//        light0Position[0] -= cos(yaw) * cameraSpeed;
//        cameraPosition[0] -= cos(yaw) * cameraSpeed;
//        cameraDirection[0] -= cos(yaw) * cameraSpeed;
//        light0Position[2] -= sin(yaw) * cameraSpeed;
//        cameraPosition[2] -= sin(yaw) * cameraSpeed;
//        cameraDirection[2] -= sin(yaw) * cameraSpeed;
//    }
//
//    if (key->key() == Qt::Key_D) {
//        turningNumber += turningSpeed;
//    }
//    if (key->key() == Qt::Key_A) {
//        turningNumber -= turningSpeed;
//    }
//    camX = sin(turningNumber) * radius;
//    camZ = cos(turningNumber) * radius;
//    cameraDirection[0] = cameraPosition[0] - camX;
//    cameraDirection[2] = cameraPosition[2] - camZ;
//    if (camX != 0) {
//        yaw = atan(camZ / camX);
////        if (camX < 0) {
////            yaw = -1 * atan(camZ / camX);
////        }
//    } else {
//        if (camZ == 1) {
//            yaw = M_PI_2;
//        } else {
//            yaw = 3 * M_PI_2;
//        }
//    }
//    if (key->key() == Qt::Key_R) {
//
//        cameraPosition[1] += 0.2;
//        light0Position[1] += 0.2;
//        cameraDirection[1] += 0.2;
////            updateGL();
//
//    }
//    if (key->key() == Qt::Key_T) {
//
//        cameraPosition[1] -= 0.2;
//        light0Position[1] -= 0.2;
//        cameraDirection[1] -= 0.2;
////            updateGL();
//
//    }
//    if (key->key() == Qt::Key_F) {
//
////        cameraPosition[1] += 0.2;
//        cameraDirection[1] += 0.2;
////            updateGL();
//
//    }
//    if (key->key() == Qt::Key_G) {
//
////        cameraPosition[1] -= 0.2;
//        cameraDirection[1] -= 0.2;
////            updateGL();
//
//    }
//
//    if (key->key() == Qt::Key_Control) {
//        while (cameraPosition[1] > 4) {
//
//            cameraPosition[1] -= 0.2;
//            light0Position[1] -= 0.2;
//            cameraDirection[1] -= 0.3;
//            updateGL();
//
//        }
//    }
//    if (jumping || falling) {
//        key->ignore();
//        return;
//    }
//    if (key->key() == Qt::Key_Shift && !jumping && !falling && !key->isAutoRepeat()) {
//        qDebug() << jumping;
//        while (cameraPosition[1] < 6.5) {
//
//            light0Position[1] += 0.2;
//            cameraPosition[1] += 0.2;
//            cameraDirection[1] += 0.2;
//            light0Position[1] -= 1.0 / 16;
//            cameraPosition[1] -= 1.0 / 16;
//            cameraDirection[1] -= 1.0 / 16;
//            updateGL();
//            jumping = true;
//        }
//        while (cameraPosition[1] > 5) {
//
//            light0Position[1] -= 1.0 / 16;
//            cameraPosition[1] -= 1.0 / 16;
//            cameraDirection[1] -= 1.0 / 16;
//            updateGL();
//            falling = true;
//        }
//        light0Position[1] = 5;
//        cameraPosition[1] = 5;
//        cameraDirection[1] = 5;
//        jumping = false;
//        falling = false;
//    }
//    qDebug() << "pos" << cameraPosition[0] << cameraPosition[1] << cameraPosition[2];
//    qDebug() << "posL" << light0Position[0] << light0Position[1] << light0Position[2];
//    qDebug() << "dir" << cameraDirection[0] << cameraDirection[1] << cameraDirection[2] << camZ << camX;
//    qDebug() << "yaw" << yaw << fmod((yaw / M_2_PI) * 360, 360);
//    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
//
//    updateGL();
//}

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
    createTessCube(1, 1, 1, 10, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 9, 0);
    createTessCube(1, 1, 1, 10, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, 9, 0);
    createTessCube(1, 1, 1, 10, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 9, 3);
    createTessCube(1, 1, 1, 10, 10, 10);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 9, -3);
    createTessCube(1, 1, 1, 10, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 5, 0);
    createTessCube(1, 1, 1, 10, 10, 10);
    glPopMatrix();
    float width = 10;
    float height = 20;
    float depth = 30;
    this->walls(10.0, 20.0, 30.0, 100, 100, 100);
//    this->createCube(2.0, 3.0, 2.0, 1.0, 0, 0.0);
//    this->createCube(2.0, 3.0, 2.0, 1.0, 15, 0.0);
//    this->createCube(1, 1, 1, -3, 6, -5);
//    glTranslatef(-3, 3, -5); //move to the desired location
    GLdouble r = 2;
    GLint sl = 40;
    GLint spl = 20;
//    this->createSphere(r, sl, spl);
//    this->createCylinder(r, r, r * 3, sl, spl);
//    glTranslatef(-2., 3., 5.);
//    this->createTessCube(2, 4, 5, 10, 10, 10);
//    glTranslatef(0, 3, 0);
//    this->createCube(2, 4, 5, 0, 0, 0);
//    glTranslatef(0, 3, 0);
//    glScaled(0.5, 0.5, 0.5);
//    this->createSemiCylinder(1.0, 1000.0, 10, 10, 10);

    float radius = 1;
//    duration = ( ( clock() - start )/ (double) CLOCKS_PER_SEC) *24;
    float camX = sin(frame / 24) * radius;
    float camZ = cos(frame / 24) * radius;
    float camHeight = 5;
    frame++;
//    qDebug() << camX << camZ << frame;
//    gluLookAt(camX, camHeight - 1, camZ, 3.0, camHeight, 0.0, 0.0, 11.0, 0.0);
//    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    gluLookAt(cameraDirection[0], cameraDirection[1], cameraDirection[2], cameraPosition[0], cameraPosition[1],
              cameraPosition[2], cameraUp[0], cameraUp[1] + 10000000000000, cameraUp[2]);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);

//              gluLookAt(1, 5 , 0, cameraPosition[0], camHeight,
//              cameraPosition[2], cameraUp[0], cameraUp[1] + 10000000000000, cameraUp[2]);
//qDebug()<<
    // flush to screen
    glFlush();
    frame++;

} // paintGL()
