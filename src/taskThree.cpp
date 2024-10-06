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
    , xMin(new NumberInput(this))
    , xMax(new NumberInput(this))
    , xStep(new NumberInput(this))
    , drawBt(new QPushButton(this))
    , spline(new QSplineSeries())
    , chart(new QChart())
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    this->setLayout(layout);

    QChartView* chartView = new QChartView(this);
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);

    chart->addSeries(spline);
    spline->setName("Function");

    axisX = new QValueAxis();
    axisX->setRange(-2, -0.75);
    this->chart->addAxis(axisX, Qt::AlignBottom);
    spline->attachAxis(axisX);

    axisY = new QValueAxis();
    axisY->setRange(2, 130);
    this->chart->addAxis(axisY, Qt::AlignLeft);
    spline->attachAxis(axisY);

    QHBoxLayout* semilay = new QHBoxLayout();
    semilay->addWidget(new QLabel("min x:"));
    semilay->addWidget(xMin);
    xMin->setText("-0.75");

    semilay->addWidget(new QLabel("max x:"));
    semilay->addWidget(xMax);
    xMax->setText("-2.05");

    semilay->addWidget(new QLabel("step:"));
    semilay->addWidget(xStep);
    xStep->setText("-0.2");

    semilay->addWidget(drawBt);
    drawBt->setText("Построить");
    connect(drawBt, &QPushButton::clicked, this, &TaskThreeWidget::drawPlot);

    layout->addLayout(semilay);

}

TaskThreeWidget::~TaskThreeWidget()
{
    // ?
}

void TaskThreeWidget::drawPlot()
{
    this->spline->clear();
    double max = -100000;
    double min = 100000;

    for (double x = xMin->getValue(); x >= xMax->getValue(); x += xStep->getValue()) {
        double res = this->calculate(x);
        if (res > max) { max = res; }
        if (res < min) { min = res; }
        this->spline->append(x, calculate(x));
    }
    axisX->setRange(xMax->getValue(), xMin->getValue());
    axisY->setRange(min, max);
}

double TaskThreeWidget::calculate(double x) {
    return 9 * pow(x, 4) + sin(57.2 + x);
}