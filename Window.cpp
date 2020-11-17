#include "Window.h"

// constructor / destructor
Window::Window(QWidget *parent)
        : QWidget(parent) { // constructor
    // create menu bar
    menuBar = new QMenuBar(this);
    // create file menu
    fileMenu = menuBar->addMenu("&File");
    // create the action
    actionQuit = new QAction("&Quit", this);
    // add the item to the menu
    fileMenu->addAction(actionQuit);


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
//    sceneWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
//    sceneWidget->setFixedSize(400, 400);

    // create slider
    nVerticesSlider = new QSlider(Qt::Horizontal);
    windowLayout->addWidget(nVerticesSlider);

    //Updates Paint event once every 60 seconds
    QTimer *frameTimer = new QTimer(this);
    QObject::connect(frameTimer, SIGNAL(timeout()), sceneWidget, SLOT(updateGL()));
    float frameRate = 1000 / 60;
    frameTimer->setInterval(frameRate);
    frameTimer->start();
} // constructor

Window::~Window() { // destructor
    delete nVerticesSlider;
    delete sceneWidget;
    delete windowLayout;
    delete actionQuit;
    delete fileMenu;
    delete menuBar;
} // destructor

// resets all the interface elements
void Window::ResetInterface() { // ResetInterface()
    nVerticesSlider->setMinimum(3);
    nVerticesSlider->setMaximum(30);
    //don't use the slider for now
    //	nVerticesSlider->setValue(thePolygon->nVertices);
    // now force refresh
    sceneWidget->update();
    update();
} // ResetInterface()
