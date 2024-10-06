#include "widgets/customnumberinput.h"

#include <QRegularExpressionValidator>
#include <QValidator>

#include <iostream>

NumberInput::NumberInput(QWidget* parent)
    : QLineEdit(parent)
{
    QRegularExpression rx("^[+-]?[0-9]+([.][0-9]+)?$");
    this->setValidator(new QRegularExpressionValidator(rx, this));
    this->setFixedHeight(30);
}

NumberInput::~NumberInput()
{

}

double NumberInput::getValue()
{
    return this->text().toFloat();
}