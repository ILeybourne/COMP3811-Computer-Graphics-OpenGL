#include <QApplication>
#include <QVBoxLayout>
#include "Window.h"

int main(int argc, char *argv[]) {
    //Create the main QApplication
    QApplication app(argc, argv);

    // create a Window widget
    Window *window = new Window(NULL);
    window->resize(1024, 512 + 20*(6));
    window->show();

    //Main Loop
    app.exec();

    delete window;
    return 0;
}
