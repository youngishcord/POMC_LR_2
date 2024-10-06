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
    NumberInput* a;
    NumberInput* b;
    NumberInput* c;

    NumberInput* d;
    NumberInput* e;
    NumberInput* f;

    QPlainTextEdit* resultText;

    double func(double x, double y, double z) {
        return pow(x, 2) * pow(y, 3) * sqrt(z);
    }

    char getSign(double a, double b) {
        if (a == b) {
            return '=';
        } else if (a > b) {
            return '>';
        } else if (a < b) {
            return '<';
        }
        return '?';
    }

private slots:
    void result();
};

#endif // TASKTHREE_H