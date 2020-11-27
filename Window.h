#ifndef __GL_POLYGON_WINDOW_H__
#define __GL_POLYGON_WINDOW_H__ 1

#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QBoxLayout>
#include <QTimer>
#include "QSizePolicy"
#include "SceneWidget.h"


class Window: public QWidget
	{ 
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
	QSlider *nVerticesSlider;

	// resets all the interface elements
	void ResetInterface();
	}; 
	
#endif
