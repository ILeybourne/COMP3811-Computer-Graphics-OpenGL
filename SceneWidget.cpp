//#define GL_GLEXT_PROTOTYPES

#include "SceneWidget.h"

// constructor
SceneWidget::SceneWidget(QWidget *parent)
        : QGLWidget(parent) { // constructor
    window = parent;
    shapeCreator = new ShapeCreator(this);
}

//// called when OpenGL is started
void SceneWidget::initializeGL() { // initializeGL()
    //Enable anti-alias
    glEnable(GL_MULTISAMPLE);
    //Normalize normals upon transformations (especially scaling)
    glEnable(GL_NORMALIZE);
    //Set Identity matrix
    glLoadIdentity();
    //Set Background colour to white
    glClearColor(1, 1, 1, 1);
    //Disable coloured material as all objects are textured
    glDisable(GL_COLOR_MATERIAL);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   shapeCreator->mAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   shapeCreator->mDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  shapeCreator->mSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, shapeCreator->mShininess2);


    ////Light parameters
    //Light 0
    GLfloat light0Ambient[] = {0.3, 0.2, 0.25, 0.0};
    GLfloat light0Diffuse[] = {2.0, 2.0, 2.0, 0.0};
    GLfloat light0Specular[] = {0.2, 0.2, 0.2, 0.0};
    GLfloat light0Shininess[] = {5.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
    glLightfv(GL_LIGHT0, GL_SHININESS, light0Shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glEnable(GL_LIGHT0);

    //Light 1 inside (Fire)
    GLfloat light1Ambient[] = {0.1, 0.1, 0.1, 0.0};
    GLfloat light1Diffuse[] = {1, 1, 1, 0.0};
    GLfloat light1Specular[] = {0.8, 0.7, 0.7, 0.0};
    GLfloat light1Shininess[] = {100.0};
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1Diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1Specular);
    glLightfv(GL_LIGHT1, GL_SHININESS, light1Shininess);
    glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
    glEnable(GL_LIGHT1);

    //Light 2 Tunnel
    GLfloat light2Ambient[] = {0.1, 0.1, 0.1, 0.0};
    GLfloat light2Diffuse[] = {1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0, 0.0};
    GLfloat light2Specular[] = {0.8 / 3.0, 0.7 / 3.0, 0.7 / 3.0, 0.0};
    glLightfv(GL_LIGHT2, GL_AMBIENT, light2Ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light2Diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light2Specular);
    glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
    glEnable(GL_LIGHT2);

    //Light 3 Tunnel
    glLightfv(GL_LIGHT3, GL_AMBIENT, light2Ambient);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, light2Diffuse);
    glLightfv(GL_LIGHT3, GL_SPECULAR, light2Specular);
    glLightfv(GL_LIGHT3, GL_POSITION, light3Position);
    glEnable(GL_LIGHT3);

    //Light 4 Tunnel
    glLightfv(GL_LIGHT4, GL_AMBIENT, light2Ambient);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, light2Diffuse);
    glLightfv(GL_LIGHT4, GL_SPECULAR, light2Specular);
    glLightfv(GL_LIGHT4, GL_POSITION, light4Position);
    glEnable(GL_LIGHT4);

    //Enable smooth shading and lighting
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);

    //Cull back of faces so unseen faces are not rendered
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    //Load Apple computer model vertex, UV, and normal info
    bool loadedPC = shapeCreator->getOBJData("./Models/AppleIIe.obj", shapeCreator->verticesPC, shapeCreator->uvsPC,
                                             shapeCreator->normalsPC);

    //Load geisha model vertex, UV, and normal info
    bool loadedGeisha = shapeCreator->getOBJData("./Models/geisha.obj", shapeCreator->verticesGeisha,
                                                 shapeCreator->uvsGeisha,
                                                 shapeCreator->normalsGeisha);

    if (!(loadedGeisha || loadedPC))
        qDebug() << "There was a error loading an OBJ file";

    ////Load textures
    glEnable(GL_TEXTURE_2D);
    shapeCreator->textureCreator->imageLoader(shapeCreator->textureCreator->textureStrings,
                                              shapeCreator->textureCreator->textures);

    ////Calculate shadow projection matrix for +Z wall and light 1
    //Define wall plane as ax+by+cz+d=0, defined by its norm and distance from origin. Offset to avoid Z-fighting
    glm::vec4 wallAsPlane = {0, 0, -1, (roomDepth / 2) - 0.2};
    glm::vec4 light1PositionAsVec4 = {light1Position[0], light1Position[1], light1Position[2], light1Position[3]};
    shadowMatrix = getShadowMatrix(wallAsPlane, light1PositionAsVec4);
}

