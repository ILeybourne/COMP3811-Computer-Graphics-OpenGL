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

void TextureCreator::swapActiveTexture(int textureNumber) {
    if (textureNumber <= GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS && textureNumber >= 0) {
        glActiveTexture(GL_TEXTURE0 + textureNumber);
//        qDebug() << "unit changed";
    } else {
        qDebug() << "Error active texture number is out of bounds!";
    }

}

void TextureCreator::imageLoader(QStringList sImage, GLuint texture[]) {
    numberOfTextures = sImage.size();

    ////TODO Clean up variables
    int nChannels[numberOfTextures];
    unsigned int imageWidth[constNumberOfTextures];
    unsigned int imageHeight[constNumberOfTextures];
    unsigned int imageSize[constNumberOfTextures];

    glGenTextures(numberOfTextures, texture);

    for (int i = 0; i < numberOfTextures; i++) {
        pQImage.push_back(QImage(sImage[i]));
        imageWidth[i] = pQImage[i].width();
        imageHeight[i] = pQImage[i].height();
        imageSize[i] = imageWidth[i] * imageHeight[i];

        nChannels[i] = 3;
        if (sImage[i].endsWith("png")) {
            nChannels[i] = 4;
        }

        glBindTexture(GL_TEXTURE_2D, texture[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        GLint format;

        if (nChannels[i] == 3) {
            pQImage[i] = pQImage[i].mirrored(false,true).convertToFormat(QImage::Format_RGB888);
            format = GL_RGB;
            glTexImage2D(GL_TEXTURE_2D,
                         0, format, imageWidth[i], imageHeight[i], 0, format, GL_UNSIGNED_BYTE,
                         pQImage[i].constBits());
        } else {
            pQImage[i] = pQImage[i].mirrored(false,true).convertToFormat(QImage::Format_RGBA8888);

            format = GL_RGBA;
            glTexImage2D(GL_TEXTURE_2D,
                         0, format, imageWidth[i], imageHeight[i], 0, format, GL_UNSIGNED_BYTE,
                         pQImage[i].constBits());
        }
    }
}

