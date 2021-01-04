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
#include <experimental/filesystem>


using namespace std;

const unsigned int N_X_IMAGE = 512;
const unsigned int N_Y_IMAGE = 512;
const unsigned int N_COLOR = 3;


class TextureCreator {
public:
    TextureCreator(QWidget *parent);

    void imageLoader(QStringList sImage, GLuint texture[]);

    QStringList textureStrings = {
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_0_Front+Z.jpg",//0
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_1_Back-Z.jpg",//1
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_2_Left+X.jpg",//2
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_3_Right-X.jpg",//3
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_4_Up+Y.jpg",//4
            "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_5_Down-Y.jpg",//5
            "./textureinternet/appleIIe.jpg",//6
            "./textureinternet/mario2.png",//7
            "./textureinternet/pruebas_geisha.jpg",//8
            "./textureinternet/fire/fire_00076.png",//9
            "./textureinternet/fire/fire_00077.png",//10
            "./textureinternet/fire/fire_00078.png",//11
            "./textureinternet/fire/fire_00079.png",//12
            "./textureinternet/fire/fire_00080.png",//13
            "./textureinternet/fire/fire_00081.png",//14
            "./textureinternet/fire/fire_00082.png",//15
            "./textureinternet/fire/fire_00083.png",//16
            "./textureinternet/fire/fire_00084.png",//17
            "./textureinternet/fire/fire_00085.png",//18
            "./textureinternet/fire/fire_00086.png",//19
            "./textureinternet/fire/fire_00087.png",//20
            "./textureinternet/fire/fire_00088.png",//21
            "./textureinternet/fire/fire_00089.png",//22
            "./textureinternet/fire/fire_00090.png",//23
            "./textureinternet/fire/fire_00091.png",//24
            "./textureinternet/fire/fire_00092.png",//25
            "./textureinternet/fire/fire_00093.png",//26
            "./textureinternet/fire/fire_00094.png",//27
            "./textureinternet/fire/fire_00095.png",//28
            "./textureinternet/Marc_Dekamps.ppm",//29
            "./textureinternet/Mercator-projection.ppm",//30
            "./textureinternet/grass_rough2.png",//31,
            "./textureinternet/PaintedPlaster010_1K_Color.jpg",//32
            "./textureinternet/PaintedPlaster015_1K_Color.jpg",//33
            "./textureinternet/PaintedPlaster016_1K_Color.jpg"//34
    };


    int skyBoxZPlusIndex = 0;  // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_0_Front+Z.jpg",
    int skyboxZNegIndex = 1;   // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_1_Back-Z.jpg",
    int SkyboxXNegIndex = 2;   // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_2_Left+X.jpg",
    int skyboxXPlusIndex = 3;  // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_3_Right-X.jpg",
    int skyboxYPlusIndex = 4;  // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_4_Up+Y.jpg",
    int skyboxYNegIndex = 5;   // "./textureinternet/Epic_BlueSunset/jpg/Epic_BlueSunset_Cam_5_Down-Y.jpg",
    int applePCIndex = 6;      // "./textureinternet/appleIIe.jpg",
    int marioIndex = 7;        // "./textureinternet/mario2.png",
    int geishaIndex = 8;       // "./textureinternet/pruebas_geisha.jpg",
    int Fire1Index = 9;        // "./textureinternet/fire/fire_00076.png",
    int Fire2Index = 10;       // "./textureinternet/fire/fire_00077.png",
    int Fire3Index = 11;       // "./textureinternet/fire/fire_00078.png",
    int Fire4Index = 12;       // "./textureinternet/fire/fire_00079.png",
    int Fire5Index = 13;       // "./textureinternet/fire/fire_00080.png",
    int Fire6Index = 14;       // "./textureinternet/fire/fire_00081.png",
    int Fire7Index = 15;       // "./textureinternet/fire/fire_00082.png",
    int Fire8Index = 16;       // "./textureinternet/fire/fire_00083.png",
    int Fire9Index = 17;       // "./textureinternet/fire/fire_00084.png",
    int Fire10Index = 18;      // "./textureinternet/fire/fire_00085.png",
    int Fire11Index = 19;      // "./textureinternet/fire/fire_00086.png",
    int Fire12Index = 20;      // "./textureinternet/fire/fire_00087.png",
    int Fire13Index = 21;      // "./textureinternet/fire/fire_00088.png",
    int Fire14Index = 22;      // "./textureinternet/fire/fire_00089.png",
    int Fire15Index = 23;      // "./textureinternet/fire/fire_00090.png",
    int Fire16Index = 24;      // "./textureinternet/fire/fire_00091.png",
    int Fire17Index = 25;      // "./textureinternet/fire/fire_00092.png",
    int Fire18Index = 26;      // "./textureinternet/fire/fire_00093.png",
    int Fire19Index = 27;      // "./textureinternet/fire/fire_00094.png",
    int Fire20Index = 28;      // "./textureinternet/fire/fire_00095.png",
    int marcIndex = 29;      // "./textureinternet/fire/fire_00095.png",
    int mapIndex = 30;      // "./textureinternet/fire/fire_00095.png",
    int grassIndex = 31;      // "./textureinternet/grass_rough2.png",
    int floorIndex = 33;      // "./textureinternet/grass_rough2.png",
    int ceilingIndex = 32;      // "./textureinternet/grass_rough2.png",
    int wallIndex = 34;      // "./textureinternet/grass_rough2.png",

    //6 skybox, 3 object (with mario), 20 fire, 2 marc, grass , 3 walls //35
    static constexpr int constNumberOfTextures = 6 + 3 + 20 + 2 + 1 + 3;

    int selectedIndex = 0;

    int numberOfTextures;

    QList<QImage> pQImage;

    int numOfTextures = textureStrings.size();
    GLuint textures[constNumberOfTextures];

    void swapActiveTexture(int textureNumber);

protected:
private:
};

#endif //SCENE_TextureCreator_H

