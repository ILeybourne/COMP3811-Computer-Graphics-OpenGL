#ifndef SCENE_WINDOW_H
#define SCENE_WINDOW_H

#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QLabel>
#include <QComboBox>
#include <QBoxLayout>
#include <QPushButton>
#include <QTimer>
#include "QSizePolicy"
#include <QTimer>
#include <QTextEdit>
#include <QLineEdit>
#include <QIntValidator>
#include "SceneWidget.h"

class Window : public QWidget {
Q_OBJECT
public:
    // constructor / destructor
    Window(QWidget *parent);

    ~Window();

    QMenuBar *menuBar;
    QMenu *fileMenu;
    QAction *actionQuit;
    QBoxLayout *windowLayout;
    SceneWidget *sceneWidget;
    QSlider *rotationSlider;
    QComboBox *screenTextureSelection;
    QPushButton *resetCameraButton;
    QLabel *screenTextureSelectionLabel;
    QLabel *fpsLabel;
    QLabel *rotationSliderLabel;
    QString fps = 0;
    QLabel *seedNumberLabel;
    QLineEdit *seedNumberLineEdit;


public slots:

    void closeWindow();

    void updateFpsLabel();

    void setRotationSpeed();

    void resetFocus();

};

#endif
