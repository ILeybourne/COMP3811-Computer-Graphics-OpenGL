#include "ShapeCreator.h"
#include <QGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
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
#include <QColor>


//#define STB_IMAGE_IMPLEMENTATION
//
//#include "stb_image.h"

// constructor
ShapeCreator::ShapeCreator(QWidget *parent) {// constructor
//    this->parent = *parent;
    this->heightGenerator(1, 1);
}
// constructor

void ShapeCreator::sky(float width, float height, float depth, int tessX, int tessY, int tessZ) {
//    glActiveTexture(GL_TEXTURE0);
//    glActiveTexture(GL_TEXTURE1);

    glBindTexture(GL_TEXTURE_2D, 0);
////   North Wall White
    //Coordinates
    glm::vec3 v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v4 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    glm::vec3 v3 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    glm::vec3 v2 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    //Normal of rect
    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));
    glBindTexture(GL_TEXTURE_2D, MyTexture[0]);
    glColor3f(1.0, 1.0, 1.0);
//    float tessXSize = abs(v1[0] - v3[0]) / (tessX);
//    float tessYSize = abs(v1[1] - v3[1]) / (tessY);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(v1[0], v1[1], v1[2]);
    glTexCoord2f(1.0f, 0.0f);

    glVertex3f(v2[0], v2[1], v2[2]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(v3[0], v3[1], v3[2]);
    glTexCoord2f(0.0f, 1.0f);

    glVertex3f(v4[0], v4[1], v4[2]);
    glEnd();
//    glActiveTexture(GL_TEXTURE0);

//    for (float i = v1[0]; i < v3[0]; i += tessXSize) {
//        for (float j = v1[1]; j < v3[1]; j += tessYSize) {
//            glBegin(GL_POLYGON);
//            glVertex3f(i, j, v1[2]);
//            glVertex3f(i + tessXSize, j, v2[2]);
//            glVertex3f(i + tessXSize, j + tessYSize, v3[2]);
//            glVertex3f(i, j + tessYSize, v4[2]);
//            glEnd();
//        }
//    }

    //East Wall Red
//    glColor3f(1.0, 0.0, 0.0);
    //Coordinates
    v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v4 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v2 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));


    glBindTexture(GL_TEXTURE_2D, MyTexture[2]);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(v1[0], v1[1], v1[2]);
    glTexCoord2f(1.0f, 0.0f);

    glVertex3f(v2[0], v2[1], v2[2]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(v3[0], v3[1], v3[2]);
    glTexCoord2f(0.0f, 1.0f);

    glVertex3f(v4[0], v4[1], v4[2]);
    glEnd();

//    tessYSize = abs(v1[1] - v3[1]) / (tessY);
//    float tessZSize = abs(v1[1] - v3[1]) / (tessZ);
//    for (float j = v1[1]; j < v3[1]; j += tessYSize) {
//        for (float k = v3[2]; k < v1[2]; k += tessZSize) {
//            glBegin(GL_POLYGON);
//            glVertex3f(v1[0], j, k);
//            glVertex3f(v2[0], j + tessYSize, k);
//            glVertex3f(v3[0], j + tessYSize, k + tessZSize);
//            glVertex3f(v4[0], j, k + tessZSize);
//            glEnd();
//        }
//    }
//    South Wall Green
//    glColor3f(1.0, 1.0, 1.0);
    //Coordinates
    v1 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v4 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    glBindTexture(GL_TEXTURE_2D, MyTexture[1]);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(v1[0], v1[1], v1[2]);
    glTexCoord2f(1.0f, 0.0f);

    glVertex3f(v2[0], v2[1], v2[2]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(v3[0], v3[1], v3[2]);
    glTexCoord2f(0.0f, 1.0f);

    glVertex3f(v4[0], v4[1], v4[2]);
    glEnd();

    //West Wall Blue
//    glColor3f(0.0, 0.0, 1.0);
    //Coordinates
    v1 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    glBindTexture(GL_TEXTURE_2D, MyTexture[3]);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(v1[0], v1[1], v1[2]);
    glTexCoord2f(1.0f, 0.0f);

    glVertex3f(v2[0], v2[1], v2[2]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(v3[0], v3[1], v3[2]);
    glTexCoord2f(0.0f, 1.0f);

    glVertex3f(v4[0], v4[1], v4[2]);
    glEnd();

    //Purple Ceil
//    glColor3f(1.0, 0.0, 1.0);
    v2 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v1 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    glBindTexture(GL_TEXTURE_2D, MyTexture[4]);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(v1[0], v1[1], v1[2]);
    glTexCoord2f(1.0f, 0.0f);

    glVertex3f(v2[0], v2[1], v2[2]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(v3[0], v3[1], v3[2]);
    glTexCoord2f(0.0f, 1.0f);

    glVertex3f(v4[0], v4[1], v4[2]);
    glEnd();

    //Yellow floor
//    glColor3f(1.0, 1.0, 0.0);
    v3 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v1 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    glBindTexture(GL_TEXTURE_2D, MyTexture[5]);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(v1[0], v1[1], v1[2]);
    glTexCoord2f(1.0f, 0.0f);

    glVertex3f(v2[0], v2[1], v2[2]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(v3[0], v3[1], v3[2]);
    glTexCoord2f(0.0f, 1.0f);

    glVertex3f(v4[0], v4[1], v4[2]);
    glEnd();
}

void ShapeCreator::walls(float width, float height, float depth, int tessX, int tessY, int tessZ) {
    glBindTexture(GL_TEXTURE_2D, 0);
////   North Wall White
    //Coordinates
    glm::vec3 v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v4 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v3 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    glm::vec3 v2 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    //Normal of rect
    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

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
////    South Wall Green
    glColor3f(0.0, 1.0, 0.0);
    //Coordinates
    v1 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v2 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};

    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessYSize = abs(v1[1] - v3[1]) / (tessY);
    for (float i = v1[0]; i < v3[0]; i += tessXSize) {
        for (float j = v1[1]; j < v3[1]; j += tessYSize) {
            glBegin(GL_POLYGON);
            glVertex3f(i, j, v1[2]);
            glVertex3f(i, j + tessYSize, v4[2]);
            glVertex3f(i + tessXSize, j + tessYSize, v3[2]);
            glVertex3f(i + tessXSize, j, v2[2]);
            glEnd();
        }
    }

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

    tessYSize = abs(v1[1] - v3[1]) / (tessY);
    tessZSize = abs(v1[1] - v3[1]) / (tessZ);
    for (float j = v1[1]; j < v3[1]; j += tessYSize) {
        for (float k = v3[2]; k < v1[2]; k += tessZSize) {
            glBegin(GL_POLYGON);
            glVertex3f(v1[0], j, k);
            glVertex3f(v4[0], j, k + tessZSize);
            glVertex3f(v3[0], j + tessYSize, k + tessZSize);
            glVertex3f(v2[0], j + tessYSize, k);
            glEnd();
        }
    }

    //Purple Ceil
    glColor3f(1.0, 0.0, 1.0);
    v1 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v4 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

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
    v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    for (float i = v3[0]; i < v1[0]; i += tessXSize) {
        for (float k = v3[2]; k < v1[2]; k += tessZSize) {
            glBegin(GL_POLYGON);
            glVertex3f(i + tessXSize, v1[1], k + tessZSize);
            glVertex3f(i, v4[1], k + tessZSize);
            glVertex3f(i, v3[1], k);
            glVertex3f(i + tessXSize, v2[1], k);
            glEnd();
        }
    }
}


void ShapeCreator::createTessCube(float width, float height, float depth, int tessX, int tessY, int tessZ) {
    glBindTexture(GL_TEXTURE_2D, 0);

////   North Wall White
    //Coordinates
    glm::vec3 v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v2 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v3 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    glm::vec3 v4 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    //Normal of rect
    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

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
    //Coordinates
    v1 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v4 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

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
    v1 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v2 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    for (float i = v3[0]; i < v1[0] - tessXSize; i += tessXSize) {
        for (float k = v3[2]; k < v1[2] - tessZSize; k += tessZSize) {
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
    v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v4 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    for (float i = v3[0]; i < v1[0] - tessXSize; i += tessXSize) {
        for (float k = v3[2]; k < v1[2] - tessZSize; k += tessZSize) {
            glBegin(GL_POLYGON);
            glVertex3f(i + tessXSize, v1[1], k + tessZSize);
            glVertex3f(i + tessXSize, v2[1], k);
            glVertex3f(i, v3[1], k);
            glVertex3f(i, v4[1], k + tessZSize);
            glEnd();
        }
    }
}


void ShapeCreator::heightGenerator(float x, float z) {

    float amp = 2;
    int seedNumber = 1;
    float height = 1;
    int width = int(planeWidth);
    int depth = int(planeDepth);
    float tempHeightsGenerated[planeWidth + 1][planeDepth + 1];

    for (int i = 0; i < width + 1; i++) {
        for (int k = 0; k < depth + 1; k++) {
            srand(seedNumber + i * 10 + k * 3);
            float randomNumber = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / amplitude));
            tempHeightsGenerated[i][k] = randomNumber;
        }
    }

    //smooth heights
    for (int i = 0; i < width + 1; i++) {
        for (int k = 0; k < depth + 1; k++) {
            int n1 = i - 1;
            int n2 = i + 1;
            int m1 = k - 1;
            int m2 = k + 1;
            if (i == 0)
                n1 = width;
            if (i == width)
                n2 = 0;
            if (k == 0)
                n1 = depth;
            if (k == depth)
                n2 = 0;
//            int topLeft[2] = {n, m};
//            int topRight[2] = {n, m};
//            int bottomLeft[2] = {n, m};
//            int bottomRight[2] = {n, m};
            float corners = (tempHeightsGenerated[n1][m1] + tempHeightsGenerated[n1][m2] +
                             tempHeightsGenerated[n2][m1] + tempHeightsGenerated[n2][m2]) / (4 * 6.0);

            float consecutive = (tempHeightsGenerated[n1][k] + tempHeightsGenerated[n2][k] +
                                 tempHeightsGenerated[i][m1] + tempHeightsGenerated[i][m2]) / (4 * 3.0);

            float center = tempHeightsGenerated[i][k] / 3.0;

            heightsGenerated[i][k] = corners + consecutive + center;
//            heightsGenerated[i][k]  = tempHeightsGenerated[i][k] ;
        }
    }


}

float ShapeCreator::interpolation(float x, float z, float c) {
    float theta = (c) * M_PI;
    float cosNorm = (1.0 - cosf(theta)) * 0.5;
    float v = x * (1.0 - cosNorm) + z * cosNorm;
    return (x * (1.0 - cosNorm)) + (z * cosNorm);
}

float ShapeCreator::interpolateAt(float x, float z) {
    int i = floor(x);
    int k = floor(z);

    float iFract = x - i;
    float kFract = z - k;

    float heightAti0k0 = heightsGenerated[i][k];
    float heightAti0k1 = heightsGenerated[i][k + 1];
    float heightAti1k0 = heightsGenerated[i + 1][k];
    float heightAti1k1 = heightsGenerated[i + 1][k + 1];


    float interpolX1 = interpolation(heightAti0k0, heightAti1k0, iFract);

    float interpolX2 = interpolation(heightAti0k1, heightAti1k1, iFract);

    return interpolation(interpolX1, interpolX2, kFract);
}


void ShapeCreator::createTessTriPlane(float width, float depth, int tessX, int tessZ) {
    float height = 1;
//    int heightXCounter = 0;
//    int heightZCounter = 0;
//    int tessXCounter = 0;
//    int tessZCounter = 0;
    glColor3f(0.5, 1.0, 0.0);
    glm::vec3 v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v2 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v3 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    glm::vec3 v4 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    float tessXSize = 1.0 / (tessX);
    float tessZSize = 1.0 / (tessZ);

    float thetaSpeed = 2.0;
    float theta = thetaSpeed * M_PI;
    float x = (1.0 - cosf(theta)) * 0.5;


    for (int i = 0; i < width; i++) {
        for (int k = 0; k < depth; k++) {
//    for (int i = 0; i < width; i++) {
//        for (int k = 0; k < depth; k++) {

            for (float n = 0; n < 1; n += tessXSize) {
                for (float m = 0; m < 1; m += tessZSize) {
                    //                    float heightAti0k0 = heightsGenerated[i][k];
                    //                    float heightAti0k1 = heightsGenerated[i][k + 1];
                    //                    float heightAti1k0 = heightsGenerated[i + 1][k + 1];
                    //                    float heightAti1k1 = heightsGenerated[i + 1][k + 1];


                    float heightAtn1m1 = interpolateAt(i + n, k + m);
                    float heightAtn0m0 = interpolateAt(i + n + tessXSize, k + m);
                    float heightAtn0m1 = interpolateAt(i + n + tessXSize, k + m + tessZSize);
                    float heightAtn1m0 = interpolateAt(i + n, k + m + tessZSize);

                    glm::vec3 vA = {i + n + tessXSize, heightAtn0m0, k + m};
                    glm::vec3 vB = {i + n + tessXSize, heightAtn0m1, k + m + tessZSize};
                    glm::vec3 vC = {i + n, heightAtn1m0, k + m + tessZSize};
                    glm::vec3 vD = {i + n, heightAtn1m1, k + m};

                    normal = glm::normalize(glm::cross(vB - vA, vC - vB));
                    glNormal3fv(glm::value_ptr(-normal));
                    glBegin(GL_POLYGON);
                    glVertex3f(vA.x, vA.y, vA.z);
                    glVertex3f(vB.x, vB.y, vB.z);
                    glVertex3f(vC.x, vC.y, vC.z);
                    glEnd();

                    normal = glm::normalize(glm::cross(vC - vA, vD - vC));
                    glNormal3fv(glm::value_ptr(-normal));
                    glBegin(GL_POLYGON);
                    glVertex3f(vA.x, vA.y, vA.z);
                    glVertex3f(vC.x, vC.y, vC.z);
                    glVertex3f(vD.x, vD.y, vD.z);
                    glEnd();
                }
            }
        }
    }
}

void ShapeCreator::drawTextPlane(float w, float h) {
    glBindTexture(GL_TEXTURE_2D, 0);

//    this->imageLoader();
//    glEnable(GL_TEXTURE_2D);
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, MyTexture[0]);
    glBindTexture(GL_TEXTURE_2D, MyTexture[0]);
    glBegin(GL_POLYGON);
    glNormal3f(0, 0, 1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0 * w / 2, 0.0 * h, 1.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0 * w / 2, 1.0 * h, 1.0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0 * w / 2, 1.0 * h, 1.0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0 * w / 2, 0.0 * h, 1.0);
    glEnd();
//    glDisable(GL_TEXTURE_2D);
}

void ShapeCreator::createFigurine() {
    glBindTexture(GL_TEXTURE_2D, 0);

//    glColor4b(1.0,1.0,0,1);
//    glColor3b(1.0,1.0,0);
    glColor3f(1.0, 1.0, 0);

    glPushMatrix();
    glScaled(0.5, 0.7, 0.5);
    createSphere(1, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, -1.0 / 0.7 / 4, 0);
    glPushMatrix();
    glScaled(0.2, 0.4, 0.2);
    glRotatef(90, 1, 0, 0);
    createCylinder(1, 1, 1, 20, 20);
//            createSphere(1, 20, 20);

    glPopMatrix();
//        glScaled(2,1,1);
    glTranslatef(0, -0.4, 0);

    glPushMatrix();
    for (float i = 0; i < 18; i++) {
        int ittDown = 4;
        int neg = 1;
        float offset = 0;
        if (i >= ittDown) {
            neg = -1;
            offset = 0.4;
        }
        glTranslatef(0, -0.05, 0);
        createCube(1. + ((i + 1) * (0.05 * neg)) + offset, 0.1, 1 + ((i + 1) * (0.05 * neg)) + offset, 0, 0, 0, 0);
    }
    glPopMatrix();
    glPushMatrix();
    glTranslatef((1 + 0.25) / 2, -0.2, 0);
    glPushMatrix();
    glScaled(0.2, 0.2, 0.2);
    createSphere(1, 20, 20);

    glPopMatrix();
    glPopMatrix();
//        glTranslatef(0,-0.5,0);
//        createCube(1.5,0.1,1,0,0,0,0);
//        glTranslatef(0,-0.1,0);
//
//        createCube(1.6,0.1,1,0,0,0,0);

//        createCube(2,1,1,0,0,0,0);


    glPopMatrix();

//    glPushMatrix();
//    glm::vec3 v1 = {-1, 0, 0};
//    glm::vec3 v2 = {0, 0, -1};
//    glm::vec3 v3 = {0, -1.5, -1};
//    glm::vec3 v4 = {-1, -1.5, 0};
//    //Normal of rect
//    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
//    glNormal3fv(glm::value_ptr(normal));
//    glBegin(GL_POLYGON);
//    glVertex3f(v1[0],v1[1],v1[2]);
//    glVertex3f(v2[0],v2[1],v2[2]);
//    glVertex3f(v3[0],v3[1],v3[2]);
//    glVertex3f(v4[0],v4[1],v4[2]);
//    glEnd();
//    glPopMatrix();

}


void ShapeCreator::createCube(float w, float h, float d, float x, float y, float z, bool shadow) {
    glBindTexture(GL_TEXTURE_2D, 0);

    //North Wall White
//    glMatrixMode(GL_TEXTURE_MATRIX);
//    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    if (shadow) glColor4f(0, 0, 0, 0.5);


//    glEnable(GL_TEXTURE_2D);
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, MyTexture[0]);


    glBegin(GL_POLYGON);
    glNormal3f(0, 0, 1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glEnd();
//    glBindTexture(GL_TEXTURE_2D, 0);
//    glDisable(GL_TEXTURE_2D);
//    glMatrixMode(GL_MODELVIEW);


    //East Wall
    glColor3f(1.0, 0.0, 0.0);
    if (shadow) glColor4f(0, 0, 0, 0.5);


    glBegin(GL_POLYGON);
    glNormal3f(1, 0, 0);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glEnd();

    //South Wall Green
    glColor3f(0.0, 1.0, 0.0);
    if (shadow) glColor4f(0, 0, 0, 0.5);


    glBegin(GL_POLYGON);
    glNormal3f(0, 0, -1);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glEnd();

    //West Wall Blue
    glColor3f(0.0, 0.0, 1.0);
    if (shadow) glColor4f(0, 0, 0, 0.5);


    glBegin(GL_POLYGON);
    glNormal3f(-1, 0, 0);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glEnd();

    //Purple Ceil
    glColor3f(1.0, 0.0, 1.0);
    if (shadow) glColor4f(0, 0, 0, 0.5);


    glBegin(GL_POLYGON);
    glNormal3f(0, 1, 0);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glEnd();

    //Yellow floor
    glColor3f(1.0, 1.0, 0.0);
    if (shadow) glColor4f(0, 0, 0, 0.5);

    glBegin(GL_POLYGON);
    glNormal3f(0, -1, 0);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glEnd();

}


void ShapeCreator::createSphere(GLdouble radius, GLint slices, GLint stacks) {
    glBindTexture(GL_TEXTURE_2D, 0);
    GLUquadric *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluSphere(quadric, radius, slices, stacks);
}

void ShapeCreator::createSemiCylinder(float rad, float length, int tessX, int tessY, int tessZ) {
    glBindTexture(GL_TEXTURE_2D, 0);

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

void ShapeCreator::createCylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks) {
    glBindTexture(GL_TEXTURE_2D, 0);

    GLUquadric *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluCylinder(quadric, base, top, height, slices, stacks);
}

//void ShapeCreator::loadTextures() {
//    glEnable(GL_TEXTURE_2D);
//    int width, height, nrChannels;
//    //Epic_BlueSunset/Epic_BlueSunset_Cam_0_Front+Z
////    unsigned char *data = stbi_load(
////            "/home/izzy/Documents/Leeds/Work/Year_3/Computer_Graphics/cw2/tutorial1/Scene/textureinternet/wall.jpg",
////            &width, &height, &nrChannels, 0);
//    unsigned char *data = stbi_load(
//            "/home/izzy/Documents/Leeds/Work/Year_3/Computer_Graphics/cw2/tutorial1/Scene/textureinternet/Epic_BlueSunset/Epic_BlueSunset_Cam_0_Front+Z.png",
//            &width, &height, &nrChannels, 4);
//    if (data) {
//        qDebug() << "text loaded";
//        qDebug() << data[0] << data[512];
//        qDebug() << width << height << nrChannels;
//    } else {
//        qDebug() << "nope loaded";
//
//    }
//
//    glGenTextures(1, &MyTexture);
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, MyTexture);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
//                    GL_REPEAT);    // set texture wrapping to GL_REPEAT (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//
//    GLint format;
//    if (nrChannels == 3) {
//        format = GL_RGB;
//
//    } else if (nrChannels == 4) {
//        format = GL_RGBA;
//    }
//    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE,
//                 data); //data is a gluByte array of your image data
//    qDebug() << glGetError();
//
//    stbi_image_free(data);
//    glDisable(GL_TEXTURE_2D);
//}
void ShapeCreator::imageLoader(QStringList sImage) {
    glEnable(GL_TEXTURE_2D);

    QString skyboxStrings[6] = {
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_0_Front+Z.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_1_Back-Z.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_2_Left+X.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_3_Right-X.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_4_Up+Y.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_5_Down-Y.jpg",
    };

//    numberOfTextures = sizeof(skyboxStrings) / sizeof(skyboxStrings[0]);
//    numberOfTextures = 6;
    numberOfTextures = sImage.size();
    qDebug() << numberOfTextures;
//    qDebug() <<sizeof(sImage) << sizeof(sImage[0])<< numberOfTextures;

//    qDebug() << numberOfTextures;
    int nChannels[numberOfTextures];
    glGenTextures(numberOfTextures, MyTexture);

    for (int i = 0; i < numberOfTextures; i++) {
        p_qimage.push_back(QImage(sImage[i]));
//        qDebug() << p_qimage[i].isNull() << "null?";
        imageWidth[i] = p_qimage[i].width();
        imageHeight[i] = p_qimage[i].height();
//        qDebug() << imageWidth[i] << imageHeight[i] << "w h?";
        imageSize[i] = imageWidth[i] * imageHeight[i];

        nChannels[i] = 3;
        if (sImage[i].endsWith("png")) {
//            qDebug() << "4 chan";
            nChannels[i] = 4;
        }
    }

    for (int i = 0; i < numberOfTextures; i++) {
        unsigned int w = imageWidth[i];
        unsigned int h = imageHeight[i];
        unsigned int s = imageSize[i];
        GLubyte image1d3Chan[w * h * 3];

        GLubyte image1d4Chan[imageWidth[i] * imageHeight[i] * 4];

        if (nChannels[i] == 3) {

//            for (unsigned int i_pix = 0; i_pix < size; i_pix++) {
//        std::div_t part = std::div((int) i_pix, (int) w);
//        QRgb colVal = p_qimage2->pixel(N_X_IMAGE - part.rem - 1, part.quot);
//        image1d[3 * size - 3 * i_pix - 3] = qRed(colVal);
//        image1d[3 * size - 3 * i_pix - 2] = qGreen(colVal);
//        image1d[3 * size - 3 * i_pix - 1] = qBlue(colVal);
//    }

            for (unsigned int i_pix = 0; i_pix < imageSize[i]; i_pix++) {
                std::div_t part = std::div((int) i_pix, (int) imageWidth[i]);

                QRgb colVal = p_qimage[i].pixel(w - part.rem - 1, part.quot);
                image1d3Chan[3 * s - 3 * i_pix - 3] = qRed(colVal);
                image1d3Chan[3 * s - 3 * i_pix - 2] = qGreen(colVal);
                image1d3Chan[3 * s - 3 * i_pix - 1] = qBlue(colVal);
            }
        } else {
            for (unsigned int i_pix = 0; i_pix < imageSize[i]; i_pix++) {
                std::div_t part = std::div((int) i_pix, (int) imageWidth[i]);
                QRgb colVal = p_qimage[i].pixel(imageWidth[i] - part.rem - 1, part.quot);
                image1d4Chan[4 * imageSize[i] - 4 * i_pix - 4] = qRed(colVal);
                image1d4Chan[4 * imageSize[i] - 4 * i_pix - 3] = qGreen(colVal);
                image1d4Chan[4 * imageSize[i] - 4 * i_pix - 2] = qBlue(colVal);
                image1d4Chan[4 * imageSize[i] - 4 * i_pix - 1] = qAlpha(colVal);
            }
        }

        glBindTexture(GL_TEXTURE_2D, MyTexture[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //    glActiveTexture(GL_TEXTURE0);

        GLint format;
        if (nChannels[i] == 3) {
            format = GL_RGB;
            glTexImage2D(GL_TEXTURE_2D,
                         0, format, imageWidth[i], imageHeight[i], 0, format, GL_UNSIGNED_BYTE,
                         image1d3Chan);
        } else {
            format = GL_RGBA;
            glTexImage2D(GL_TEXTURE_2D,
                         0, format, imageWidth[i], imageHeight[i], 0, format, GL_UNSIGNED_BYTE,
                         image1d4Chan);
        }
    }
}

bool ShapeCreator::getOBJData(std::string fp, std::vector<float> &out_vertices,
                              std::vector<float> &out_uvs,
                              std::vector<float> &out_normals) {
    string cp = std::experimental::filesystem::current_path();
    fp = cp.append(fp);

    const char *path = fp.c_str();

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        qDebug() << "Impossible to open the file !";
        return false;
    }
    qDebug() << "File opened";

    while (1) {

        char lineHeader[128];
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break;

        if (strcmp(lineHeader, "v") == 0) {
            glm::vec3 vertex;
            float vertex2x;
            float vertex2y;
            float vertex2z;
            fscanf(file, "%f %f %f\n", &vertex2x, &vertex2y, &vertex2z);
            out_vertices.push_back(vertex2x);
            out_vertices.push_back(vertex2y);
            out_vertices.push_back(vertex2z);
        } else if (strcmp(lineHeader, "vt") == 0) {
            float uv2U;
            float uv2V;
//            fscanf(file, "%f %f\n", &uv.x, &uv.y);
            fscanf(file, "%f %f\n", &uv2U, &uv2V);
//            temp_uvs.push_back(uv);
            temp_uvs2.push_back(uv2U);
            temp_uvs2.push_back(uv2V);

        } else if (strcmp(lineHeader, "vn") == 0) {
            float normal2x;
            float normal2y;
            float normal2z;
//            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            fscanf(file, "%f %f %f\n", &normal2x, &normal2y, &normal2z);
            temp_normals2.push_back(normal2x);
            temp_normals2.push_back(normal2y);
            temp_normals2.push_back(normal2z);

        } else if (strcmp(lineHeader, "f") == 0) {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                 &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2],
                                 &normalIndex[2]);

            if (matches != 9) {
                printf("File can't be read by our simple parser : ( Try exporting with other options\n");
                return false;
            }

            vertexIndices.push_back(vertexIndex[0] - 1);
            vertexIndices.push_back(vertexIndex[1] - 1);
            vertexIndices.push_back(vertexIndex[2] - 1);
            uvIndices.push_back(uvIndex[0]);
            uvIndices.push_back(uvIndex[1]);
            uvIndices.push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }

    }
    qDebug() << "Finished loading data";

//    for (unsigned int i = 0; i < vertexIndices.size(); i++) {
//        unsigned int vertexIndex = vertexIndices[i];
////        glm::vec3 vertex = temp_vertices[vertexIndex - 1];
//        float vertex2x, vertex2y, vertex2z;
//        vertex2x = temp_vertices2[vertexIndex * 3 + 0];
//        vertex2y = temp_vertices2[vertexIndex * 3 + 1];
//        vertex2z = temp_vertices2[vertexIndex * 3 + 2];
//        out_vertices.push_back(vertex2x);
//        out_vertices.push_back(vertex2y);
//        out_vertices.push_back(vertex2z);
//    }
    return true;
}


