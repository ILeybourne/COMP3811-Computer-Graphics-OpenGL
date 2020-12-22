#include "TextureCreator.h"
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <QGLWidget>
#include <QtGui>
#include <QOpenGLFunctions>
#include <QtCore/QTime>
#include <cstdio>
#include <cmath>
#include <QColor>

// constructor
TextureCreator::TextureCreator(QWidget *parent) {// constructor
}
// constructor

void TextureCreator::swapActiveTexture(int textureNumber){
    if (textureNumber <= GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS && textureNumber >= 0){
        glActiveTexture(GL_TEXTURE0 + textureNumber);
//        qDebug() << "unit changed";
    }else{
        qDebug() << "Error active texture number is out of bounds!";
    }

}

void TextureCreator::imageLoader(QStringList sImage, GLuint texture[]) {
    qDebug() << sImage.size();
    qDebug() << this->numberOfTextures;

    numberOfTextures = sImage.size();

    qDebug() << "after";


    qDebug() << numberOfTextures;

    int nChannels[numberOfTextures];
    unsigned int imageWidth[constNumberOfTextures];
    unsigned int imageHeight[constNumberOfTextures];
    unsigned int imageSize[constNumberOfTextures];

    glGenTextures(numberOfTextures, texture);

    qDebug() << "generation";

    for (int i = 0; i < numberOfTextures; i++) {
        pQImage.push_back(QImage(sImage[i]));
        imageWidth[i] = pQImage[i].width();
        imageHeight[i] = pQImage[i].height();
        imageSize[i] = imageWidth[i] * imageHeight[i];

        nChannels[i] = 3;
        if (sImage[i].endsWith("png")) {
            qDebug() << "4 chan";
            nChannels[i] = 4;
        }
    }

    for (int i = 0; i < numberOfTextures; i++) {
        unsigned int w = imageWidth[i];
        unsigned int h = imageHeight[i];
        unsigned int s = imageSize[i];
        GLubyte image1d3Chan[w * h * 3];
        GLubyte image1d4Chan[imageWidth[i] * imageHeight[i] * 4];
        if (nChannels[i] == 3) {
            for (unsigned int i_pix = 0; i_pix < imageSize[i]; i_pix++) {
                std::div_t part = std::div((int) i_pix, (int) imageWidth[i]);

                QRgb colVal = pQImage[i].pixel(w - part.rem - 1, part.quot);
                image1d3Chan[3 * s - 3 * i_pix - 3] = qRed(colVal);
                image1d3Chan[3 * s - 3 * i_pix - 2] = qGreen(colVal);
                image1d3Chan[3 * s - 3 * i_pix - 1] = qBlue(colVal);
            }
        } else {
            for (unsigned int i_pix = 0; i_pix < imageSize[i]; i_pix++) {
                std::div_t part = std::div((int) i_pix, (int) imageWidth[i]);
                QRgb colVal = pQImage[i].pixel(imageWidth[i] - part.rem - 1, part.quot);
                image1d4Chan[4 * imageSize[i] - 4 * i_pix - 4] = qRed(colVal);
                image1d4Chan[4 * imageSize[i] - 4 * i_pix - 3] = qGreen(colVal);
                image1d4Chan[4 * imageSize[i] - 4 * i_pix - 2] = qBlue(colVal);
                image1d4Chan[4 * imageSize[i] - 4 * i_pix - 1] = qAlpha(colVal);
            }
        }

        glBindTexture(GL_TEXTURE_2D, texture[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        GLint format;
        if (nChannels[i] == 3) {
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
        qDebug() << i;
    }
    qDebug() << "finished";
}

