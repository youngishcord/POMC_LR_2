#include "taskTwo.h"
#include "widgets/customnumberinput.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <QDebug>
#include <QHBoxLayout>
#include <QButtonGroup>

#include <iostream>
#include <cmath>

TaskTwoWidget::TaskTwoWidget(QWidget* parent)
    : QWidget(parent)
    , randomLay(new QVBoxLayout())
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(randomLay);

    QPushButton* generateBt = new QPushButton("Сгенерировать", this);
    layout->addWidget(generateBt);
    QObject::connect(generateBt, &QPushButton::clicked, this, &TaskTwoWidget::generator);

    this->setLayout(layout);
}

TaskTwoWidget::~TaskTwoWidget()
{
    // ?
}

void TaskTwoWidget::generator()
{
    QLayoutItem* child;
    while ((child = this->randomLay->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    for (int i = 0; i < QRandomGenerator::global()->bounded(1, 8); i++) {
        int randomNumber = QRandomGenerator::global()->bounded(1, 4);

        std::unique_ptr<QWidget> widget = widgetFactory[randomNumber]();

        if (widget) {
            this->randomLay->addWidget(widget.release());
        }
    }
}