// called every time the widget is resized
void SceneWidget::resizeGL(int w, int h) { // resizeGL()
    // Set the viewport to the entire widget
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float width = w;
    float height = h;
    //Change the perspective to match the new aspect ratio of the view port
    gluPerspective(this->fov, width / height, 0.01, sqrt(pow(1000, 2) + pow(1000, 2)) + pow(1000, 2));
} // resizeGL()

void SceneWidget::keyPressEvent(QKeyEvent *key) {
    const float cameraSpeed = 0.2f;
    const float turningSpeed = 0.05f;
    //Keep yaw between -pi/2 and pi/2
    if (camX < 0) {
        yaw = (M_PI + yaw);
    }

    //Strife Left
    if (key->key() == Qt::Key_Q) {
        float newYaw = yaw - M_PI / 2;
        cameraPosition[2] += sin(newYaw) * cameraSpeed;
        cameraDirection[2] += sin(newYaw) * cameraSpeed;
        cameraPosition[0] += cos(newYaw) * cameraSpeed;
        cameraDirection[0] += cos(newYaw) * cameraSpeed;
    }
    //Strife Right
    if (key->key() == Qt::Key_E) {
        float newYaw = yaw + M_PI / 2;
        cameraPosition[2] += sin(newYaw) * cameraSpeed;
        cameraDirection[2] += sin(newYaw) * cameraSpeed;
        cameraPosition[0] += cos(newYaw) * cameraSpeed;
        cameraDirection[0] += cos(newYaw) * cameraSpeed;
    }
    //Move Forward
    if (key->key() == Qt::Key_W) {
        cameraPosition[0] += cos(yaw) * cameraSpeed;
        cameraDirection[0] += cos(yaw) * cameraSpeed;
        cameraPosition[2] += sin(yaw) * cameraSpeed;
        cameraDirection[2] += sin(yaw) * cameraSpeed;
    }
    //Move Backwards
    if (key->key() == Qt::Key_S) {
        cameraPosition[0] -= cos(yaw) * cameraSpeed;
        cameraDirection[0] -= cos(yaw) * cameraSpeed;
        cameraPosition[2] -= sin(yaw) * cameraSpeed;
        cameraDirection[2] -= sin(yaw) * cameraSpeed;
    }
    //Turn Left
    if (key->key() == Qt::Key_A) {
        turningNumber += turningSpeed;
    }
    //Turn Right
    if (key->key() == Qt::Key_D) {
        turningNumber -= turningSpeed;
    }

    //Update new direction of camera
    camX = sin(turningNumber) * radius;
    camZ = cos(turningNumber) * radius;
    cameraDirection[0] = cameraPosition[0] - camX;
    cameraDirection[2] = cameraPosition[2] - camZ;
    if (camX != 0) {
        yaw = atan(camZ / camX);
    }

    //Pan up
    if (key->key() == Qt::Key_R) {
        cameraPosition[1] += 0.2;
        cameraDirection[1] += 0.2;
    }
    //Pan Down
    if (key->key() == Qt::Key_F) {
        cameraPosition[1] -= 0.2;
        cameraDirection[1] -= 0.2;
    }
    //Tilt Up
    if (key->key() == Qt::Key_T) {
        cameraDirection[1] -= 0.02;
    }
    //Tilt Down
    if (key->key() == Qt::Key_G) {
        cameraDirection[1] += 0.02;
    }
}

////Called by Qt button
void SceneWidget::resetCamera() {
    for (int i = 0; i < 3; i++) {
        cameraPosition[i] = cameraStartPosition[i];
        cameraDirection[i] = cameraStartDirection[i];
        yaw = startingYaw;
        turningNumber = startingTurningNumber;
        camX = sin(turningNumber) * radius;
        camZ = cos(turningNumber) * radius;
    }
}

