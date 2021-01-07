#include "ShapeCreator.h"
#include <GL/glu.h>
#include <QGLWidget>
#include <QtGui>
#include <QtCore/QTime>
#include <glm/glm.hpp>
#include <QOpenGLFunctions>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <QColor>

// constructor
ShapeCreator::ShapeCreator(QWidget *parent) {// constructor
    this->heightGenerator(1, 1);
}
// constructor

void ShapeCreator::sky(float width, float height, float depth) {
    //Set colour to white as textures will be drawn
    glColor3f(1.0, 1.0, 1.0);

////  North Wall (-Z)
    //Coordinates
    glm::vec3 v1 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    glm::vec3 v2 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    glm::vec3 v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    glm::vec3 v4 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};

    //Normal of rectangle
    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    //Bind first skybox texture
    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[0]);
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

    //East Wall (+X)
    //Coordinates
    v2 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v4 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v1 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};

    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[2]);
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

////    South Wall (+Z)
    //Coordinates
    v3 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v4 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));
    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[1]);
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
////


    //West Wall Blue
    //Coordinates
    v2 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[3]);
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
    v4 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v1 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v2 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[4]);
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
    v4 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v3 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));
    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[5]);
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
    glBindTexture(GL_TEXTURE_2D, 0);
}

void ShapeCreator::createDoorway(float width, float height, float depth, int tessX, int tessY, int tessZ) {
    glColor3f(1.0, 1.0, 1.0);
    //Coordinates
    glm::vec3 v1;
    glm::vec3 v2;
    glm::vec3 v3;
    glm::vec3 v4;

    //Normal of rect
    glm::vec3 normal;
    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[textureCreator->wallIndex]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    float scaleFactor = width / tessX / 50;


    //Coordinates
    v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v4 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};

    float tessXSize = abs(v1[0] - v3[0]) / (tessX);
    float tessYSize = abs(v1[1] - v3[1]) / (tessY);
    float tessZSize = abs(v1[2] - v3[2]) / (tessZ);

    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));
    float offset = 0.55;

//    tessZSize = abs(v1[1] - v3[1]) / (tessZ);
    float doorOuter = 0 + 10 * (tessZSize);
    float doorInner = 0 - 10 * (tessZSize);
    float doorwayWidth = 2;
    for (int i = 0; i < 2; i++) {
        glPushMatrix();
        glTranslatef(doorwayWidth * i, 0, 0);
        //Invert normal for external wall
        if (i == 1) {
            glDisable(GL_LIGHT1);
            glEnable(GL_LIGHT2);
            glEnable(GL_LIGHT3);
            glEnable(GL_LIGHT4);
            glNormal3fv(glm::value_ptr(-normal));
        }

        for (float j = v1[1]; j < v3[1]; j += tessYSize) {
            for (float k = v3[2]; k < v1[2]; k += tessZSize) {
                //Render wall that isn't doorway
                if (!(k > doorInner - tessZSize && k < doorOuter && j <= height / 2)) {
                    glBegin(GL_POLYGON);
                    glTexCoord2f((k) * scaleFactor + offset, (j + tessYSize) * scaleFactor);
                    glVertex3f(v2[0], j + tessYSize, k);
                    glTexCoord2f((k) * scaleFactor + offset, (j) * scaleFactor);
                    glVertex3f(v1[0], j, k);
                    glTexCoord2f((k + tessZSize) * scaleFactor + offset, (j) * scaleFactor);
                    glVertex3f(v4[0], j, k + tessZSize);
                    glTexCoord2f((k + tessZSize) * scaleFactor + offset, (j + tessYSize) * scaleFactor);
                    glVertex3f(v3[0], j + tessYSize, k + tessZSize);
                    glEnd();
                }
            }
        }
        glPopMatrix();
    }

    glEnable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT3);
    glDisable(GL_LIGHT4);

    glPushMatrix();
    glTranslatef(0, 0, doorInner);
    createTexturedPlane(width / 2, 0, doorwayWidth, height / 2, 0, 0, doorwayWidth / 10, height / 2 / 10, false,
                        textureCreator->textures[textureCreator->wallIndex]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, doorOuter);
    glRotatef(180, 1, 0, 0);
    glTranslatef(0, -height / 2, 0);

    createTexturedPlane(width / 2, 0, doorwayWidth, height / 2, 0, 0, doorwayWidth / 10, height / 2 / 10, false,
                        textureCreator->textures[textureCreator->wallIndex]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, height / 2, doorInner);
    glRotatef(90, 1, 0, 0);
    createTexturedPlane(width / 2, 0, doorwayWidth, doorOuter - doorInner, 0, 0, doorwayWidth / 10, height / 2 / 10,
                        false,
                        textureCreator->textures[textureCreator->wallIndex]);
    glPopMatrix();

    float inner = (v3[2] / 10) * 4;
    float outer = (v3[2] / 10) * 4;

    v1 = {0, height / 2, inner};
    v2 = {0, height / 2, inner};
    v3 = {0 + 2, 0, inner};
    v4 = {0 + 2, 0, inner};
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));
    glBegin(GL_POLYGON);
    glVertex3f(v1[0], v1[1], v1[2]);
    glVertex3f(v2[0], v2[1], v2[2]);
    glVertex3f(v3[0], v3[1], v3[2]);
    glVertex3f(v4[0], v4[1], v4[2]);
    glEnd();
}

