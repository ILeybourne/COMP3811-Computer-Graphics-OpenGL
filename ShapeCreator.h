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

//    GLfloat mAmbient[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat mAmbient[4] = {1, 1, 1, 0.0f};
    GLfloat mDiff[4] = {1, 1, 1, 0.0};
    GLfloat mSpec[4] = {1, 1, 1, 0.0f};
    GLfloat mShininess2[1] = {50};
    GLfloat mMidSpec[4] = {0.4, 0.4, 0.4, 1.0f};
    GLfloat mLowSpec[4] = {0.1, 0.2, 0.1, 1.0f};

    void sky(float w, float h, float d);

    void walls(float w, float h, float d, int tX, int tY, int tZ);

    void createTessCube(float width, float height, float depth, int tessX, int tessY, int tessZ);

    void createCube(float w, float h, float d, float x, float y, float z, bool shadow, GLuint texture);

    void createSphere(GLdouble radius, GLint slices, GLint stacks);

    void createCylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);

    void createSemiCylinder(float rad, float length, int x, int y, int z);

    void createSemiCylinder2(float rad, float length, int x, int y, int z, GLuint texture);

    void createTessilatedTerrain(float width, float depth, int tessX, int tessZ);

    void heightGenerator(float x, float z);

    void
    createTexturedPlane(float x, float y, float width, float height, float tu, float tv, float tWidth, float tHeight,
                        bool blend, GLuint texture);

    float interpolation(float x, float z, float c);

    float interpolateAt(float x, float z);

    void createFigurine();


    bool getOBJData(std::string fp,
                    std::vector<float> &out_vertices,
                    std::vector<float>
                    &out_uvs,
                    std::vector<float> &out_normals
    );

//    std::vector <glm::vec3> temp_vertices;
//    std::vector <glm::vec2> temp_uvs;
//    std::vector <glm::vec3> temp_normals;
//
//    std::vector <std::array<float, 3>> vertices;
//    std::vector <std::array<float, 2>> uvs;
//    std::vector <std::array<float, 3>> normals;

    std::vector<GLfloat> verticesPC;
    std::vector<GLfloat> uvsPC;
    std::vector<GLfloat> normalsPC;

    std::vector<GLfloat> verticesGeisha;
    std::vector<GLfloat> uvsGeisha;
    std::vector<GLfloat> normalsGeisha;

//    void drawTexture(float x, float y, float w, float h,
//                              float tx, float ty, float tw, float th, bool blend ,GLuint texture);

    static constexpr int planeWidth = 10;
    static constexpr int planeDepth = 10;

    float amplitude = 10;
    int planeXTess = 20;
    int planeZTess = 20;
    float heightsGenerated[planeWidth + 1][planeDepth + 1];

    TextureCreator *textureCreator;

    void createTorus(float innerRadius, float width, int sides, int rings);

    float turnTableRotation = 0;
    float gimbal1Turning = 0;
    float gimbal2Turning = 0;
    float gyroTurning = 0;

    void createGyro();

    void createEdgeCylinder(float radius, float height, float slices, float stacks);

    void drawPC();

    void createPopulatedDesk();

    void createGeisha(bool black);

    void createStickGeisha(bool black);

    void createTunnel(float width, float height, float depth, int tessX, int tessY, int tessZ);

    void createTorch(unsigned long long frame);


    void createDoorway(float width, float height, float depth, int tessX, int tessY, int tessZ);
protected:
private:

    void createDisk(GLdouble inner, GLdouble outer, GLint slices, GLint loops);

    void createDesk();
};

#endif //SCENE_STB_IMAGE_H
