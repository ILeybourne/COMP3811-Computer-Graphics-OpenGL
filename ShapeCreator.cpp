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

void ShapeCreator::walls(float width, float height, float depth, int tessX, int tessY, int tessZ) {
////   North Wall White
    //Coordinates
    glm::vec3 v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v2 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    glm::vec3 v3 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    glm::vec3 v4 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    //Normal of rect
    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

//    glBindTexture(GL_TEXTURE_2D, MyTexture[0]);
//    glBegin(GL_POLYGON);
//    glNormal3f(0, 0, 1);
//    glTexCoord2f(0.0f, 0.0f);
//    glVertex3f(-1.0 * w / 2, 0.0 * h, 1.0);
//    glTexCoord2f(0.0f, 1.0f);
//    glVertex3f(-1.0 * w / 2, 1.0 * h, 1.0);
//    glTexCoord2f(1.0f, 1.0f);
//    glVertex3f(1.0 * w / 2, 1.0 * h, 1.0);
//    glTexCoord2f(1.0f, 0.0f);
//    glVertex3f(1.0 * w / 2, 0.0 * h, 1.0);
//    glEnd();

    glColor3f(1.0, 1.0, 1.0);

    float tessXSize = abs(v1[0] - v3[0]) / (tessX);
    float tessYSize = abs(v1[1] - v3[1]) / (tessY);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(v1[0], v1[1], v1[2]);
    glTexCoord2f(0.0f, 1.0f);glVertex3f(v2[0], v2[1], v2[2]);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(v3[0], v3[1], v3[2]);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(v4[0], v4[1], v4[2]);
    glEnd();

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
//    South Wall Green
    glColor3f(0.0, 1.0, 0.0);
    //Coordinates
    v1 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v2 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

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
            glVertex3f(v2[0], j + tessYSize, k);
            glVertex3f(v3[0], j + tessYSize, k + tessZSize);
            glVertex3f(v4[0], j, k + tessZSize);
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
            glVertex3f(i + tessXSize, v2[1], k);
            glVertex3f(i, v3[1], k);
            glVertex3f(i, v4[1], k + tessZSize);
            glEnd();
        }
    }
}


void ShapeCreator::createTessCube(float width, float height, float depth, int tessX, int tessY, int tessZ) {

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
    float width = planeWidth;
    float depth = planeDepth;
    for (int i = 0; i < planeXTess + 1; i++) {
        for (int k = 0; k < planeZTess + 1; k++) {
            srand(seedNumber + i * 10 + k * 3);
            float randomNumber = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / amplitude));

            heightsGenerated[i][k] = randomNumber;
//            qDebug() << "ran" << i << k << randomNumbe r;
        }
    }

}


void ShapeCreator::createTessTriPlane(float width, float depth, int tessX, int tessZ) {
//Yellow floor
    float height = 1;
    int heightXCounter = 0;
    int heightZCounter = 0;
    glColor3f(0.5, 1.0, 0.0);
    glm::vec3 v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v2 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v3 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    glm::vec3 v4 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    float tessXSize = abs(v1[0] - v3[0]) / (tessX);
    float tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    for (float i = v3[0]; i < v1[0]; i += tessXSize) {
        for (float k = v3[2]; k < v1[2] - tessZSize; k += tessZSize) {
            glm::vec3 vA = {i + tessXSize, heightsGenerated[heightXCounter + 1][heightZCounter + 1], k + tessZSize};
            glm::vec3 vB = {i + tessXSize, heightsGenerated[heightXCounter + 1][heightZCounter], k + 0};
            glm::vec3 vC = {i + 0, heightsGenerated[heightXCounter][heightZCounter], k + 0};
            glm::vec3 vD = {i + 0, heightsGenerated[heightXCounter][heightZCounter + 1], k + tessZSize};
            float r1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float r2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float r3 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float r4 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

            normal = glm::normalize(glm::cross(vB - vA, vC - vB));
            glNormal3fv(glm::value_ptr(normal));
            glBegin(GL_POLYGON);
            glVertex3f(vA.x, vA.y, vA.z);
            glVertex3f(vB.x, vB.y, vB.z);
            glVertex3f(vC.x, vC.y, vC.z);
            glEnd();
            normal = glm::normalize(glm::cross(vC - vA, vD - vC));
            glNormal3fv(glm::value_ptr(normal));
            glBegin(GL_POLYGON);
            glVertex3f(vA.x, vA.y, vA.z);
            glVertex3f(vC.x, vC.y, vC.z);
            glVertex3f(vD.x, vD.y, vD.z);
            glEnd();
            heightZCounter++;
//            qDebug() << heightXCounter<<heightZCounter;
        }
        heightZCounter = 0;
        heightXCounter++;
    }
}