void ShapeCreator::walls(float width, float height, float depth, int tessX, int tessY, int tessZ) {
    glDisable(GL_CULL_FACE);
    glEnable(GL_TEXTURE);
    glBindTexture(GL_TEXTURE_2D, 0);
////   North Wall White
    glColor3f(1.0, 1.0, 1.0);
    //Coordinates
    glm::vec3 v1 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    glm::vec3 v2 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    glm::vec3 v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    glm::vec3 v4 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};

    //Normal of rect
    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));
    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[textureCreator->wallIndex]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    float scaleFactor = width / tessX / 50;
    float tessXSize = abs(v1[0] - v3[0]) / (tessX);
    float tessYSize = abs(v1[1] - v3[1]) / (tessY);

    for (float i = v1[0]; i < v3[0] - tessXSize; i += tessXSize) {
        for (float j = v1[1]; j < v3[1]; j += tessYSize) {
            glBegin(GL_POLYGON);
//            glTexCoord2f((i + tessXSize) * scaleFactor, (j + tessYSize)* scaleFactor);
            glTexCoord2f((i) * scaleFactor, (j) * scaleFactor);
            glVertex3f(i, j, v1[2]);
            glTexCoord2f((i + tessXSize) * scaleFactor, (j) * scaleFactor);
            glVertex3f(i + tessXSize, j, v2[2]);
            glTexCoord2f((i + tessXSize) * scaleFactor, (j + tessYSize) * scaleFactor);
            glVertex3f(i + tessXSize, j + tessYSize, v3[2]);
            glTexCoord2f((i) * scaleFactor, (j + tessYSize) * scaleFactor);
            glVertex3f(i, j + tessYSize, v4[2]);
            glEnd();
        }
    }

    createDoorway(width, height, depth, tessX, tessY, tessZ);
    ////Replaced by createDoorway;
//    //East Wall Red
////    glColor3f(1.0, 0.0, 0.0);
//    //Coordinates
//    v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
//    v2 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
//    v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
//    v4 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
//    //Normal of rect
//    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
//    glNormal3fv(glm::value_ptr(normal));
//    float offset = 0.55;
//    float tessZSize = abs(v1[1] - v3[1]) / (tessZ);
//
//    float doorOuter = v3[2] + 2 * (tessZ / 2 * tessZSize);
//    float doorInner = v3[2] +      tessZ / 2 * tessZSize;
//    float doorwayWidth = 2;
//
//    for (int i = 0; i < 2; i++) {
//        glPushMatrix();
//        glTranslatef(doorwayWidth * i, 0, 0);
//        //Invert normal for external wall
//        if (i == 1)
//            glDisable(GL_LIGHT1);
//        glEnable(GL_LIGHT2);
//        glEnable(GL_LIGHT3);
//        glEnable(GL_LIGHT4);
//        glNormal3fv(glm::value_ptr(-normal));
//        for (float j = v1[1]; j < v3[1]; j += tessYSize) {
//            for (float k = v3[2]; k < v1[2]; k += tessZSize) {
//                //Render wall that isn't doorway
//                if (!(k > doorInner && k < doorOuter && j <= height / 2)) {
//                    glBegin(GL_POLYGON);
//                    glTexCoord2f((k) * scaleFactor + offset, (j + tessYSize) * scaleFactor);
//                    glVertex3f(v2[0], j + tessYSize, k);
//                    glTexCoord2f((k) * scaleFactor + offset, (j) * scaleFactor);
//                    glVertex3f(v1[0], j, k);
//                    glTexCoord2f((k + tessZSize) * scaleFactor + offset, (j) * scaleFactor);
//                    glVertex3f(v4[0], j, k + tessZSize);
//                    glTexCoord2f((k + tessZSize) * scaleFactor + offset, (j + tessYSize) * scaleFactor);
//                    glVertex3f(v3[0], j + tessYSize, k + tessZSize);
//                    glEnd();
//                }
//            }
//        }
//        glPopMatrix();
//    }
//
//    glEnable(GL_LIGHT1);
//    glDisable(GL_LIGHT2);
//    glDisable(GL_LIGHT3);
//    glDisable(GL_LIGHT4);
//
//    glPushMatrix();
//    glTranslatef(0, 0, doorInner);
//    createTexturedPlane(width / 2, 0, doorwayWidth, height / 2, 0, 0, doorwayWidth / 10, height / 2 / 10, false,
//                        textureCreator->textures[textureCreator->wallIndex]);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0, 0, doorOuter);
//    glRotatef(180, 1, 0, 0);
//    glTranslatef(0, -height / 2, 0);
//
//    createTexturedPlane(width / 2, 0, doorwayWidth, height / 2, 0, 0, doorwayWidth / 10, height / 2 / 10, false,
//                        textureCreator->textures[textureCreator->wallIndex]);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0, height / 2, doorInner);
//    glRotatef(90, 1, 0, 0);
//    createTexturedPlane(width / 2, 0, doorwayWidth, doorOuter - doorInner, 0, 0, doorwayWidth / 10, height / 2 / 10,
//                        false,
//                        textureCreator->textures[textureCreator->wallIndex]);
//    glPopMatrix();
//
//    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[textureCreator->wallIndex]);
//
//    float inner = (v3[2] / 10) * 4;
//    float outer = (v3[2] / 10) * 4;
//
//    v1 = {0, height / 2, inner};
//    v2 = {0, height / 2, inner};
//    v3 = {0+ 2, 0,      inner};
//    v4 = {0+ 2, 0,      inner};
//    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
//    glNormal3fv(glm::value_ptr(normal));
//    glBegin(GL_POLYGON);
//    glVertex3f(v1[0], v1[1], v1[2]);
//    glVertex3f(v2[0], v2[1], v2[2]);
//    glVertex3f(v3[0], v3[1], v3[2]);
//    glVertex3f(v4[0], v4[1], v4[2]);
//    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[textureCreator->wallIndex]);
////    South Wall Green
//    glColor3f(0.0, 1.0, 0.0);
    //Coordinates
    v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v4 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessYSize = abs(v1[1] - v3[1]) / (tessY);
    for (float i = v1[0]; i < v3[0] - tessXSize; i += tessXSize) {
        for (float j = v1[1]; j < v3[1]; j += tessYSize) {
            glBegin(GL_POLYGON);
            //            glTexCoord2f((i + tessXSize) * scaleFactor, (j + tessYSize)* scaleFactor);
            glTexCoord2f((i) * scaleFactor, (j) * scaleFactor);

            glVertex3f(i, j, v1[2]);
            glTexCoord2f((i) * scaleFactor, (j + tessYSize) * scaleFactor);

            glVertex3f(i, j + tessYSize, v4[2]);
            glTexCoord2f((i + tessXSize) * scaleFactor, (j + tessYSize) * scaleFactor);

            glVertex3f(i + tessXSize, j + tessYSize, v3[2]);
            glTexCoord2f((i + tessXSize) * scaleFactor, (j) * scaleFactor);

            glVertex3f(i + tessXSize, j, v2[2]);
            glEnd();
        }
    }
    //West Wall Blue
