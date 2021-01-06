#ifndef SCENE_WINDOW_H
#define SCENE_WINDOW_H

#include <QGLWidget>
#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QLabel>
#include <QComboBox>
#include <QBoxLayout>
#include <QPushButton>
#include <QTimer>
#include "QSizePolicy"
#include "SceneWidget.h"

class Window : public QWidget {
Q_OBJECT
public:
    // constructor / destructor
    Window(QWidget *parent);

    ~Window();

    // visual hierarchy
    // menu bar
    QMenuBar *menuBar;
    // file menu
    QMenu *fileMenu;
    // quit action
    QAction *actionQuit;

    // window layout
    QBoxLayout *windowLayout;

    // beneath that, the main widget
    SceneWidget *sceneWidget;
    QGLWidget *wid;
    // and a slider for the number of vertices
    QSlider *rotationSlider;
    QComboBox *screenTextureSelection;

    QPushButton *resetCameraButton;

    QLabel *screenTextureSelectionLabel;

    QLabel *fpsLabel;
    QLabel *rotationSliderLabel;

    int test;

    // resets all the interface elements
    void ResetInterface();

public slots:

    void closeWindow();

    void updateFpsLabel();

    void setRotationSpeed();

    void resetFocus();

};

#endif
