#ifndef SCENE_ShapeCreator_H
#define SCENE_ShapeCreator_H

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
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


const unsigned int N_X_IMAGE = 512;
const unsigned int N_Y_IMAGE = 512;
const unsigned int N_COLOR = 3;


class ShapeCreator { //
public:
    ShapeCreator(QWidget *parent);

    void walls(float w, float h, float d, int tX, int tY, int tZ);

    void createTessCube(float width, float height, float depth, int tessX, int tessY, int tessZ);

    void createCube(float w, float h, float d, float x, float y, float z);

    void createSphere(GLdouble radius, GLint slices, GLint stacks);

    void createCylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);

    void createSemiCylinder(float rad, float length, int x, int y, int z);

    void createTessTriPlane(float width, float depth, int tessX, int tessZ);

    void heightGenerator(float x, float z);

    void loadTextures();

    void imageLoader();

    void drawTextPlane(float w, float h);

    QWidget parent;
    static constexpr int planeWidth = 100;
    static constexpr int planeDepth = 100;
    float amplitude = 4;
    int planeXTess = 50;
    int planeZTess = 50;
    float heightsGenerated[planeWidth + 1][planeDepth + 1];





    static constexpr int textNum = 6;
    int numberOfTextures;
    //    GLubyte image[N_X_IMAGE][N_Y_IMAGE][N_COLOR];
    QList<QImage> p_qimage;
    GLuint MyTexture[6];
    GLuint singText;

    unsigned int imageWidth[textNum];
    unsigned int imageHeight[textNum];
    unsigned int imageSize[textNum];
    QOpenGLShaderProgram *program = nullptr;
    QOpenGLBuffer vbo;

protected:

private:
};

#endif //SCENE_STB_IMAGE_H

