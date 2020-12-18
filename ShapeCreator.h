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

    void imageLoader(QStringList sImage);

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

    bool getOBJData(std::string fp,
                    std::vector<float> &out_vertices,
                    std::vector<float>
                    &out_uvs,
                    std::vector<float> &out_normals
    );

    std::vector<GLuint> vertexIndices, uvIndices, normalIndices;
    std::vector <glm::vec3> temp_vertices;
    std::vector <glm::vec2> temp_uvs;
    std::vector <glm::vec3> temp_normals;
    std::vector<float> temp_vertices2;
    std::vector <std::array<float, 2>> temp_uvs2;
    std::vector <float> temp_normals2;


    std::vector <std::array<float, 3>> vertices;
    std::vector <std::array<float, 2>> uvs;
    std::vector <std::array<float, 3>> normals; // Won't be used at the moment.

    std::vector<GLfloat> vertices3;
    std::vector<GLfloat> uvs3;
    std::vector<GLfloat> normals3; // Won't be used at the moment.
    void drawTexture(float x, float y, float w, float h,
                              float tx, float ty, float tw, float th, bool blend);

    bool getOBJinfo2(std::string fp, std::vector <std::array<float, 3>> &out_vertices,
                     std::vector <std::array<float, 2>> &out_uvs,
                     std::vector <std::array<float, 3>> &out_normals);

//
//    Model apple = {0};
//    apple.vertices = 9555;
//    apple.positions = 3088;
//    apple.texels = 3131;
//    apple.normals = 1292;
//    apple.faces = 3185;

    static constexpr int appleVertices = 9555;
    static constexpr int applePositions = 3088;
    static constexpr int appleTexels = 3131;
    static constexpr int appleNormals = 1292;
    static constexpr int appleFaces = 3185;

    QWidget parent;
    static constexpr int planeWidth = 10;
    static constexpr int planeDepth = 10;
    float amplitude = 10;
    int planeXTess = 20;
    int planeZTess = 20;
    float heightsGenerated[planeWidth + 1][planeDepth + 1];


    int numberOfTextures;
    QList <QImage> p_qimage;
    static constexpr int textNum = 8;
    GLuint MyTexture[textNum];
//    GLuint appleTexture[1];
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

