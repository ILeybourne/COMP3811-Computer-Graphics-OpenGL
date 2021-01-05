#include "Window.h"
#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QBoxLayout>
#include <QTimer>
#include "QSizePolicy"
#include "SceneWidget.h"

// constructor / destructor
Window::Window(QWidget *parent)
        : QWidget(parent) { // constructor
    // create menu bar

    QGLFormat glFormat;
    glFormat.setVersion( 3, 3 );
    glFormat.setProfile( QGLFormat::CoreProfile ); // Requires >=Qt-4.8.0
    glFormat.setSampleBuffers( true );

    menuBar = new QMenuBar(this);
    // create file menu
    fileMenu = menuBar->addMenu("&File");
    // create the action
    actionQuit = new QAction("&Quit", this);
    // add the item to the menu
    fileMenu->addAction(actionQuit);
    QObject::connect(actionQuit, SIGNAL(triggered()), this, SLOT(closeWindow()));



    // create the window layout
    windowLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    // leave signals & slots to the controller

    // create main widget
    sceneWidget = new SceneWidget(this);
    //8 factor multisampling
    QGLFormat format;
    format.setSamples(8);
    sceneWidget->setFormat(format);
    sceneWidget->setFocusPolicy(Qt::StrongFocus);

    windowLayout->addWidget(sceneWidget);
    windowLayout->setMenuBar(menuBar);


//    sceneWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
//    sceneWidget->setFixedSize(400, 400);

    // create slider
    rotationSlider = new QSlider(Qt::Horizontal);

    screenTextureSelection = new QComboBox();
    QList<QString> stringsList;
    stringsList.append("Sky");
    stringsList.append("Marc");
    stringsList.append("Map");
    screenTextureSelection->addItems(stringsList);
    int i;
    QObject::connect(screenTextureSelection, SIGNAL(currentIndexChanged( int)), sceneWidget, SLOT(changeScreenTexture(int)));
//    QObject::connect(screenTextureSelection, SIGNAL(hasFocus( bool)), screenTextureSelection->clearFocus(), SLOT());
    QObject::connect(screenTextureSelection, SIGNAL(currentIndexChanged( int)), this, SLOT(resetFocus()));
    screenTextureSelectionLabel = new QLabel(this);
    screenTextureSelectionLabel->setText("Screen Image:");
    screenTextureSelectionLabel->setBuddy(screenTextureSelection);

    QBoxLayout *selectionLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    selectionLayout->addWidget(screenTextureSelectionLabel,10);
    selectionLayout->addWidget(screenTextureSelection,90);



    rotationSliderLabel = new QLabel(this);
    rotationSliderLabel->setFixedHeight(20);
    rotationSliderLabel->setText("Rotation Speed:");

    QBoxLayout *sliderLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    sliderLayout->addWidget(rotationSliderLabel);
    sliderLayout->addWidget(rotationSlider);

    resetCameraButton = new QPushButton(this);
    resetCameraButton->setText("Reset Camera");
    QBoxLayout *buttonLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    buttonLayout->addWidget(resetCameraButton);
    QObject::connect(resetCameraButton, SIGNAL(released()), sceneWidget, SLOT(resetCamera()));

    fpsLabel = new QLabel(this);
    fpsLabel->setFixedHeight(20);
    rotationSlider->sliderReleased();

    QObject::connect(rotationSlider, SIGNAL(valueChanged(int)), this, SLOT(setRotationSpeed()));
    QObject::connect(rotationSlider, SIGNAL(valueChanged(int)), this, SLOT(resetFocus()));
    rotationSlider->setFocusPolicy(Qt::NoFocus);
    screenTextureSelection->setFocusPolicy(Qt::NoFocus);
    screenTextureSelectionLabel->setFocusPolicy(Qt::NoFocus);
    fpsLabel->setFocusPolicy(Qt::NoFocus);;
    rotationSliderLabel->setFocusPolicy(Qt::NoFocus);;
    rotationSlider->setSliderPosition(10);
    resetCameraButton->setFocusPolicy(Qt::NoFocus);


    windowLayout->addWidget(fpsLabel);
    windowLayout->addLayout(sliderLayout);
    windowLayout->addLayout(selectionLayout);
    windowLayout->addLayout(buttonLayout);

    ////Updates Paint event 60 times second
    QTimer *frameTimer = new QTimer(this);
    QObject::connect(frameTimer, SIGNAL(timeout()), sceneWidget, SLOT(updateGL()));
    float frameRate = 1000 / 60;
    frameTimer->setInterval(frameRate);
    frameTimer->start();

    ////FPS timer
    QTimer *secondTimer = new QTimer(this);
    QObject::connect(secondTimer, SIGNAL(timeout()), sceneWidget, SLOT(getFrameRate()));
    QObject::connect(secondTimer, SIGNAL(timeout()), this, SLOT(updateFpsLabel()));
    updateFpsLabel();
    secondTimer->setInterval(1000);
    secondTimer->start();
} // constructor

void Window::updateFpsLabel() {
    QString fps = QString::number(sceneWidget->frameDifference);
    qDebug() << "test" << fps << sceneWidget->frameDifference;
    fpsLabel->setText(fps + " fps");
}

void Window::setRotationSpeed(){
    int pos =rotationSlider->sliderPosition();
    qDebug() << pos;
    sceneWidget->turnTableRotationSpeed = pos/10;
}

void Window::closeWindow() {
    qDebug() << "closing";
    this->close();
}

void Window::resetFocus() {
    rotationSlider->clearFocus();
    screenTextureSelection->clearFocus();
    fpsLabel->clearFocus();
    screenTextureSelectionLabel->clearFocus();
    sceneWidget->setFocus();
}

Window::~Window() { // destructor
    delete rotationSlider;
    delete sceneWidget;
    delete windowLayout;
    delete actionQuit;
    delete fileMenu;
    delete menuBar;
} // destructor

// resets all the interface elements
void Window::ResetInterface() { // ResetInterface()
    rotationSlider->setMinimum(3);
    rotationSlider->setMaximum(30);
    //don't use the slider for now
    //	rotationSlider->setValue(thePolygon->nVertices);
    // now force refresh
    sceneWidget->update();
    update();
} // ResetInterface()
