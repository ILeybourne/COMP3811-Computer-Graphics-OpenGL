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


class TextureCreator {
public:
    TextureCreator(QWidget *parent);

    void imageLoader(QStringList sImage, GLuint texture[]);



    int numberOfTextures;
    QList <QImage> pQImage;
    static constexpr int textNum = 8;

    GLuint MyTextures[textNum];

    unsigned int imageWidth[textNum];
    unsigned int imageHeight[textNum];
    unsigned int imageSize[textNum];

protected:

private:
};

#endif //SCENE_STB_IMAGE_H