//bool ShapeCreator::getOBJinfo2(std::string fp, std::vector <std::array<float, 3>> &out_vertices,
//                               std::vector <std::array<float, 2>> &out_uvs,
//                               std::vector <std::array<float, 3>> &out_normals) {
//
//    string cp = std::experimental::filesystem::current_path();
//    fp = cp.append(fp);
//
//    const char *path = fp.c_str();
//
//    FILE *file = fopen(path, "r");
//    if (file == NULL) {
//        qDebug() << "Impossible to open the file !";
//        return false;
//    }
//    qDebug() << "File opened";
//
//    while (1) {
//
//        char lineHeader[128];
//        // read the first word of the line
//        int res = fscanf(file, "%s", lineHeader);
//        if (res == EOF)
//            break;
//
//        if (strcmp(lineHeader, "v") == 0) {
//            glm::vec3 vertex;
//            GLfloat vertex2x;
//            GLfloat vertex2y;
//            GLfloat vertex2z;
////            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
//            fscanf(file, "%f %f %f\n", &vertex2x, &vertex2y, &vertex2z);
////            qDebug() << vertex2[0] << vertex2[1] << vertex2[2];
//            temp_vertices.push_back(vertex);
//            temp_vertices2.push_back(vertex2x);
//            temp_vertices2.push_back(vertex2y);
//            temp_vertices2.push_back(vertex2z);
//
//
//        } else if (strcmp(lineHeader, "vt") == 0) {
//            glm::vec2 uv;
//            std::array<float, 2> uv2;
////            fscanf(file, "%f %f\n", &uv.x, &uv.y);
//            fscanf(file, "%f %f\n", &uv2[0], &uv2[1]);
////            temp_uvs.push_back(uv);
//            temp_uvs2.push_back(uv2);
//
//        } else if (strcmp(lineHeader, "vn") == 0) {
//            glm::vec3 normal;
//            std::array<float, 3> normal2;
////            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
//            fscanf(file, "%f %f %f\n", &normal2[0], &normal2[1], &normal2[2]);
////            temp_normals.push_back(normal);
//            temp_normals2.push_back(normal2);
//
//        } else if (strcmp(lineHeader, "f") == 0) {
//            std::string vertex1, vertex2, vertex3;
//            GLuint vertexIndex[3], uvIndex[3], normalIndex[3];
//            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0],
//                                 &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2],
//                                 &normalIndex[2]);
//
//            if (matches != 9) {
//                printf("File can't be read by our simple parser : ( Try exporting with other options\n");
//                return false;
//            }
//
//            vertexIndices.push_back(vertexIndex[0]);
//            vertexIndices.push_back(vertexIndex[1]);
//            vertexIndices.push_back(vertexIndex[2]);
//            uvIndices.push_back(uvIndex[0]);
//            uvIndices.push_back(uvIndex[1]);
//            uvIndices.push_back(uvIndex[2]);
//            normalIndices.push_back(normalIndex[0]);
//            normalIndices.push_back(normalIndex[1]);
//            normalIndices.push_back(normalIndex[2]);
//        }
//    }
//
//
////    for (unsigned int i = 0; i < vertexIndices.size(); i++) {
////        unsigned int vertexIndex = vertexIndices[i];
//////        glm::vec3 vertex = temp_vertices[vertexIndex - 1];
////        std::array<float, 3> vertex2;
////        vertex2[0] = temp_vertices2[vertexIndex - 1][0];
////        vertex2[1] = temp_vertices2[vertexIndex - 1][1];
////        vertex2[2] = temp_vertices2[vertexIndex - 1][2];
////        out_vertices.push_back(vertex2);
////    }
//
//
//
////    static constexpr int vect3Size = out_vertices.size();
//
////    std::copy(v.begin(), v.end(), arr);
////    glm::vec3 *vector3Array = &out_vertices[0];
//
////    for (int i = 0; i <; ++i) {
////
////    }
//
//    for (unsigned int i = 0; i < uvIndices.size(); i++) {
//        unsigned int uvIndex = uvIndices[i];
////        glm::vec2 uv = temp_uvs[uvIndex - 1];
//        std::array<float, 2> uv2;
//        uv2[0] = temp_uvs2[uvIndex - 1][0];
//        uv2[1] = temp_uvs2[uvIndex - 1][1];
//        out_uvs.push_back(uv2);
//    }
//
//    for (unsigned int i = 0; i < normalIndices.size(); i++) {
//        unsigned int normalIndex = normalIndices[i];
////        glm::vec3 normal = temp_normals[normalIndex - 1];
//        std::array<float, 3> normal2;
//        normal2[0] = temp_normals2[normalIndex - 1][0];
//        normal2[1] = temp_normals2[normalIndex - 1][1];
//        normal2[2] = temp_normals2[normalIndex - 1][2];
//        out_normals.push_back(normal2);
//    }
//    return true;
//}