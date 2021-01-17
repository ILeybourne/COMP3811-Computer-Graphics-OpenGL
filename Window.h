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

    QLabel *fpsLabel;
    QString fps = "0";

    QLabel *rotationSliderLabel;
    QSlider *rotationSlider;

    QLabel *screenTextureSelectionLabel;
    QComboBox *screenTextureSelection;

    QLabel *gyroSelectionLabel;
    QComboBox *gyroTextureSelection;

    QLabel *seedNumberLabel;
    QLineEdit *seedNumberLineEdit;
    QIntValidator *intValid = new QIntValidator(0, INT_MAX, this);
    QPushButton *resetCameraButton;

public slots:

    void closeWindow();

    void updateFpsLabel();

    void setRotationSpeed();

    void resetFocus();

};

#endif
