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
#include <string>
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include "TextureCreator.h"


using namespace std;

//const unsigned int N_X_IMAGE = 512;
//const unsigned int N_Y_IMAGE = 512;
//const unsigned int N_COLOR = 3;


class ShapeCreator { //
public:
    ShapeCreator(QWidget *parent);

    void sky(float w, float h, float d, int tX, int tY, int tZ);

    void walls(float w, float h, float d, int tX, int tY, int tZ);

    void createTessCube(float width, float height, float depth, int tessX, int tessY, int tessZ);

    void createCube(float w, float h, float d, float x, float y, float z, bool shadow);

    void createSphere(GLdouble radius, GLint slices, GLint stacks);

    void createCylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);

    void createSemiCylinder(float rad, float length, int x, int y, int z);

    void createTessTriPlane(float width, float depth, int tessX, int tessZ);

    void heightGenerator(float x, float z);

    void loadTextures();

    void imageLoader(QStringList sImage, GLuint texture[]);

    void drawTextPlane(float w, float h, int index);

    float interpolation(float x, float z, float c);

    float interpolateAt(float x, float z);

    void createFigurine();

    typedef struct Model {
        int vertices;
        int positions;
        int texels;
        int normals;
        int faces;
    } Model;

    Model getOBJinfo(std::string fp);

    bool getOBJData(std::string fp,
                    std::vector<float> &out_vertices,
                    std::vector<float>
                    &out_uvs,
                    std::vector<float> &out_normals
    );

//    std::vector<GLuint> vertexIndices, uvIndices, normalIndices;
    std::vector <glm::vec3> temp_vertices;
    std::vector <glm::vec2> temp_uvs;
    std::vector <glm::vec3> temp_normals;
//    std::vector<float> temp_vertices2;
//    std::vector <std::array<float, 2>> temp_uvs2;
//    std::vector <float> tempNormals;


    std::vector <std::array<float, 3>> vertices;
    std::vector <std::array<float, 2>> uvs;
    std::vector <std::array<float, 3>> normals; // Won't be used at the moment.

    std::vector<GLfloat> verticesPC;
    std::vector<GLfloat> uvsPC;
    std::vector<GLfloat> normalsPC;

    std::vector<GLfloat> verticesGeisha;
    std::vector<GLfloat> uvsGeisha;
    std::vector<GLfloat> normalsGeisha;


    void drawTexture(float x, float y, float w, float h,
                              float tx, float ty, float tw, float th, bool blend ,GLuint texture);



    QWidget parent;
    static constexpr int planeWidth = 10;
    static constexpr int planeDepth = 10;
    float amplitude = 10;
    int planeXTess = 20;
    int planeZTess = 20;
    float heightsGenerated[planeWidth + 1][planeDepth + 1];

    TextureCreator *textureCreator;


//    int numberOfTextures;
//    QList <QImage> p_qimage;
//    static constexpr int textNum = 8;
//
//    GLuint MyTexture[textNum];
//
//    unsigned int imageWidth[textNum];
//    unsigned int imageHeight[textNum];
//    unsigned int imageSize[textNum];
//    QOpenGLShaderProgram *program = nullptr;
//    QOpenGLBuffer vbo;

protected:

private:
};

#endif //SCENE_STB_IMAGE_H

