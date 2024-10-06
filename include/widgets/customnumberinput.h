#ifndef NUMBERINPUT_H
#define NUMBERINPUT_H

#include <QLineEdit>

class NumberInput : public QLineEdit {
    Q_OBJECT

public:
    explicit NumberInput(QWidget* parent = nullptr);
    ~NumberInput();

    double getValue();
};

#endif // NUMBERINPUT_H