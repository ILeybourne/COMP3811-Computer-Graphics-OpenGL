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


using namespace std;

const unsigned int N_X_IMAGE = 512;
const unsigned int N_Y_IMAGE = 512;
const unsigned int N_COLOR = 3;


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

    void imageLoader();

    void drawTextPlane(float w, float h);

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


    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector< glm::vec3 > temp_vertices;
    std::vector< glm::vec2 > temp_uvs;

    std::vector< glm::vec3 > temp_normals;

    std::vector< glm::vec3 > vertices;
    std::vector< glm::vec2 > uvs;
    std::vector< glm::vec3 > normals; // Won't be used at the moment.
    bool getOBJinfo2(std::string fp, std::vector <glm::vec3> &out_vertices,
                     std::vector <glm::vec2> &out_uvs,
                     std::vector <glm::vec3> &out_normals);

//
//    Model apple = {0};
//    apple.vertices = 9555;
//    apple.positions = 3088;
//    apple.texels = 3131;
//    apple.normals = 1292;
//    apple.faces = 3185;

    static constexpr  int appleVertices = 9555;
    static constexpr  int applePositions = 3088;
    static constexpr  int appleTexels = 3131;
    static constexpr  int appleNormals = 1292;
    static constexpr  int appleFaces = 3185;

//    float
//    float applePositions[3088]= {};

    void extractOBJdata(string fp, float positions[][3], float texels[][2], float normals[][3], int faces[][9]);


    QWidget parent;
    static constexpr int planeWidth = 10;
    static constexpr int planeDepth = 10;
    float amplitude = 10;
    int planeXTess = 20;
    int planeZTess = 20;
    float heightsGenerated[planeWidth + 1][planeDepth + 1];


    static constexpr int textNum = 6;
    int numberOfTextures;
    //    GLubyte image[N_X_IMAGE][N_Y_IMAGE][N_COLOR];
    QList <QImage> p_qimage;
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

