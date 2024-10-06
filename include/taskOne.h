#ifndef TASKONE_H
#define TASKONE_H

#include <QWidget>
#include <QPushButton>
#include <QPlainTextEdit>

#include "widgets/customnumberinput.h"

class TaskOneWidget : public QWidget {
    Q_OBJECT

public: 
    explicit TaskOneWidget(QWidget* parent = nullptr);
    ~TaskOneWidget();

private:
    NumberInput* xStart;
    NumberInput* xStop;
    NumberInput* Step;

    QPushButton* button;
    QPlainTextEdit* resultText;
    double calculate(double x);

private slots:
    void printResult();
};

// #include "taskOne.moc"

#endif // TASKONE_H