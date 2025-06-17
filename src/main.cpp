#include <QApplication>
#include "../include/gui.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv); // inicializamos QApplication
    NetSnifferGUI gui; // creamos nuestro GUI
    gui.show(); // mostramos el GUI
    return app.exec(); // ejecutamos la aplicación
}