//    glColor3f(0.0, 0.0, 1.0);
    //Coordinates
    v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));
    tessYSize = abs(v1[1] - v3[1]) / (tessY);
    float tessZSize = abs(v1[1] - v3[1]) / (tessZ);
    for (float j = v1[1]; j < v3[1]; j += tessYSize) {
        for (float k = v3[2]; k < v1[2]; k += tessZSize) {
            glBegin(GL_POLYGON);
            glTexCoord2f((k) * scaleFactor, (j) * scaleFactor);
            glVertex3f(v1[0], j, k);
            glTexCoord2f((k) * scaleFactor, (j + tessYSize) * scaleFactor);
            glVertex3f(v2[0], j + tessYSize, k);
            glTexCoord2f((k + tessZSize) * scaleFactor, (j + tessYSize) * scaleFactor);
            glVertex3f(v3[0], j + tessYSize, k + tessZSize);
            glTexCoord2f((k + tessZSize) * scaleFactor, (j) * scaleFactor);
            glVertex3f(v4[0], j, k + tessZSize);
            glEnd();
        }
    }

    //Purple Ceil
    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[textureCreator->ceilingIndex]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glColor3f(1.0, 0.0, 1.0);
    v1 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v4 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v2 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    for (float i = v3[0]; i < v1[0] - tessXSize; i += tessXSize) {
        for (float k = v3[2]; k < v1[2]; k += tessZSize) {
            glBegin(GL_POLYGON);
            glTexCoord2f((i + tessXSize) * scaleFactor, (k + tessZSize) * scaleFactor);
            glVertex3f(i + tessXSize, v1[1], k + tessZSize);
            glTexCoord2f((i) * scaleFactor, (k + tessZSize) * scaleFactor);
            glVertex3f(i, v4[1], k + tessZSize);
            glTexCoord2f((i) * scaleFactor, (k) * scaleFactor);
            glVertex3f(i, v3[1], k);
            glTexCoord2f((i + tessXSize) * scaleFactor, (k) * scaleFactor);
            glVertex3f(i + tessXSize, v2[1], k);
            glEnd();
        }
    }

    //Yellow floor
    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[textureCreator->floorIndex]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glColor3f(1.0, 1.0, 0.0);
    v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v3 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));

    tessXSize = abs(v1[0] - v3[0]) / (tessX);
    tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    for (float i = v3[0]; i < v1[0] - tessXSize; i += tessXSize) {
        for (float k = v3[2]; k < v1[2]; k += tessZSize) {
            glBegin(GL_POLYGON);
            glTexCoord2f((i + tessXSize) * scaleFactor, (k + tessZSize) * scaleFactor);
            glVertex3f(i + tessXSize, v1[1], k + tessZSize);
            glTexCoord2f((i + tessXSize) * scaleFactor, (k) * scaleFactor);
            glVertex3f(i + tessXSize, v2[1], k);
            glTexCoord2f((i) * scaleFactor, (k) * scaleFactor);
            glVertex3f(i, v3[1], k);
            glTexCoord2f((i) * scaleFactor, (k + tessZSize) * scaleFactor);
            glVertex3f(i, v4[1], k + tessZSize);
            glEnd();
        }
    }
    glEnable(GL_CULL_FACE);
    glBindTexture(GL_TEXTURE_2D, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void ShapeCreator::createTorch(unsigned long long frame) {
    glDisable(GL_CULL_FACE);

    int fireNum = frame % 20 + (6 + 3);
    float fireWidth = 4;
    float fireHeight = 5;
    glPushMatrix();
    glTranslatef(0, -1.5, 0);
    glPushMatrix();
    glTranslatef(0, 1.3, 0);
    glRotatef(-45, 1, 0, 0);
    glColor3f(165.0 / 255.0, 42.0 / 255.0, 42.0 / 255.0);
    createCylinder(0, 0.5, 2, 10, 10);
    glPopMatrix();

    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3f(1, 1, 1);

    glPushMatrix();
    glTranslatef(-fireWidth / 2, 2, 2);
    createTexturedPlane(0, 0, fireWidth, fireHeight, 0, 0, 1, 1, true,
                        textureCreator->textures[fireNum]);
    glPopMatrix();
    glPopMatrix();
    glDisable(GL_BLEND);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
};


////TODO DISABLE LIGHT 1
void ShapeCreator::createTunnel(float width, float height, float depth, int tessX, int tessY, int tessZ) {
    glPushMatrix();
    glPushMatrix();
//    glScalef(1, 1.5, 1.5);
//    createSemiCylinder(depth, width, tessX, tessY, tessZ);
    glTranslatef(0, -depth / 10, 0);
    glScalef(1, 1.1, 1);
    createSemiCylinder2(depth / 2, width - 1, tessX, tessY, tessZ, textureCreator->textures[textureCreator->wallIndex]);
    glPopMatrix();
    glDisable(GL_CULL_FACE);
    //Yellow floor
    glColor3f(1.0, 1.0, 1.0);
    glm::vec3 v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    glm::vec3 v2 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    glm::vec3 v3 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    glm::vec3 v4 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    //Normal of rect
    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(normal));
    float tessXSize = abs(v1[0] - v3[0]) / (tessX);
    float tessZSize = abs(v1[2] - v3[2]) / (tessZ);
    float scaleFactor = width / tessX / 50;
    glTranslatef(depth / 2 + 10, 0, 0);

    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[textureCreator->floorIndex]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mMidSpec);
    for (float i = v3[0]; i < v1[0]; i += tessXSize) {
        for (float k = v3[2]; k < v1[2] - tessZSize; k += tessZSize) {
            glBegin(GL_POLYGON);
            glTexCoord2f((i + tessXSize) * scaleFactor, (k + tessZSize) * scaleFactor);
            glVertex3f(i + tessXSize, v1[1], k + tessZSize);
            glTexCoord2f((i + tessXSize) * scaleFactor, (k) * scaleFactor);
            glVertex3f(i + tessXSize, v2[1], k);
            glTexCoord2f((i) * scaleFactor, (k) * scaleFactor);
            glVertex3f(i, v3[1], k);
            glTexCoord2f((i) * scaleFactor, (k + tessZSize) * scaleFactor);
            glVertex3f(i, v4[1], k + tessZSize);
            glEnd();
        }
    }
    glPopMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mspec);
    glEnable(GL_CULL_FACE);
    glBindTexture(GL_TEXTURE_2D, 0);
}