float *SceneWidget::getShadowMatrix(glm::vec4 p, glm::vec4 l) {
    static float shadowMatrix[16];
    //Calculate dot product between plane and light
    float dot = glm::dot(p, l);

    //Formula to calculate projection onto plane
    shadowMatrix[0] = dot - l[0] * p[0];
    shadowMatrix[4] = -l[0] * p[1];
    shadowMatrix[8] = -l[0] * p[2];
    shadowMatrix[12] = -l[0] * p[3];

    shadowMatrix[1] = -l[1] * p[0];
    shadowMatrix[5] = dot - l[1] * p[1];
    shadowMatrix[9] = -l[1] * p[2];
    shadowMatrix[13] = -l[1] * p[3];

    shadowMatrix[2] = -l[2] * p[0];
    shadowMatrix[6] = -l[2] * p[1];
    shadowMatrix[10] = dot - l[2] * p[2];
    shadowMatrix[14] = -l[2] * p[3];

    shadowMatrix[3] = -l[3] * p[0];
    shadowMatrix[7] = -l[3] * p[1];
    shadowMatrix[11] = -l[3] * p[2];
    shadowMatrix[15] = dot - l[3] * p[3];

    return shadowMatrix;
}

///Slot for changing terrain seed
void SceneWidget::changeTerrainSeed(QString seed) {
    //Despite validation all textChanged(QString) returns string with non-numerical values so all non-numeric characters must be removed
    seed.remove(QRegExp("[\\D]"));
    if (seed == "" || seed.isEmpty()) {
        seed = "1";
    }
    int seedAsInt = seed.toInt();
    shapeCreator->heightGenerator(seedAsInt);
}

///Rendering scaled up version of terrain with trees added
void SceneWidget::placeTerrain() {
    glPushMatrix();
    glScaled(1.0 / shapeCreator->planeWidth * 1000, 1.0, 1.0 / shapeCreator->planeDepth * 1000);
    float treeHeightRatio = (1.0 / shapeCreator->planeWidth * 1000) / 1.0;
    glTranslatef(-shapeCreator->planeWidth / 2.0, -shapeCreator->amplitude, -shapeCreator->planeDepth / 2.0);
    for (int i = 0; i < shapeCreator->numberOfTrees; i++) {
        float x = shapeCreator->treePositions[i][0];
        float y = shapeCreator->treePositions[i][1];
        float z = shapeCreator->treePositions[i][2];
        glPushMatrix();
        glTranslatef(x, y, z);
        //Restore aspect ratio of trees
        glScaled(1, treeHeightRatio, 1);
        //and then scale down by x5
        glScaled(1.0 / 5.0, 1.0 / 5.0, 1.0 / 5.0);
        float additionHeight = shapeCreator->treeHeightRad[i][0];
        float additionRad = shapeCreator->treeHeightRad[i][1];
        shapeCreator->createTree(additionHeight, additionRad);
        glPopMatrix();
    }
    shapeCreator->createTessilatedTerrain(shapeCreator->planeWidth, shapeCreator->planeDepth, shapeCreator->planeXTess,
                                          shapeCreator->planeZTess);
    glPopMatrix();
}

void SceneWidget::updateGeishaPosition(){
    //Add a sin wave to geishas height to simulate bopping while walking
    if (!(turningRight || turningLeft)) {
        geishaPosition[1] += sin(geishaBop) / 30.0;
        geishaBop += 0.5;
    }

    //Move geisha across X axis if not turning
    if (moveLeft && !turningRight) {
        geishaPosition[0] -= 0.1;
    }
    if (moveRight && !turningLeft) {
        geishaPosition[0] += 0.1;
    }

    //Decides when to turn and when to move geisha
    if (geishaPosition[0] >= 5.0 && geishaRotation == 270 - 180) {
        turningLeft = true;
    } else if (geishaPosition[0] >= 5.0 && geishaRotation == 270) {
        turningLeft = false;
        moveRight = false;
        moveLeft = true;
    }
    if (geishaPosition[0] <= -5.0 && geishaRotation == 270) {
        turningRight = true;
    } else if (geishaPosition[0] <= -5.0 && geishaRotation == 270 - 180) {
        turningRight = false;
        moveRight = true;
        moveLeft = false;
    }

    //Add or subtracts to geisha's rotation variable
    if (turningRight) {
        geishaRotation -= 2;
    }
    if (turningLeft) {
        geishaRotation += 2;
    }
}

