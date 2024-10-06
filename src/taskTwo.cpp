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
    , xValue(new NumberInput(this))
    , mValue(new NumberInput(this))
    , resultText(new QPlainTextEdit(this))
{
    QGridLayout* layout = new QGridLayout(this);

    QHBoxLayout* radioLay = new QHBoxLayout();
    QButtonGroup* radioGroup = new QButtonGroup(this);
    radioGroup->setExclusive(true);

    sh = new QRadioButton("sh(x)", this);
    radioLay->addWidget(sh);
    radioGroup->addButton(sh);
    sh->setChecked(true);

    square = new QRadioButton("x^2", this);
    radioLay->addWidget(square);
    radioGroup->addButton(square);

    e = new QRadioButton("e^x", this);
    radioLay->addWidget(e);
    radioGroup->addButton(e);

    layout->addLayout(radioLay, 0, 0);

    layout->addWidget(new QLabel("Введите значение X:"), 1, 0);
    layout->addWidget(xValue, 1, 1);

    layout->addWidget(new QLabel("Введите значение Y:"), 2, 0);
    layout->addWidget(mValue, 2, 1);

    layout->addWidget(new QLabel("Результат выполнения программы:"), 3, 0, 1, 2);

    resultText->setReadOnly(true);
    layout->addWidget(resultText, 4, 0, 1, 2);

    button = new QPushButton("Выполнить", this);
    QObject::connect(button, &QPushButton::clicked, this, &TaskTwoWidget::printResult);
    layout->addWidget(button, 5, 1);

}

TaskTwoWidget::~TaskTwoWidget()
{
    // ?
}

void TaskTwoWidget::printResult()
{
    double result;

    if (this->mValue->getValue() < this->xValue->getValue()) {
        result = this->calculateSin();
    }
    else if (this->mValue->getValue() > this->xValue->getValue()) {
        result = this->calculateCos();
    }
    else {
        result = this->calculateSquare();
    }
    resultText->setPlainText(QString(
        "Лаб. работа №1. Ст. гр. АДМ-23-06 Куликов Ю.Н.\n"
        "X = " + QString::number(xValue->getValue()) + "\n"
        "M = " + QString::number(mValue->getValue()) + "\n"
        "Результат U = " + QString::number(result) + "\n"
    ));
}

double TaskTwoWidget::getFunction()
{
    if (this->sh->isChecked()) {
        return sinh(this->xValue->getValue());
    } 
    else if (this->square->isChecked()) {
        return pow(this->xValue->getValue(), 2);
    }
    else if (this->e->isChecked()) {
        return exp(this->xValue->getValue());
    }
    else {
        return 0;
    }
}

double TaskTwoWidget::calculateSin() 
{
    return (sin(5 * this->getFunction() + 3 * this->mValue->getValue() * std::fabs(this->getFunction())));
}

double TaskTwoWidget::calculateCos()
{
    return (cos(3 * this->getFunction() + 5 * this->mValue->getValue() * std::fabs(this->getFunction())));
}

double TaskTwoWidget::calculateSquare()
{
    return pow((this->getFunction() + this->mValue->getValue()), 2);
}