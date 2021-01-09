#include "Window.h"


// constructor
Window::Window(QWidget *parent)
        : QWidget(parent) { // constructor
    ////Create menu bar
    menuBar = new QMenuBar(this);
    fileMenu = menuBar->addMenu("&File");
    actionQuit = new QAction("&Quit", this);
    fileMenu->addAction(actionQuit);
    QObject::connect(actionQuit, SIGNAL(triggered()), this, SLOT(closeWindow()));

    ////Create main window layout
    windowLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    // leave signals & slots to the controller

    ////Create main widget
    sceneWidget = new SceneWidget(this);
    //8 factor multisampling (antialias)
    QGLFormat format;
    format.setSamples(8);
    sceneWidget->setFormat(format);
    sceneWidget->setFocusPolicy(Qt::StrongFocus);


    ////Create QWidgets
    rotationSlider = new QSlider(Qt::Horizontal);

    screenTextureSelection = new QComboBox();
    QList<QString> stringsList = {"Sky",
                                  "Marc",
                                  "Map"};
    screenTextureSelection->addItems(stringsList);

    screenTextureSelectionLabel = new QLabel(this);
    screenTextureSelectionLabel->setText("Screen Image:");
    screenTextureSelectionLabel->setBuddy(screenTextureSelection);

    rotationSliderLabel = new QLabel(this);
    rotationSliderLabel->setFixedHeight(20);
    rotationSliderLabel->setText("Turntable Speed:");

    resetCameraButton = new QPushButton(this);
    resetCameraButton->setText("Reset Camera");

    fpsLabel = new QLabel(this);
    fpsLabel->setFixedHeight(20);

    ////Set Focus policies
    rotationSlider->setFocusPolicy(Qt::NoFocus);
    screenTextureSelection->setFocusPolicy(Qt::NoFocus);
    screenTextureSelectionLabel->setFocusPolicy(Qt::NoFocus);
    fpsLabel->setFocusPolicy(Qt::NoFocus);;
    rotationSliderLabel->setFocusPolicy(Qt::NoFocus);;
    resetCameraButton->setFocusPolicy(Qt::NoFocus);

    ////Set up layouts and widget in window order
    windowLayout->addWidget(sceneWidget);
    windowLayout->setMenuBar(menuBar);
    windowLayout->addWidget(fpsLabel);

    QBoxLayout *sliderLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    sliderLayout->addWidget(rotationSliderLabel, 15);
    sliderLayout->addWidget(rotationSlider, 85);

    QBoxLayout *selectionLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    selectionLayout->addWidget(screenTextureSelectionLabel, 15);
    selectionLayout->addWidget(screenTextureSelection, 85);

    QBoxLayout *buttonLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    buttonLayout->addWidget(resetCameraButton);

    windowLayout->addLayout(sliderLayout);
    windowLayout->addLayout(selectionLayout);
    windowLayout->addLayout(buttonLayout);

    ////Connections
    QObject::connect(screenTextureSelection, SIGNAL(currentIndexChanged(int)), sceneWidget,
                     SLOT(changeScreenTexture(int)));
    QObject::connect(screenTextureSelection, SIGNAL(currentIndexChanged(int)), this, SLOT(resetFocus()));
    QObject::connect(rotationSlider, SIGNAL(valueChanged(int)), this, SLOT(setRotationSpeed()));
    QObject::connect(rotationSlider, SIGNAL(valueChanged(int)), this, SLOT(resetFocus()));
    rotationSlider->setSliderPosition(10);
    QObject::connect(resetCameraButton, SIGNAL(released()), sceneWidget, SLOT(resetCamera()));

    ////Timers
    //Updates Paint event 60 times second
    QTimer *frameTimer = new QTimer(this);
    QObject::connect(frameTimer, SIGNAL(timeout()), sceneWidget, SLOT(updateGL()));
    float frameRate = 1000 / 60;
    frameTimer->setInterval(frameRate);
    frameTimer->start();

    //FPS timer
    QTimer *secondTimer = new QTimer(this);
    QObject::connect(secondTimer, SIGNAL(timeout()), sceneWidget, SLOT(getFrameRate()));
    QObject::connect(secondTimer, SIGNAL(timeout()), this, SLOT(updateFpsLabel()));
    updateFpsLabel();
    secondTimer->setInterval(1000);
    secondTimer->start();
}

void Window::updateFpsLabel() {
    QString fps = QString::number(sceneWidget->frameDifference);
    fpsLabel->setText(fps + " fps");
}

void Window::setRotationSpeed() {
    int pos = rotationSlider->sliderPosition();
    qDebug() << pos;
    sceneWidget->turnTableRotationSpeed = pos / 10;
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
    delete screenTextureSelection;
    delete screenTextureSelectionLabel;
    delete rotationSliderLabel;
    delete resetCameraButton;
    delete fpsLabel;
} // destructor