void SceneWidget::updateFrameActions() {
    //Add to the rotation variables of the gyroscopes parts
    shapeCreator->gimbal1Turning += M_PI_2;
    shapeCreator->gimbal2Turning += 1;
    shapeCreator->gyroTurning += 1.618033988749895 * 2;
    shapeCreator->turnTableRotation += turnTableRotationSpeed;
    shapeCreator->fireNumber = frame % 20 + (6 + 2);
    updateGeishaPosition();

    //Update frame number
    frame++;
    if (frame == ULLONG_MAX) {
        frame = 0;
    }
}

void SceneWidget::changeScreenTexture(int i) {
    //Changes texture based on selected item from combo box
    if (i == 0)
        shapeCreator->textureCreator->selectedScreenIndex = shapeCreator->textureCreator->skyboxZPlusIndex;
    if (i == 1)
        shapeCreator->textureCreator->selectedScreenIndex = shapeCreator->textureCreator->marcIndex;
    if (i == 2)
        shapeCreator->textureCreator->selectedScreenIndex = shapeCreator->textureCreator->mapIndex;
}

void SceneWidget::changeGyroTexture(int i) {
    //Changes texture based on selected item from combo box
    if (i == 0)
        shapeCreator->textureCreator->selectedGyroIndex = shapeCreator->textureCreator->steelIndex;
    if (i == 1)
        shapeCreator->textureCreator->selectedGyroIndex = shapeCreator->textureCreator->ironIndex;
}

////Slot called by Qt connection to display framerate
unsigned long long SceneWidget::getFrameRate() {
    frameDifference = frame - lastFrameRecorded;
    lastFrameRecorded = frame;
    return frameDifference;
}

