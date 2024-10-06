#include "taskOne.h"
#include "widgets/customnumberinput.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <QDebug>

#include <iostream>
#include <cmath>

TaskOneWidget::TaskOneWidget(QWidget* parent)
    : QWidget(parent)
    , xValue(new NumberInput(this))
    , yValue(new NumberInput(this))
    , zValue(new NumberInput(this))
    , resultText(new QPlainTextEdit(this))
{
    QGridLayout* layout = new QGridLayout(this);

    layout->addWidget(new QLabel("Введите значение X:"), 0, 0);
    layout->addWidget(xValue, 0, 1);

    layout->addWidget(new QLabel("Введите значение Y:"), 1, 0);
    layout->addWidget(yValue, 1, 1);

    layout->addWidget(new QLabel("Введите значение Z:"), 2, 0);
    layout->addWidget(zValue, 2, 1);

    layout->addWidget(new QLabel("Результат выполнения программы:"), 3, 0, 1, 2);

    resultText->setReadOnly(true);
    layout->addWidget(resultText, 4, 0, 1, 2);

    button = new QPushButton("Выполнить", this);
    QObject::connect(button, &QPushButton::clicked, this, &TaskOneWidget::printResult);
    layout->addWidget(button, 5, 1);

}

TaskOneWidget::~TaskOneWidget()
{
    // ?
}

void TaskOneWidget::printResult()
{

    resultText->setPlainText(QString(
        "Лаб. работа №1. Ст. гр. АДМ-23-06 Куликов Ю.Н.\n"
        "X = " + QString::number(xValue->getValue()) + "\n"
        "Y = " + QString::number(yValue->getValue()) + "\n"
        "Z = " + QString::number(zValue->getValue()) + "\n"
        "Результат U = " + QString::number(this->calculate()) + "\n"
    ));
}

double TaskOneWidget::calculate() 
{
    return (exp(std::fabs(xValue->getValue() - yValue->getValue())) * pow(std::fabs(xValue->getValue() - yValue->getValue()), xValue->getValue() + yValue->getValue())) / (atan(xValue->getValue()) + atan(zValue->getValue())) + (cbrt(pow(xValue->getValue(), 6) + pow(log(yValue->getValue()), 2)));
}

