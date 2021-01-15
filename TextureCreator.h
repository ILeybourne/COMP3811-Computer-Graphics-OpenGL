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
            "./Textures/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_0_Front+Z.jpg", //0
            "./Textures/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_1_Back-Z.jpg",  //1
            "./Textures/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_2_Left+X.jpg",  //2
            "./Textures/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_3_Right-X.jpg", //3
            "./Textures/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_4_Up+Y.jpg",    //4
            "./Textures/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_5_Down-Y.jpg",  //5
            "./Textures/appleIIe.jpg",                                          //6
            "./Textures/pruebas_geisha.jpg",                                    //7
            "./Textures/fire/fire_00076.png",                                   //8
            "./Textures/fire/fire_00077.png",                                   //9
            "./Textures/fire/fire_00078.png",                                  //10
            "./Textures/fire/fire_00079.png",                                  //11
            "./Textures/fire/fire_00080.png",                                  //12
            "./Textures/fire/fire_00081.png",                                  //13
            "./Textures/fire/fire_00082.png",                                  //14
            "./Textures/fire/fire_00083.png",                                  //15
            "./Textures/fire/fire_00084.png",                                  //16
            "./Textures/fire/fire_00085.png",                                  //17
            "./Textures/fire/fire_00086.png",                                  //18
            "./Textures/fire/fire_00087.png",                                  //19
            "./Textures/fire/fire_00088.png",                                  //20
            "./Textures/fire/fire_00089.png",                                  //21
            "./Textures/fire/fire_00090.png",                                  //22
            "./Textures/fire/fire_00091.png",                                  //23
            "./Textures/fire/fire_00092.png",                                  //24
            "./Textures/fire/fire_00093.png",                                  //25
            "./Textures/fire/fire_00094.png",                                  //26
            "./Textures/fire/fire_00095.png",                                  //27
            "./Textures/Marc_Dekamps.ppm",                                     //28
            "./Textures/Mercator-projection.ppm",                              //29
            "./Textures/grass_rough2.png",                                     //30
            "./Textures/PaintedPlaster010_1K_Color.jpg",                       //31,
            "./Textures/PaintedPlaster015_1K_Color.jpg",                       //32
            "./Textures/PaintedPlaster016_1K_Color.jpg",                       //33
            "./Textures/Wood047_1K_Color.jpg",                                 //34
            "./Textures/Linolafett_CC-0_RPv6ofy.jpg",                          //35
            "./Textures/Tree_bark_seamless_07.png",                            //36
            "./Textures/caststeel.jpg"                                         //37
    };

    GLuint skyBoxZPlusIndex = 0;  // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_0_Front+Z.jpg",
    GLuint skyboxZNegIndex = 1;   // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_1_Back-Z.jpg",
    GLuint SkyboxXNegIndex = 2;   // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_2_Left+X.jpg",
    GLuint skyboxXPlusIndex = 3;  // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_3_Right-X.jpg",
    GLuint skyboxYPlusIndex = 4;  // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_4_Up+Y.jpg",
    GLuint skyboxYNegIndex = 5;   // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_5_Down-Y.jpg",
    GLuint applePCIndex = 6;      // "./textureinternet/appleIIe.jpg",
    GLuint geishaIndex  = 7;     // "./textureinternet/pruebas_geisha.jpg",
    GLuint Fire1Index  = 8;        // "./textureinternet/fire/fire_00076.png",
    GLuint Fire2Index  = 9;        // "./textureinternet/fire/fire_00077.png",
    GLuint Fire3Index  = 10;       // "./textureinternet/fire/fire_00078.png",
    GLuint Fire4Index  = 11;       // "./textureinternet/fire/fire_00079.png",
    GLuint Fire5Index  = 12;       // "./textureinternet/fire/fire_00080.png",
    GLuint Fire6Index  = 13;       // "./textureinternet/fire/fire_00081.png",
    GLuint Fire7Index  = 14;       // "./textureinternet/fire/fire_00082.png",
    GLuint Fire8Index  = 15;       // "./textureinternet/fire/fire_00083.png",
    GLuint Fire9Index  = 16;       // "./textureinternet/fire/fire_00084.png",
    GLuint Fire10Index = 17;      // "./textureinternet/fire/fire_00085.png",
    GLuint Fire11Index = 18;      // "./textureinternet/fire/fire_00086.png",
    GLuint Fire12Index = 19;      // "./textureinternet/fire/fire_00087.png",
    GLuint Fire13Index = 20;      // "./textureinternet/fire/fire_00088.png",
    GLuint Fire14Index = 21;      // "./textureinternet/fire/fire_00089.png",
    GLuint Fire15Index = 22;      // "./textureinternet/fire/fire_00090.png",
    GLuint Fire16Index = 23;      // "./textureinternet/fire/fire_00091.png",
    GLuint Fire17Index = 24;      // "./textureinternet/fire/fire_00092.png",
    GLuint Fire18Index = 25;      // "./textureinternet/fire/fire_00093.png",
    GLuint Fire19Index = 26;      // "./textureinternet/fire/fire_00094.png",
    GLuint Fire20Index = 27;      // "./textureinternet/fire/fire_00095.png",
    GLuint marcIndex   = 28;      // "./textureinternet/fire/fire_00095.png",
    GLuint mapIndex    = 29;      // "./textureinternet/fire/fire_00095.png",
    GLuint grassIndex  = 30;      // "./textureinternet/grass_rough2.png",
    GLuint ceilingIndex= 31;      // "./textureinternet/grass_rough2.png",
    GLuint floorIndex  = 32;      // "./textureinternet/grass_rough2.png",
    GLuint wallIndex   = 33;      // "./textureinternet/grass_rough2.png",
    GLuint woodIndex   = 34;
    GLuint treeIndex   = 35;
    GLuint barkIndex   = 36;
    GLuint metalIndex  = 37;

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
