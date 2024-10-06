#include "mainwindow.h"
#include "taskOne.h"
#include "taskTwo.h"
#include "taskThree.h"

#include <QLabel>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , taskTabs(new QTabWidget(this))
{
    this->setWindowTitle("ЛР 2");
    this->setFixedSize(400, 500);

    setCentralWidget(taskTabs);
    taskTabs->addTab(new TaskOneWidget(this), "Задание №1");
    taskTabs->addTab(new TaskTwoWidget(this), "Задание №2");
    taskTabs->addTab(new TaskThreeWidget(this), "Задание №3");
}

MainWindow::~MainWindow()
{
    // ?
}
