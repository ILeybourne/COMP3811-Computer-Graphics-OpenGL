#include "TextureCreator.h"

TextureCreator::TextureCreator() {

}

void TextureCreator::imageLoader(QStringList sImage, GLuint texture[]) {
    numberOfTextures = sImage.size();

    //arrays to store channel and image sizes
    int nChannels[numberOfTextures];
    unsigned int imageWidth[constNumberOfTextures];
    unsigned int imageHeight[constNumberOfTextures];

    //Generate textures in memory
    glGenTextures(numberOfTextures, texture);

    //For each image
    for (int i = 0; i < numberOfTextures; i++) {
        //Convert to QImage
        pQImage.push_back(QImage(sImage[i]));
        //and get size
        imageWidth[i] = pQImage[i].width();
        imageHeight[i] = pQImage[i].height();

        //set number of channels
        nChannels[i] = 3;
        if (sImage[i].endsWith("png")) {
            nChannels[i] = 4;
        }

        //Set texture parameters
        glBindTexture(GL_TEXTURE_2D, texture[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

        GLint format;

        //set format based on number of channels
        if (nChannels[i] == 3) {
            pQImage[i] = pQImage[i].mirrored(false, true).convertToFormat(QImage::Format_RGB888);
            format = GL_RGB;
        } else {
            pQImage[i] = pQImage[i].mirrored(false, true).convertToFormat(QImage::Format_RGBA8888);
            format = GL_RGBA;

        }

        //Set texture
        glTexImage2D(GL_TEXTURE_2D,
                     0, format, imageWidth[i], imageHeight[i], 0, format, GL_UNSIGNED_BYTE,
                     pQImage[i].constBits());
    }
}

