#ifndef TASKTWO_H
#define TASKTWO_H

#include <QWidget>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QRadioButton>

#include "widgets/customnumberinput.h"

class TaskTwoWidget : public QWidget {
    Q_OBJECT

public: 
    explicit TaskTwoWidget(QWidget* parent = nullptr);
    ~TaskTwoWidget();

private:
    NumberInput* xValue;
    NumberInput* mValue;

    QRadioButton* sh;
    QRadioButton* square;
    QRadioButton* e;

    QPushButton* button;
    QPlainTextEdit* resultText;
    double getFunction();
    double calculateSin();
    double calculateCos();
    double calculateSquare();

private slots:
    void printResult();
};

#endif // TASKTWO_H