void ShapeCreator::createTessCube(float width, float height, float depth, int tessX, int tessY, int tessZ) {
    glBindTexture(GL_TEXTURE_2D, 0);

////   North Wall White
    //Coordinates
    glm::vec3 v1 = {-1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    glm::vec3 v4 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    glm::vec3 v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    glm::vec3 v2 = {-1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
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
            glVertex3f(i, j + tessYSize, v4[2]);
            glVertex3f(i + tessXSize, j + tessYSize, v3[2]);
            glVertex3f(i + tessXSize, j, v2[2]);
            glEnd();
        }
    }

    ////East Wall Red
    glColor3f(1.0, 0.0, 0.0);
    //Coordinates
    v1 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v2 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, -1.0 * depth / 2};
    v4 = {1.0 * width / 2, 0.0 * height, -1.0 * depth / 2};
    //Normal of rect
    normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
    glNormal3fv(glm::value_ptr(-normal));

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
    v1 = {-1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
    v4 = {-1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v3 = {1.0 * width / 2, 1.0 * height, 1.0 * depth / 2};
    v2 = {1.0 * width / 2, 0.0 * height, 1.0 * depth / 2};
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
            glVertex3f(v4[0], j, k + tessZSize);
            glVertex3f(v3[0], j + tessYSize, k + tessZSize);
            glVertex3f(v2[0], j + tessYSize, k);
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
            glVertex3f(i, v4[1], k + tessZSize);
            glVertex3f(i, v3[1], k);
            glVertex3f(i + tessXSize, v2[1], k);
            glEnd();
        }
    }
    glEnable(GL_CULL_FACE);
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
            ////Generate random number between 0 and amplitude
            float randomNumber = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / amplitude));
            tempHeightsGenerated[i][k] = randomNumber;
        }
    }

    for (int i = width / 2; i < width / 2 + (width / 5 * 2) + 1; i++) {
        for (int k = depth / 2 - depth / 5; k < depth / 2 + depth / 5 + 1; k++) {
            tempHeightsGenerated[i][k] = 0;
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

            float corners = (tempHeightsGenerated[n1][m1] + tempHeightsGenerated[n1][m2] +
                             tempHeightsGenerated[n2][m1] + tempHeightsGenerated[n2][m2]) / (4 * 6.0);

            float consecutive = (tempHeightsGenerated[n1][k] + tempHeightsGenerated[n2][k] +
                                 tempHeightsGenerated[i][m1] + tempHeightsGenerated[i][m2]) / (4 * 3.0);

            float center = tempHeightsGenerated[i][k] / 3.0;

            heightsGenerated[i][k] = corners + consecutive + center;
//            heightsGenerated[i][k]  = tempHeightsGenerated[i][k] ;
        }
    }

    glBindTexture(GL_TEXTURE_2D, 0);

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


void ShapeCreator::createTessilatedTerrain(float width, float depth, int tessX, int tessZ) {
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

    glColor3f(1, 1, 1);

//    glSamplerParameteri(textureCreator->samplerId, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glSamplerParameteri(textureCreator->samplerId, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glBindTexture(GL_TEXTURE_2D, textureCreator->grassIndex + 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mLowSpec);
//    GLfloat lowShininess2[] = {10000};
//    glMaterialfv(GL_FRONT, GL_SHININESS, lowShininess2);

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
                    glm::vec3 vD = {i + n + tessXSize, heightAtn0m1, k + m + tessZSize};
                    glm::vec3 vC = {i + n, heightAtn1m0, k + m + tessZSize};
                    glm::vec3 vB = {i + n, heightAtn1m1, k + m};

                    float scaleFactor = 2;

//                    if (!(k > depth / 2 - 1 && k < depth / 2 + 1 && i > width / 2 - 1 && k < width / 2 + 1)) {
                    normal = glm::normalize(glm::cross(vB - vA, vC - vB));
                    glNormal3fv(glm::value_ptr(normal));
                    glBegin(GL_POLYGON);
                    glTexCoord2f((n + tessXSize) * scaleFactor, m * scaleFactor);
                    glVertex3f(vA.x, vA.y, vA.z);
                    glTexCoord2f(n * scaleFactor, m * scaleFactor);
                    glVertex3f(vB.x, vB.y, vB.z);
                    glTexCoord2f(n * scaleFactor, (m + tessZSize) * scaleFactor);
                    glVertex3f(vC.x, vC.y, vC.z);
                    glEnd();

                    normal = glm::normalize(glm::cross(vC - vA, vD - vC));
                    glNormal3fv(glm::value_ptr(normal));
                    glBegin(GL_POLYGON);
                    glTexCoord2f((n + tessXSize) * scaleFactor, m * scaleFactor);
                    glVertex3f(vA.x, vA.y, vA.z);
                    glTexCoord2f(n * scaleFactor, (m + tessZSize) * scaleFactor);
                    glVertex3f(vC.x, vC.y, vC.z);
                    glTexCoord2f((n + tessXSize) * scaleFactor, (m + tessZSize) * scaleFactor);
                    glVertex3f(vD.x, vD.y, vD.z);
                    glEnd();
//                    }
                }
            }
        }
    }