void ShapeCreator::drawTextPlane(float w, float h) {
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


void ShapeCreator::createCube(float w, float h, float d, float x, float y, float z) {
    //North Wall White
//    glMatrixMode(GL_TEXTURE_MATRIX);
//    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, MyTexture[0]);
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


void ShapeCreator::createSphere(GLdouble radius, GLint slices, GLint stacks) {
    GLUquadric *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluSphere(quadric, radius, slices, stacks);
}

void ShapeCreator::createSemiCylinder(float rad, float length, int tessX, int tessY, int tessZ) {
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

void ShapeCreator::imageLoader() {
    glEnable(GL_TEXTURE_2D);

    QString skyboxStrings[6] = {
//            "./textureinternet/wall.jpg"
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_0_Front+Z.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_1_Back-Z.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_2_Left+X.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_3_Right-X.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_4_Up+Y.jpg",
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_5_Down-Y.jpg",
    };
    numberOfTextures = sizeof(skyboxStrings) / sizeof(skyboxStrings[0]);
    qDebug() << numberOfTextures;
    int nChannels[numberOfTextures];
    glGenTextures(6, MyTexture);

    for (int i = 0; i < numberOfTextures; i++) {
        p_qimage.push_back(QImage(skyboxStrings[i]));
        qDebug() << p_qimage[i].isNull() << "null?";
        imageWidth[i] = p_qimage[i].width();
        imageHeight[i] = p_qimage[i].height();
        qDebug() << imageWidth[i] << imageHeight[i] << "w h?";
        imageSize[i] = imageWidth[i] * imageHeight[i];

        nChannels[i] = 3;
        if (skyboxStrings[i].endsWith("png")) {
            qDebug() << "4 chan";
            nChannels[i] = 4;
        }
    }
    for (int i = 0; i < numberOfTextures; i++) {
        qDebug() << nChannels[i] << "xhan";
        qDebug() << imageWidth[i] << "w";
        qDebug() << imageWidth[i] << "h";
        qDebug() << imageSize[i] << "s";
    }

    qDebug() << nChannels[0] << nChannels[1] << nChannels[2] << nChannels[3] << nChannels[4] << nChannels[5];
    qDebug() << nChannels[0];
    for (int i = 0; i < numberOfTextures; i++) {
        qDebug() << "first";
        unsigned int w = imageWidth[i];
        unsigned int h = imageHeight[i];
        unsigned int s = imageSize[i];
        GLubyte image1d3Chan[w * h * 3];
        qDebug() << "second";

        GLubyte image1d4Chan[imageWidth[i] * imageHeight[i] * 4];
        qDebug() << "third";

        if (nChannels[i] == 3) {
            qDebug() << "3 chan";

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
            qDebug() << "4channnn";
            for (unsigned int i_pix = 0; i_pix < imageSize[i]; i_pix++) {
                std::div_t part = std::div((int) i_pix, (int) imageWidth[i]);
                QRgb colVal = p_qimage[i].pixel(imageWidth[i] - part.rem - 1, part.quot);
                image1d4Chan[4 * imageSize[i] - 4 * i_pix - 4] = qRed(colVal);
                image1d4Chan[4 * imageSize[i] - 4 * i_pix - 3] = qGreen(colVal);
                image1d4Chan[4 * imageSize[i] - 4 * i_pix - 2] = qBlue(colVal);
                image1d4Chan[4 * imageSize[i] - 4 * i_pix - 1] = qAlpha(colVal);
            }
        }
        qDebug() << "end";

        glBindTexture(GL_TEXTURE_2D, MyTexture[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //    glActiveTexture(GL_TEXTURE0);
        GLint format;
        if (nChannels[i] == 3) {

            qDebug() << "3 chan texturing";

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





//
////    for (unsigned int i_x_pix = 0; i_x_pix < N_X_IMAGE; i_x_pix++) {
////        for (unsigned int i_y_pix = 0; i_y_pix < N_Y_IMAGE; i_y_pix++) {
////            QRgb colval = p_qimage->pixel(i_x_pix, i_y_pix);
////            image[N_Y_IMAGE - 1 - i_y_pix][i_x_pix][0] = qRed(colval);
////            image[N_Y_IMAGE - 1 - i_y_pix][i_x_pix][1] = qGreen(colval);
////            image[N_Y_IMAGE - 1 - i_y_pix][i_x_pix][2] = qBlue(colval);
////        }
////    }
//


//    QImage *p_qimage2 = new QImage("./textureinternet/wall.jpg");
//
//    unsigned int w = p_qimage2->width();
//    unsigned int h = p_qimage2->height();
//    unsigned int size = w * h;
//
//    if (!p_qimage2->isNull()) {
//        qDebug() << "image loaded yay";
//        qDebug() << p_qimage2->width();
//    }
//    GLubyte image1d[w * h * 3];
//
////    GLubyte image1d[N_X_IMAGE * N_Y_IMAGE * N_COLOR];
//    qDebug() << size;
//
//    for (unsigned int i_pix = 0; i_pix < size; i_pix++) {
//        std::div_t part = std::div((int) i_pix, (int) w);
//        QRgb colVal = p_qimage2->pixel(N_X_IMAGE - part.rem - 1, part.quot);
//        image1d[3 * size - 3 * i_pix - 3] = qRed(colVal);
//        image1d[3 * size - 3 * i_pix - 2] = qGreen(colVal);
//        image1d[3 * size - 3 * i_pix - 1] = qBlue(colVal);
//    }
//
//    glEnable(GL_TEXTURE_2D);
//    glGenTextures(1, &singText);
////    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, singText);
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT
//    );
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT
//    );
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR
//    );
//    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR
//    );
//
//    GLint format = GL_RGB;
//
//    glTexImage2D(GL_TEXTURE_2D,
//                 0, format, w, h, 0, format, GL_UNSIGNED_BYTE,
//                 image1d);


//    glDisable(GL_TEXTURE_2D);

}