void SceneWidget::drawShadows() {
    //Shadows should not be lit and should be black
    glDisable(GL_LIGHTING);
    glColor4f(0, 0, 0, 1);
    glEnable(GL_CULL_FACE);

    //Geishas shadow is position is set using matrix multiplication of the shadow matrix to show were shadow would land
    //on plane from the lights perspective
    glPushMatrix();
    glMultMatrixf(shadowMatrix);
    drawGeishas(true);
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

void SceneWidget::drawGeishas(bool black) {
    //Geisha 1
    glPushMatrix();
    //Coloured geishas are placed normally. Shadow geishas are placed with respect to the room here view to the matrix projection
    if (!black) {
        glTranslatef(geishaPosition[0], geishaPosition[1], geishaPosition[2]);
    } else {
        glTranslatef(geishaPosition[0], geishaPosition[1] - lowestTerrain - roomHeight, geishaPosition[2]);
    }
    glRotatef(geishaRotation, 0, 1, 0);
    shapeCreator->createStickGeisha(black);
    glPopMatrix();

    //Geisha 2
    glPushMatrix();
    if (!black) {
        glTranslatef(-geishaPosition[0], geishaPosition[1], geishaPosition[2]);
    } else {
        glTranslatef(-geishaPosition[0], geishaPosition[1] - lowestTerrain - roomHeight, geishaPosition[2]);
    }
    glRotatef(geishaRotation - 180, 0, 1, 0);
    shapeCreator->createStickGeisha(black);
    glPopMatrix();
}

void SceneWidget::drawFire() {
    glDisable(GL_LIGHTING);
    glDisable(GL_CULL_FACE);
    float fireWidth = 10;
    float fireHeight = 20;
    glPushMatrix();
    glTranslatef(light1Position[0] - fireWidth / 2, -fireHeight / 8, light1Position[2]);
    shapeCreator->createTexturedPlane(0, 0, fireWidth, fireHeight, 0, 0, 1, 1, true,
                                      shapeCreator->textureCreator->textures[shapeCreator->fireNumber]);
    glPopMatrix();
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
}

void SceneWidget::paintGL() { // paintGL()
    ////Clear screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    ////Z Depth test
    glEnable(GL_DEPTH_TEST);

    ////Enable Lighting
    glEnable(GL_LIGHTING);

    ////Inside cave
    glPushMatrix();
    //Move room to underneath terrain
    glTranslatef(0, -lowestTerrain - roomHeight - 1, 0);
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT3);
    glDisable(GL_LIGHT4);
    glEnable(GL_LIGHT1);

    //Draw main room walls
    glPushMatrix();
    shapeCreator->walls(roomWidth, roomHeight, roomDepth, 50, 50, 50);
    glPopMatrix();

    ////Draw Geisha
    glPushMatrix();
    drawGeishas(false);
    glPopMatrix();

    ////Inside - tunnel
    //Change lighting to tunnel lighting
    glDisable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);

    //Move over to edge of wall +X
    glPushMatrix();
    glTranslatef(roomWidth / 2, 0, 0);

    //Draw desk
    glPushMatrix();
    glTranslatef(20, 0, 20);
    glRotatef(180, 0, 1, 0);
    shapeCreator->createPopulatedDesk();
    glPopMatrix();

    //Draw Tunnel
    shapeCreator->createTunnel(roomWidth, roomHeight, roomDepth, 50, 50);

    //Create Fireplace
    glPushMatrix();
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glTranslatef(-roomWidth / 2, 0, 0);
    glRotatef(90, 0, 1, 0);
    glTranslatef((roomDepth - roomWidth) / 2 - 2.01, 0, 0);
    glScalef(1, 1, roomWidth / roomDepth);
    shapeCreator->createDoorway(roomWidth, roomHeight, roomDepth, 50, 50, 50);
    glPopMatrix();

    //Draw Doorway at end of tunnel
    glTranslatef(roomWidth + 2, 0, 0);
    glPushMatrix();
    glTranslatef(roomWidth / 2 - 2.5, 0, 0);
    glRotatef(180, 0, 1, 0);
    shapeCreator->createDoorway(roomWidth, roomHeight, roomDepth, 50, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2.5, 0, -roomDepth / 2);
    shapeCreator->createTexturedPlane(0, 0, roomWidth, roomHeight, 0, 0, 1, 1, 0,
                                      shapeCreator->textureCreator->textures[shapeCreator->textureCreator->wallIndex]);
    glTranslatef(roomWidth, 0, roomDepth);
    shapeCreator->createTexturedPlane(0, 0, -roomWidth, roomHeight, 0, 0, 1, 1, 0,
                                      shapeCreator->textureCreator->textures[shapeCreator->textureCreator->wallIndex]);
    glPopMatrix();
    glEnable(GL_CULL_FACE);

    //Draw Stairs
    for (int i = 0; i < 15; i++) {
        shapeCreator->createCube(roomWidth / 15, roomHeight / 15, roomDepth, 0, 0, 0, 0,
                                 shapeCreator->textureCreator->textures[shapeCreator->textureCreator->woodIndex]);
        glTranslatef(roomWidth / 15, roomHeight / 15, 0);
    }
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    ////Outside
    //Skybox
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glTranslatef(0, -500, 0);
    shapeCreator->sky(1000.0, 1000.0, 1000.0);
    glPopMatrix();

    //Change lighting to outdoor lighting
    glEnable(GL_LIGHTING);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT3);
    glDisable(GL_LIGHT4);
    glEnable(GL_LIGHT0);
    glBindTexture(GL_TEXTURE_2D, 0);

    //Terrain
    placeTerrain();


    ////Inside
    //Shadows are immune to translations and should be projected separately
    //Draw shadows onto +Z wall
    drawShadows();

    //// Draw torches and fire (Drawn last as they are blended objects)
    // Draw torches
    glPushMatrix();
    glTranslatef(light2Position[0], light2Position[1], light2Position[2]);
    shapeCreator->createTorch();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(light3Position[0], light3Position[1], light3Position[2]);
    glRotatef(180, 0, 1, 0);
    shapeCreator->createTorch();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(light4Position[0], light4Position[1], light4Position[2]);
    shapeCreator->createTorch();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -lowestTerrain - roomHeight - 0.01, 0);
    //Draw Fire
    glPushMatrix();
    glTranslatef(0, 0, -1);
    for (float i = 0; i < 10; i++) {
        glPushMatrix();
        glTranslatef(0, 0, (i) / 10);
        drawFire();
        glPopMatrix();
    }
    glPopMatrix();
    glPopMatrix();

    //Place Camera
    glLoadIdentity();
    gluLookAt(cameraDirection[0], cameraDirection[1], cameraDirection[2], cameraPosition[0], cameraPosition[1],
              cameraPosition[2], cameraUp[0], cameraUp[1] + 10000000000000, cameraUp[2]);

    //Ensure lights are fixed
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
    glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
    glLightfv(GL_LIGHT3, GL_POSITION, light3Position);
    glLightfv(GL_LIGHT4, GL_POSITION, light4Position);

    //Render
    glFlush();

    //Update frame dependant variables
    updateFrameActions();
} // paintGL()