//    GLfloat mspec[] = {1, 1, 1, 1.0f};
    glMaterialfv(GL_FRONT, GL_SPECULAR, mspec);
//    GLfloat shininess2[] = {50};
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);
    glBindTexture(GL_TEXTURE_2D, 0);
//    glSamplerParameteri(textureCreator->samplerId, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//    glSamplerParameteri(textureCreator->samplerId, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void ShapeCreator::createTexturedPlane(float x, float y, float width, float height, float tu, float tv, float tWidth,
                                       float tHeight, bool blend, GLuint texture) {
//    glBindTexture(GL_TEXTURE_2D, 0);
//    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[index]);
//    GLfloat verts[] = {x, y, x + w, y, x + w, y + h, x, y + h};

    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_POLYGON);
    glNormal3f(0, 0, 1);
    glTexCoord2f(tu, tv);
    glVertex3f(x, y, 0);
    glTexCoord2f(tu + tWidth, tv);
    glVertex3f(x + width, y, 0);
    glTexCoord2f(tu + tWidth, tv + tHeight);
    glVertex3f(x + width, y + height, 0);
    glTexCoord2f(tu, tv + tHeight);
    glVertex3f(x, y + height, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}

////TODO Scrap?
void ShapeCreator::createFigurine() {
    glBindTexture(GL_TEXTURE_2D, 0);
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
        createCube(1. + ((i + 1) * (0.05 * neg)) + offset, 0.1, 1 + ((i + 1) * (0.05 * neg)) + offset, 0, 0, 0, 0, 0);
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
    glBindTexture(GL_TEXTURE_2D, 0);

}


void ShapeCreator::createCube(float w, float h, float d, float x, float y, float z, bool shadow, GLuint texture) {
    glColor3f(1.0, 1.0, 1.0);
    if (shadow) glColor4f(0, 0, 0, 0.5);

    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_POLYGON);
    glNormal3f(0, 0, 1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glEnd();

    //East Wall
    if (texture == 0)
        glColor3f(1.0, 0.0, 0.0);
    if (shadow) glColor4f(0, 0, 0, 0.5);

    glBegin(GL_POLYGON);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glEnd();

    //South Wall Green
    if (texture == 0) glColor3f(0.0, 1.0, 0.0);
    if (shadow) glColor4f(0, 0, 0, 0.5);
    glBegin(GL_POLYGON);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glEnd();

    //West Wall Blue
    if (texture == 0)
        glColor3f(0.0, 0.0, 1.0);
    if (shadow) glColor4f(0, 0, 0, 0.5);
    glBegin(GL_POLYGON);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glEnd();

    //Purple Ceil
    if (texture == 0)
        glColor3f(1.0, 0.0, 1.0);
    if (shadow) glColor4f(0, 0, 0, 0.5);
    glBegin(GL_POLYGON);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, -1.0 * d / 2 + z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glEnd();

    //Yellow floor
    if (texture == 0)
        glColor3f(1.0, 1.0, 0.0);
    if (shadow) glColor4f(0, 0, 0, 0.5);
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, 0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, -1.0 * d / 2 + z);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
}


void ShapeCreator::createSphere(GLdouble radius, GLint slices, GLint stacks) {
    glBindTexture(GL_TEXTURE_2D, 0);
    GLUquadric *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluSphere(quadric, radius, slices, stacks);
}

void ShapeCreator::createSemiCylinder2(float rad, float length, int tessX, int tessY, int tessZ, GLuint texture) {
    glPushMatrix();
//    glTranslatef(-rad, 0, 0);
//    glRotatef(90, 0, 1, 0);
    glDisable(GL_CULL_FACE);
    float scaleFactor = 0.1;
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    int numberOfSides = 100;
    for (int x = 0; x < length; x++) {
        for (float t = 0; t < M_PI; t += M_PI / numberOfSides) {
            float z = rad * cos(t);
            float y = rad * sin(t);
            float z2 = rad * cos(t + M_PI / numberOfSides);
            float y2 = rad * sin(t + M_PI / numberOfSides);

            glm::vec3 v1 = {x, y, z};
            glm::vec3 v2 = {x, y2, z2};
            glm::vec3 v3 = {x + 1, y2, z2};
            glm::vec3 v4 = {x + 1, y, z};

            glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
            glNormal3fv(glm::value_ptr(normal));

            glBegin(GL_POLYGON);
            glTexCoord2f((v1[0]) * scaleFactor, (v1[2]) * scaleFactor);
            glVertex3f(v1[0], v1[1], v1[2]);
            glTexCoord2f((v2[0]) * scaleFactor, (v2[2]) * scaleFactor);
            glVertex3f(v2[0], v2[1], v2[2]);
            glTexCoord2f((v3[0]) * scaleFactor, (v3[2]) * scaleFactor);
            glVertex3f(v3[0], v3[1], v3[2]);
            glTexCoord2f((v4[0]) * scaleFactor, (v4[2]) * scaleFactor);
            glVertex3f(v4[0], v4[1], v4[2]);
            glEnd();
        }
    }
    glEnable(GL_CULL_FACE);
    glPopMatrix();
}

