######################################################################
# Automatically generated by qmake (3.0) Tue Aug 8 14:19:53 2017
######################################################################

TEMPLATE = app
TARGET = Scene
INCLUDEPATH += . /opt/local/include

QT += widgets opengl gui 

LIBS += -lGLU -lstdc++fs


# Input
HEADERS += ShapeCreator.h SceneWidget.h Window.h TextureCreator.h
SOURCES += Main.cpp \
           TextureCreator.cpp \
           ShapeCreator.cpp \
           SceneWidget.cpp \
           Window.cpp \
