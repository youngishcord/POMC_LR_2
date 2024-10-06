#ifndef TASKTHREE_H
#define TASKTHREE_H

#include <QWidget>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QRadioButton>
#include <QSplineSeries>
#include <QChart>
#include <QValueAxis>

#include "widgets/customnumberinput.h"

class TaskThreeWidget : public QWidget {
    Q_OBJECT

public: 
    explicit TaskThreeWidget(QWidget* parent = nullptr);
    ~TaskThreeWidget();

private:
    NumberInput* xMin;
    NumberInput* xMax;
    NumberInput* xStep;

    QPushButton* drawBt;
    QSplineSeries* spline;

    QChart* chart;

    QValueAxis* axisX;
    QValueAxis* axisY;

    double calculate(double x);

private slots:
    void drawPlot();
};

#endif // TASKTHREE_H