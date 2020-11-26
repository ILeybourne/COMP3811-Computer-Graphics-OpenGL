#include "CreateShapes.h"

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
    glBegin(GL_POLYGON);
    glNormal3f(0, 0, 1);
    glVertex3f(-1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(-1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 1.0 * h + y, 1.0 * d / 2 + z);
    glVertex3f(1.0 * w / 2 + x, 0.0 * h + y, 1.0 * d / 2 + z);
    glEnd();

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
