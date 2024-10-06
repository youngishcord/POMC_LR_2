#include "taskThree.h"
#include "widgets/customnumberinput.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QChart>
#include <QChartView>
#include <QLineSeries>

// #include <QSplineSeries>

#include <iostream>
#include <cmath>

TaskThreeWidget::TaskThreeWidget(QWidget* parent)
    : QWidget(parent)
    , a(new NumberInput(this))
    , b(new NumberInput(this))
    , c(new NumberInput(this))
    , d(new NumberInput(this))
    , e(new NumberInput(this))
    , f(new NumberInput(this))
    , resultText(new QPlainTextEdit(this))
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    this->setLayout(layout);

    QGridLayout* grid = new QGridLayout();
    grid->addWidget(new QLabel("Значение а:"), 0, 0);
    grid->addWidget(a, 0, 1);
    grid->addWidget(new QLabel("Значение b:"), 1, 0);
    grid->addWidget(b, 1, 1);
    grid->addWidget(new QLabel("Значение c:"), 2, 0);
    grid->addWidget(c, 2, 1);
    grid->addWidget(new QLabel("Значение d:"), 3, 0);
    grid->addWidget(d, 3, 1);
    grid->addWidget(new QLabel("Значение e:"), 4, 0);
    grid->addWidget(e, 4, 1);
    grid->addWidget(new QLabel("Значение f:"), 5, 0);
    grid->addWidget(f, 5, 1);

    layout->addLayout(grid);

    layout->addWidget(resultText);
    resultText->setReadOnly(true);

    QPushButton* calculateBt = new QPushButton("Вычислить");
    layout->addWidget(calculateBt);
    connect(calculateBt, &QPushButton::clicked, this, &TaskThreeWidget::result);

}

TaskThreeWidget::~TaskThreeWidget()
{
    // ?
}

void TaskThreeWidget::result()
{
    double res1 = this->func(a->getValue(), b->getValue(), c->getValue());
    double res2 = this->func(d->getValue(), e->getValue(), f->getValue());
    QString res("Результат работы программы:\n");
    res += "f(a,b,c) = " + QString::number(res1) + "\n";
    res += "f(d,e,f) = " + QString::number(res2) + "\n";
    res += "f(a,b,c)" + QString(getSign(res1, res2)) + "f(d,e,f)\n";
    this->resultText->setPlainText(res);
}

