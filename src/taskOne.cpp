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
    , xStart(new NumberInput(this))
    , xStop(new NumberInput(this))
    , Step(new NumberInput(this))
    , resultText(new QPlainTextEdit(this))
{
    QGridLayout* layout = new QGridLayout(this);

    layout->addWidget(new QLabel("Минимальное значение X:"), 0, 0);
    layout->addWidget(xStart, 0, 1);
    xStart->setText("-0.75");

    layout->addWidget(new QLabel("Максимальное значение X:"), 1, 0);
    layout->addWidget(xStop, 1, 1);
    xStop->setText("-2.05");

    layout->addWidget(new QLabel("Шаг X:"), 2, 0);
    layout->addWidget(Step, 2, 1);
    Step->setText("-0.2");

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
    resultText->clear();
    QString result = QString("Лаб. работа №2. Ст. гр. АДМ-23-06 Куликов Ю.Н.\n");
    
    for (double x = xStart->getValue(); x >= xStop->getValue(); x += Step->getValue()) {
        result += "x = " + QString::number(x) + "; " + "y = " + QString::number(this->calculate(x)) + "\n";
    }

    resultText->setPlainText(result);
}

inline double TaskOneWidget::calculate(double x) {
    return 9 * pow(x, 4) + sin(57.2 + x);
}
