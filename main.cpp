#include <iostream>

#include <QApplication>

#include "include/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    std::cout << "::MESSAGE ON STARTUP::" << "\n";

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
