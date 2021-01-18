#ifndef SCENE_ShapeCreator_H
#define SCENE_ShapeCreator_H

#include <QGLWidget>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <QtGui>
#include <QtCore/QTime>
#include <GL/glu.h>
#include <QtGui>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <QGLWidget>
#include <QOpenGLFunctions>
#include <cstdio>
#include "TextureCreator.h"

using namespace std;

class ShapeCreator { //
public:
    ShapeCreator(QWidget *parent);

    GLfloat mAmbient[4] = {0.4, 0.4, 0.4, 1.0};
    GLfloat mDiff[4] = {0.5, 0.5, 0.5, 1.0};
    GLfloat mSpec[4] = {1, 1, 1, 1.0};
    GLfloat mShininess2[1] = {50};
    GLfloat mHighSpec[4] = {4, 4, 4, 1.0};
    GLfloat mMidSpec[4] = {0.4, 0.4, 0.4, 1.0};
    GLfloat mLowSpec[4] = {0.1, 0.2, 0.1, 1.0};
    GLuint fireNumber;

    void sky(float w, float h, float d);

    void walls(float w, float h, float d, int tX, int tY, int tZ);

    void createTessCube(float width, float height, float depth, int tessX, int tessY, int tessZ);

    void createCube(float w, float h, float d, float x, float y, float z, bool shadow, GLuint texture);

    void createSphere(GLdouble radius, GLint slices, GLint stacks, GLuint texture);

    void createCylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks, GLuint texture);

    void createSemiCylinder(float rad, float length, int tessX, int tessY, int tessZ, GLuint texture);

    void createTessilatedTerrain(float width, float depth, int tessX, int tessZ);

    void heightGenerator(int seedNumber);

    void
    createTexturedPlane(float x, float y, float width, float height, float tu, float tv, float tWidth, float tHeight,
                        bool blend, GLuint texture);

    float interpolation(float x, float z, float f);

    float interpolateAt(float x, float z);

    bool getOBJData(std::string fp,
                    std::vector<float> &out_vertices,
                    std::vector<float>
                    &out_uvs,
                    std::vector<float> &out_normals
    );

    std::vector<GLfloat> verticesPC;
    std::vector<GLfloat> uvsPC;
    std::vector<GLfloat> normalsPC;

    std::vector<GLfloat> verticesGeisha;
    std::vector<GLfloat> uvsGeisha;
    std::vector<GLfloat> normalsGeisha;


    int seedNumber = 1;

    static constexpr int planeWidth = 10;
    static constexpr int planeDepth = 10;

    float amplitude = 100;
    int planeXTess = 20;
    int planeZTess = 20;
    float heightsGenerated[planeWidth + 1][planeDepth + 1];
    std::vector<std::array<float, 3>> treePositions;
    std::vector<std::array<float, 2>> treeHeightRad;
    int numberOfTrees = 30;

    TextureCreator *textureCreator;

    void createTorus(float innerRadius, float width, int sides, int rings, GLuint texture);

    float turnTableRotation = 0;
    float gimbal1Turning = 0;
    float gimbal2Turning = 0;
    float gyroTurning = 0;

    void createGyro();

    void createEdgeCylinder(float radius, float height, float slices, float stacks, GLuint texture);

    void drawPC();

    void createPopulatedDesk();

    void createGeisha(bool black);

    void createStickGeisha(bool black);

    void createTunnel(float width, float height, float depth, int tessX, int tessY, int tessZ);

    void createTorch(unsigned long long frame);

    void createDoorway(float width, float height, float depth, int tessX, int tessY, int tessZ);

    void createTree(float height, float rad);

protected:
private:
    void createDisk(GLdouble inner, GLdouble outer, GLint slices, GLint loops, GLuint texture);

    void createDesk();
};

#endif //SCENE_STB_IMAGE_H
