#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->firstArgument, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &Calculator::recalculate);
    connect(ui->secondArgument, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &Calculator::recalculate);
    connect(ui->operation, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &Calculator::recalculate);
}

void Calculator::recalculate()
{
    int firstNumber = ui->firstArgument->value();
    int secondNumber = ui->secondArgument->value();
    int sign = ui->operation->currentText().at(0).unicode();
    int result = 0;
    switch(sign)
    {
    case '+':
        result = firstNumber + secondNumber;
        break;
    case '-':
        result = firstNumber - secondNumber;
        break;
    case '*':
        result = firstNumber * secondNumber;
        break;
    case '/':
        if (secondNumber)
            result = firstNumber / secondNumber;
        else
            result = 0;
    }
    ui->answer->setText(QString::number(result));
}

Calculator::~Calculator()
{
    delete ui;
}