void ShapeCreator::createSemiCylinder(float rad, float length, int tessX, int tessY, int tessZ) {
    //TODO Clean up outside also visible with culling. Triangles in both directions?
    glDisable(GL_CULL_FACE);
    glPushMatrix();
    int numberOfSide = 100;
//    int numberOfSide = rad;
//    if(numberOfSide % 2 == 1){
//        numberOfSide +=1;
//    }
    glTranslatef(0, 0, rad / 4);

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
                glNormal3fv(glm::value_ptr(normal));
                glBegin(GL_POLYGON);
                glVertex3f(v1[0], v1[1], v1[2]);
                glVertex3f(v4[0], v4[1], v4[2]);
                glVertex3f(v3[0], v3[1], v3[2]);
                glVertex3f(v2[0], v2[1], v2[2]);
                glEnd();
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
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void ShapeCreator::createCylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks) {
    GLUquadric *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluCylinder(quadric, base, top, height, slices, stacks);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void ShapeCreator::createDisk(GLdouble inner, GLdouble outer, GLint slices, GLint loops) {

    GLUquadric *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluDisk(quadric, inner, outer, slices, loops);
    glBindTexture(GL_TEXTURE_2D, 0);

}

bool ShapeCreator::getOBJData(std::string fp, std::vector<float> &out_vertices,
                              std::vector<float> &out_uvs,
                              std::vector<float> &out_normals) {

    string cp = std::experimental::filesystem::current_path();

    std::vector<GLuint> vertexIndices, uvIndices, normalIndices;
    std::vector<float> temp_vertices2;
    std::vector<std::array<float, 2>> temp_uvs2;
    std::vector<float> tempNormals;

    fp = cp.append(fp);

    const char *path = fp.c_str();

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        qDebug() << "Cannot open object file !";
        return false;
    }

    ////Loop over all of file until EOF to get of OBJ data
    while (1) {
        char lineHeader[128];
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break;

        ////If vertex data is found
        if (strcmp(lineHeader, "v") == 0) {
            float vertexX;
            float vertexY;
            float vertexZ;
            ///Get vertexs and add to temporary vertex array
            fscanf(file, "%f %f %f\n", &vertexX, &vertexY, &vertexZ);
            temp_vertices2.push_back(vertexX);
            temp_vertices2.push_back(vertexY);
            temp_vertices2.push_back(vertexZ);
        }
            ////If vertex texture data is found add UV coordinates to temporary UV array
        else if (strcmp(lineHeader, "vt") == 0) {
            float uvU;
            float uvV;
            fscanf(file, "%f %f\n", &uvU, &uvV);
            std::array<float, 2> temp = {uvU, uvV};
            temp_uvs2.push_back(temp);

        }
            ////If vertex normal data is found add normal data to temporary normal array
        else if (strcmp(lineHeader, "vn") == 0) {
            float normalX;
            float normalY;
            float normalZ;
            fscanf(file, "%f %f %f\n", &normalX, &normalY, &normalZ);
            tempNormals.push_back(normalX);
            tempNormals.push_back(normalY);
            tempNormals.push_back(normalZ);
        }
            ////If face data is found add the 3 vertex indices, 3 UV indices and 3 normal indices to correct arrays.
            ////A face is always made up of triangles as as OBJ file has been triangulated beforehand
        else if (strcmp(lineHeader, "f") == 0) {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                 &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2],
                                 &normalIndex[2]);

            if (matches != 9) {
                printf("File can't be read by our simple parser : ( Try exporting with other options\n");
                return false;
            }
            // -1 to 0 index
            vertexIndices.push_back(vertexIndex[0] - 1);
            vertexIndices.push_back(vertexIndex[1] - 1);
            vertexIndices.push_back(vertexIndex[2] - 1);
            uvIndices.push_back(uvIndex[0] - 1);
            uvIndices.push_back(uvIndex[1] - 1);
            uvIndices.push_back(uvIndex[2] - 1);
            normalIndices.push_back(normalIndex[0] - 1);
            normalIndices.push_back(normalIndex[1] - 1);
            normalIndices.push_back(normalIndex[2] - 1);
        }

    }
    ////Once all vertex, UV, normal and face data has been obtain sort each data in order stated by face indices
    for (unsigned int i = 0; i < vertexIndices.size(); i++) {
        unsigned int vertexIndex = vertexIndices[i];
        float vertex2x, vertex2y, vertex2z;
        vertex2x = temp_vertices2[vertexIndex * 3 + 0];
        vertex2y = temp_vertices2[vertexIndex * 3 + 1];
        vertex2z = temp_vertices2[vertexIndex * 3 + 2];
        out_vertices.push_back(vertex2x);
        out_vertices.push_back(vertex2y);
        out_vertices.push_back(vertex2z);
    }
    for (unsigned int i = 0; i < uvIndices.size(); i++) {
        unsigned int uvIndex = uvIndices[i];
        float uv2U, uv2V;
        uv2U = temp_uvs2[uvIndex][0];
        uv2V = temp_uvs2[uvIndex][1];
        out_uvs.push_back(uv2U);
        out_uvs.push_back(uv2V);
    }
    for (unsigned int i = 0; i < normalIndices.size(); i++) {
        unsigned int normalIndex = normalIndices[i];
        float normal2x, normal2y, normal2z;
        normal2x = tempNormals[normalIndex * 3 + 0];
        normal2y = tempNormals[normalIndex * 3 + 1];
        normal2z = tempNormals[normalIndex * 3 + 2];
        out_normals.push_back(normal2x);
        out_normals.push_back(normal2y);
        out_normals.push_back(normal2z);
    }

    glBindTexture(GL_TEXTURE_2D, 0);

    return true;
}

