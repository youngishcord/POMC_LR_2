#ifndef TASKTWO_H
#define TASKTWO_H

#include <QWidget>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QRadioButton>
#include <QRandomGenerator>
#include <QVBoxLayout>
#include <QMap>
#include <QLabel>

#include <vector>

#include "widgets/customnumberinput.h"

class TaskTwoWidget : public QWidget {
    Q_OBJECT

public: 
    explicit TaskTwoWidget(QWidget* parent = nullptr);
    ~TaskTwoWidget();

private:
    QVBoxLayout* randomLay;
    QMap<int, std::function<std::unique_ptr<QWidget>()>> widgetFactory = {
        {1, []() {
            auto widget = std::make_unique<QPushButton>("Button Widget");
            widget->setFixedWidth(QRandomGenerator::global()->bounded(100, 400));
            return widget;
            }},
        {2, []() {
            auto widget = std::make_unique<QLabel>("Label Widget");
            widget->setFixedWidth(QRandomGenerator::global()->bounded(100, 400));
            return widget;
            }},
        {3, []() {
            auto widget = std::make_unique<QTextEdit>("Text Edit Widget");
            widget->setFixedWidth(QRandomGenerator::global()->bounded(100, 400));
            return widget;
            }},
    };

private slots:
    void generator();
};

#endif // TASKTWO_H