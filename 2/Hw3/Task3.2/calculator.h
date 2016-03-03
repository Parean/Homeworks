#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

/**
 * @class Calculator
 * Class which represents the implementation of widget for calculating arithmetic expressions
 */

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:

    ///Automatically called when user change the value or operation argument

    void recalculate();
};

#endif // CALCULATOR_H