void ShapeCreator::createGyro() {
    float frameRad = 4;
    float frameWidth = 0.2;

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    ////Frame
    createTorus(frameRad, frameWidth, 50, 50);

    ////Bearing 1 Outer
    glPushMatrix();
    glTranslatef(frameRad - frameWidth - 0.2, 0, 0);
    glRotatef(90, 0, 1, 0);
    createCylinder(0.1, 0.1, 0.3, 10, 10);
    glPopMatrix();
    ////Bearing 2 Outer
    glPushMatrix();
    glTranslatef(-frameRad + frameWidth, 0, 0);
    glRotatef(90, 0, 1, 0);
    createCylinder(0.1, 0.1, 0.3, 10, 10);
    glPopMatrix();

    ////Gimbal1
    glPushMatrix();
    float gimbal1Rad = frameRad - (frameWidth) * 2 - 0.1;
    glRotatef(gimbal1Turning, 1, 0, 0);
    createTorus(gimbal1Rad, 0.2, 50, 50);

    ////Bearing 3 Inner
    glPushMatrix();
    glTranslatef(0, gimbal1Rad - frameWidth, 0);
    glRotatef(90, 1, 0, 0);
    createCylinder(0.1, 0.1, 0.3, 10, 10);
    glPopMatrix();

    ////Bearing 4 Inner
    glPushMatrix();
    glTranslatef(0, -gimbal1Rad + frameWidth + 0.2, 0);
    glRotatef(90, 1, 0, 0);
    createCylinder(0.1, 0.1, 0.3, 10, 10);
    glPopMatrix();
    glPushMatrix();
    float gimbal2Rad = gimbal1Rad - (frameWidth) * 2 - 0.1;
    glRotatef(gimbal1Turning, 0, 1, 0);
    createTorus(gimbal2Rad, 0.2, 50, 50);
    glPushMatrix();

    ////Axle
    glPushMatrix();
    glTranslatef(-gimbal2Rad + frameWidth - 0.1, 0, 0);
    glRotatef(90, 0, 1, 0);
    createCylinder(0.1, 0.1, gimbal2Rad * 2, 10, 10);
    glPopMatrix();
    glPushMatrix();

    ////Gyro
    glRotatef(gyroTurning, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    float gyroHeight = 0.8;
    int gyroSlices = 10;
    glTranslatef(0, 0, -gyroHeight / 2);
    glRotatef(180, 0, 1, 0);
    createDisk(0, gimbal2Rad - 0.5, gyroSlices, 10);
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, gyroHeight);
    createDisk(0, gimbal2Rad - 0.5, gyroSlices, 10);
    glTranslatef(0, 0, -gyroHeight);
    createCylinder(gimbal2Rad - 0.5, gimbal2Rad - 0.5, gyroHeight, gyroSlices, gyroSlices);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    ////Stand
    glPushMatrix();
    glTranslatef(0, -frameRad - frameWidth, 0);
    glRotatef(90, 1, 0, 0);
    glPushMatrix();
    glRotatef(180, 1, 0, 0);
    createDisk(0, gimbal2Rad - 0.5, gyroSlices, 10);
    glPopMatrix();
    createCylinder(gimbal2Rad - 0.5, frameRad - 0.5, gyroHeight, gyroSlices, gyroSlices);
    glTranslatef(0, 0, gyroHeight);
    createDisk(0, frameRad - 0.5, gyroSlices, 10);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void ShapeCreator::createDesk() {
    glColor3f(1, 0, 0);

    glPushMatrix();
    glTranslatef(5, 0, 2);
    createCube(0.5, 4, 0.5, 0, 0, 0, 0, textureCreator->textures[textureCreator->woodIndex]);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-5, 0, 2);
    createCube(0.5, 4, 0.5, 0, 0, 0, 0, textureCreator->textures[textureCreator->woodIndex]);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(5, 0, -2);
    createCube(0.5, 4, 0.5, 0, 0, 0, 0, textureCreator->textures[textureCreator->woodIndex]);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-5, 0, -2);
    createCube(0.5, 4, 0.5, 0, 0, 0, 0, textureCreator->textures[textureCreator->woodIndex]);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 4, 0);
    createCube(10 + 2, 0.25, 4 + 2, 0, 0, 0, 0, textureCreator->textures[textureCreator->woodIndex]);
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);

}

void ShapeCreator::createEdgeCylinder(float rad, float height, float slices, float stacks) {
    glPushMatrix();
    glTranslatef(0, height, 0);
    glRotatef(90, 1, 0, 0);
    glPushMatrix();
    glRotatef(180, 1, 0, 0);
    createDisk(0, rad, slices, stacks);
    glPopMatrix();
    createCylinder(rad, rad, height, slices, stacks);
    glTranslatef(0, 0, height);
    createDisk(0, rad, slices, stacks);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void ShapeCreator::createGeisha(bool black) {
    ////Draw geisha
    if (black) {
        glColor3f(0, 0, 0);
    } else {
        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, textureCreator->textures[6 - 1 + 3]);
    }

    glDisable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
    if (!black) {
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glTexCoordPointer(2, GL_FLOAT, 0, uvsGeisha.data());
    }
    glEnableClientState(GL_NORMAL_ARRAY); //enable normal array
    glPushMatrix();
    glScalef(0.1, 0.1, 0.1);
    glTranslatef(0, 7, 0);
    glVertexPointer(3, GL_FLOAT, 0, verticesGeisha.data());
    glNormalPointer(GL_FLOAT, 0, normalsGeisha.data());
    glDrawArrays(GL_TRIANGLES, 0, verticesGeisha.size() / 3);
    glPopMatrix();
    glDisableClientState(GL_VERTEX_ARRAY);
    if (!black) {
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    glDisableClientState(GL_NORMAL_ARRAY); //enable normal array
    glEnable(GL_CULL_FACE);
}

void ShapeCreator::createStickGeisha(bool black) {
    createGeisha(black);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0.1, 0, -2);
    createCylinder(0.1, 0.1, 5, 50, 50);
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);
}


void ShapeCreator::createPopulatedDesk() {
    ////Desk
    glPushMatrix();
    glScalef(1, 0.5, 1);
    createDesk();
    glPopMatrix();

    ////Turntable
    glPushMatrix();
    glTranslatef(-2.5, 3 + (0.25 * 0.5) - 0.001, 0);
    glPushMatrix();
    glTranslatef(0, -1, 0);
    glRotatef(turnTableRotation, 0, 1, 0);
    createEdgeCylinder(2.5, 0.5, 10, 10);
    glPopMatrix();
    glTranslatef(0, 0.5, 0);
    glScalef(0.2, 0.2, 0.2);
    glPushMatrix();
    glRotatef(turnTableRotation, 0, 1, 0);
    glTranslatef(0, 0, 7);
    createGyro();
    glPopMatrix();
    glPopMatrix();

    ////PC
    glPushMatrix();
    glTranslatef(1.5, 3 + 0.25, 1);
    glScalef(0.5, 0.5, 0.5);
    drawPC();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, 0);
}

