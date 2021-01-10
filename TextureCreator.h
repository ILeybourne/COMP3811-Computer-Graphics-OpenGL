#ifndef SCENE_TextureCreator_H
#define SCENE_TextureCreator_H

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
#include <GL/glu.h>
#include <QGLWidget>
#include <QtCore/QTime>
#include "qopenglfunctions.h"
#include <QOpenGLTexture>

using namespace std;

class TextureCreator {
public:
    TextureCreator(QWidget *parent);

    void imageLoader(QStringList sImage, GLuint texture[]);

    QStringList textureStrings = {
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_0_Front+Z.jpg", //0
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_1_Back-Z.jpg",  //1
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_2_Left+X.jpg",  //2
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_3_Right-X.jpg", //3
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_4_Up+Y.jpg",    //4
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_5_Down-Y.jpg",  //5
            "./textureinternet/appleIIe.jpg",                                          //6
            "./textureinternet/mario2.png",                                            //7
            "./textureinternet/pruebas_geisha.jpg",                                    //8
            "./textureinternet/fire/fire_00076.png",                                   //9
            "./textureinternet/fire/fire_00077.png",                                  //10
            "./textureinternet/fire/fire_00078.png",                                  //11
            "./textureinternet/fire/fire_00079.png",                                  //12
            "./textureinternet/fire/fire_00080.png",                                  //13
            "./textureinternet/fire/fire_00081.png",                                  //14
            "./textureinternet/fire/fire_00082.png",                                  //15
            "./textureinternet/fire/fire_00083.png",                                  //16
            "./textureinternet/fire/fire_00084.png",                                  //17
            "./textureinternet/fire/fire_00085.png",                                  //18
            "./textureinternet/fire/fire_00086.png",                                  //19
            "./textureinternet/fire/fire_00087.png",                                  //20
            "./textureinternet/fire/fire_00088.png",                                  //21
            "./textureinternet/fire/fire_00089.png",                                  //22
            "./textureinternet/fire/fire_00090.png",                                  //23
            "./textureinternet/fire/fire_00091.png",                                  //24
            "./textureinternet/fire/fire_00092.png",                                  //25
            "./textureinternet/fire/fire_00093.png",                                  //26
            "./textureinternet/fire/fire_00094.png",                                  //27
            "./textureinternet/fire/fire_00095.png",                                  //28
            "./textureinternet/Marc_Dekamps.ppm",                                     //29
            "./textureinternet/Mercator-projection.ppm",                              //30
            "./textureinternet/grass_rough2.png",                                     //31,
            "./textureinternet/PaintedPlaster010_1K_Color.jpg",                       //32
            "./textureinternet/PaintedPlaster015_1K_Color.jpg",                       //33
            "./textureinternet/PaintedPlaster016_1K_Color.jpg",                       //34
            "./textureinternet/Wood047_1K_Color.jpg"                                  //35
    };

    GLuint skyBoxZPlusIndex = 0;  // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_0_Front+Z.jpg",
    GLuint skyboxZNegIndex = 1;   // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_1_Back-Z.jpg",
    GLuint SkyboxXNegIndex = 2;   // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_2_Left+X.jpg",
    GLuint skyboxXPlusIndex = 3;  // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_3_Right-X.jpg",
    GLuint skyboxYPlusIndex = 4;  // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_4_Up+Y.jpg",
    GLuint skyboxYNegIndex = 5;   // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_5_Down-Y.jpg",
    GLuint applePCIndex = 6;      // "./textureinternet/appleIIe.jpg",
    GLuint marioIndex = 7;        // "./textureinternet/mario2.png",
    GLuint geishaIndex = 8;       // "./textureinternet/pruebas_geisha.jpg",
    GLuint Fire1Index = 9;        // "./textureinternet/fire/fire_00076.png",
    GLuint Fire2Index = 10;       // "./textureinternet/fire/fire_00077.png",
    GLuint Fire3Index = 11;       // "./textureinternet/fire/fire_00078.png",
    GLuint Fire4Index = 12;       // "./textureinternet/fire/fire_00079.png",
    GLuint Fire5Index = 13;       // "./textureinternet/fire/fire_00080.png",
    GLuint Fire6Index = 14;       // "./textureinternet/fire/fire_00081.png",
    GLuint Fire7Index = 15;       // "./textureinternet/fire/fire_00082.png",
    GLuint Fire8Index = 16;       // "./textureinternet/fire/fire_00083.png",
    GLuint Fire9Index = 17;       // "./textureinternet/fire/fire_00084.png",
    GLuint Fire10Index = 18;      // "./textureinternet/fire/fire_00085.png",
    GLuint Fire11Index = 19;      // "./textureinternet/fire/fire_00086.png",
    GLuint Fire12Index = 20;      // "./textureinternet/fire/fire_00087.png",
    GLuint Fire13Index = 21;      // "./textureinternet/fire/fire_00088.png",
    GLuint Fire14Index = 22;      // "./textureinternet/fire/fire_00089.png",
    GLuint Fire15Index = 23;      // "./textureinternet/fire/fire_00090.png",
    GLuint Fire16Index = 24;      // "./textureinternet/fire/fire_00091.png",
    GLuint Fire17Index = 25;      // "./textureinternet/fire/fire_00092.png",
    GLuint Fire18Index = 26;      // "./textureinternet/fire/fire_00093.png",
    GLuint Fire19Index = 27;      // "./textureinternet/fire/fire_00094.png",
    GLuint Fire20Index = 28;      // "./textureinternet/fire/fire_00095.png",
    GLuint marcIndex = 29;      // "./textureinternet/fire/fire_00095.png",
    GLuint mapIndex = 30;      // "./textureinternet/fire/fire_00095.png",
    GLuint grassIndex = 31;      // "./textureinternet/grass_rough2.png",
    GLuint ceilingIndex = 32;      // "./textureinternet/grass_rough2.png",
    GLuint floorIndex = 33;      // "./textureinternet/grass_rough2.png",
    GLuint wallIndex = 34;      // "./textureinternet/grass_rough2.png",
    GLuint woodIndex = 35;

    //6 skybox, 3 object (with mario), 20 fire, 2 marc, grass , 3 walls //35
    static constexpr int constNumberOfTextures = 6 + 3 + 20 + 2 + 1 + 3;

    int selectedIndex = 0;

    int numberOfTextures;

    QList<QImage> pQImage;

    GLuint textures[constNumberOfTextures];

    void swapActiveTexture(int textureNumber);

protected:
private:
};
#endif //SCENE_TextureCreator_H