void ShapeCreator::drawPC() {
    glBindTexture(GL_TEXTURE_2D, textureCreator->textures[6 - 1 + 1]);
    glColor3f(1.0, 1.0, 1.0);
    glColor4f(1.0, 1.0, 1.0, 1.0);
    ////Apple PC
    glDisable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY); //enable normal array
    glPushMatrix();
    glVertexPointer(3, GL_FLOAT, 0, verticesPC.data());
    glTexCoordPointer(2, GL_FLOAT, 0, uvsPC.data());
    glNormalPointer(GL_FLOAT, 0, normalsPC.data());
    glDrawArrays(GL_TRIANGLES, 0, verticesPC.size() / 3);
//    glDrawElements(GL_TRIANGLES, shapeCreator->vertexIndices.size(), GL_UNSIGNED_INT, shapeCreator->vertexIndices.data());

    ////PC Screen
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glRotatef(-2, 1, 0, 0);
    glTranslatef(-1.33, -0.4, -0.62);
    glScalef(1.8, 1.2, 1);
//    drawTexture(0, 0, 2, 2, 0, 0, 1, 1, true, textureCreator->textures[textureCreator->selectedIndex]);
    createTexturedPlane(0, 0, 2, 2, 0, 0, 1, 1, false, textureCreator->textures[textureCreator->selectedIndex]);
    glPopMatrix();
    glPopMatrix();
    glDisableClientState(GL_VERTEX_ARRAY); //disable the client states again
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void ShapeCreator::createTorus(float outerRadius, float innerRadius, int sides, int rings) {
    glBindTexture(GL_TEXTURE_2D, 0);
    glColor3f(1, 0, 0);
    float eta, theta, eta2, theta2;
    float diffEta = (M_PI * 2) / sides;
    float diffTheta = (M_PI * 2) / rings;
    float vertexBuffer2[sides * rings * 3];
    int count = 0;
    for (int i = 0; i < rings; i++) {
        theta = diffTheta * i;
        for (int j = 0; j < sides; j++) {
            eta = diffEta * j;
            //main vertex
            glm::vec3 v1;
            //vertex adjacent on next ring
            glm::vec3 v2;
            //vertex on next ring and next side
            glm::vec3 v3;
            //vertex on main ring and next side
            glm::vec3 v4;
            //The four vertices can be used to draw a plane

            int i2 = i + 1;
            int j2 = j + 1;

            if (i == rings - 1)
                i2 = 0;

            if (j == sides - 1)
                j2 = 0;

            theta2 = diffTheta * i2;
            eta2 = diffEta * j2;

            //x
            v1.x = cos(theta) * (outerRadius + cos(eta) * innerRadius);
            //y
            v1.y = sin(theta) * (outerRadius + cos(eta) * innerRadius);
            //z
            v1.z = sin(eta) * innerRadius;

            //x
            v2.x = cos(theta2) * (outerRadius + cos(eta) * innerRadius);
            //y
            v2.y = sin(theta2) * (outerRadius + cos(eta) * innerRadius);
            //z
            v2.z = sin(eta) * innerRadius;

            //x
            v3.x = cos(theta2) * (outerRadius + cos(eta2) * innerRadius);
            //y
            v3.y = sin(theta2) * (outerRadius + cos(eta2) * innerRadius);
            //z
            v3.z = sin(eta2) * innerRadius;

            //x
            v4.x = cos(theta) * (outerRadius + cos(eta2) * innerRadius);
            //y
            v4.y = sin(theta) * (outerRadius + cos(eta2) * innerRadius);
            //z
            v4.z = sin(eta2) * innerRadius;

            glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
            glNormal3fv(glm::value_ptr(normal));
            glBegin(GL_POLYGON);
            glVertex3f(v1.x, v1.y, v1.z);
            glVertex3f(v2.x, v2.y, v2.z);
            glVertex3f(v3.x, v3.y, v3.z);
            glVertex3f(v4.x, v4.y, v4.z);
            glEnd();

//            //x
//            vertexBuffer2[(i * sides * 3) + j * 3 + 0] = cos(theta) * (outerRadius + cos(eta) * innerRadius);
//            //y
//            vertexBuffer2[(i * sides * 3) + j * 3 + 1] = sin(theta) * (outerRadius + cos(eta) * innerRadius);
//            //z
//            vertexBuffer2[(i * sides * 3) + j * 3 + 2] = sin(eta) * innerRadius;
//
        }
    }
    glBindTexture(GL_TEXTURE_2D, 0);
}

////TODO change
//void ShapeCreator::drawTexture(float x, float y, float w, float h,
//                               float tx, float ty, float tw, float th, bool blend, GLuint texture) {
//    glBindTexture(GL_TEXTURE_2D, texture);
//    if (blend) {
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    }
//    glColor3f(1.0, 1.0, 1.0);
//    GLfloat verts[] = {x, y, x + w, y, x + w, y + h, x, y + h};
//    GLfloat tex_coords[] = {tx, ty, tx + tw, ty, tx + tw, ty + th, tx, ty + th};
//
//    glm::vec3 v1 = {x, y, 0};
//    glm::vec3 v2 = {x + w, y, 0};
//    glm::vec3 v3 = {x, y + h, 0};
//
//    ////TODO Normals for screen? Normals Disable atm since screen emits light
//    glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v2));
//    GLfloat normCoords[] = {normal.x, normal.y, normal.z, normal.x, normal.y, normal.z, normal.x, normal.y, normal.z,
//                            normal.x, normal.y, normal.z, normal.x, normal.y, normal.z, normal.x, normal.y, normal.z};
//    glNormal3fv(glm::value_ptr(normal));
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//    glEnableClientState(GL_NORMAL_ARRAY);
//    glVertexPointer(2, GL_FLOAT, 0, verts);
//    glTexCoordPointer(2, GL_FLOAT, 0, tex_coords);
//    glNormalPointer(GL_FLOAT, 0, normCoords);
//    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//    glDisableClientState(GL_VERTEX_ARRAY);
//    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//    glDisableClientState(GL_NORMAL_ARRAY);
//
//    if (blend) {
//        glDisable(GL_BLEND);
//    }
//    glBindTexture(GL_TEXTURE_2D, 0);
//}