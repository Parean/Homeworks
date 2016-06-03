#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);

	connect(&bash, &Bash::endOfParsing, this, &Widget::getNextQuote);
	connect(ui->nextButton, &QPushButton::clicked, this, &Widget::getNextQuote);
	connect(ui->minusButton, &QPushButton::clicked, this, &Widget::setRatingDown);
	connect(ui->plusButton, &QPushButton::clicked, this, &Widget::setRatingUp);
	connect(ui->bayanButton, &QPushButton::clicked, this, &Widget::setBayan);
	connect(ui->loadButton, &QPushButton::clicked, this, &Widget::reload);
}

void Widget::getNextQuote()
{
	if(!bash.isParsingFinished())
		return;

	if (++currentQuote == bash.getNumberOfQuotes())
	{
		QMessageBox msgBox;
		msgBox.setText("You've seen all the quotes");
		msgBox.setInformativeText("Do you want to start over?");
		msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::NoButton);
		int ret = msgBox.exec();

		switch(ret)
		{
		case QMessageBox::Yes:
			reload();
			break;
		case QMessageBox::No:
			this->close();
			break;
		}

		return;
	}

	setEnabledOfRatingElements(true);
	ui->textEdit->setText(bash.getQuote(currentQuote));

	currentRating = bash.getRating(currentQuote).toInt();
	ui->ratingValueLineEdit->setText(QString::number(currentRating));
}

void Widget::setEnabledOfRatingElements(bool isActive)
{
	ui->plusButton->setEnabled(isActive);
	ui->minusButton->setEnabled(isActive);
	ui->bayanButton->setEnabled(isActive);
	ui->ratingValueLineEdit->setEnabled(isActive);
}

void Widget::setRatingDown()
{
	if(!bash.isParsingFinished())
		return;

	ui->ratingValueLineEdit->setText(QString::number(currentRating - 1));
	setEnabledOfRatingElements(false);

	bash.setRatingDown(currentQuote);
}

void Widget::setRatingUp()
{
	if(!bash.isParsingFinished())
		return;

	ui->ratingValueLineEdit->setText(QString::number(currentRating + 1));
	setEnabledOfRatingElements(false);

	bash.setRatingUp(currentQuote);
}

void Widget::setBayan()
{
	if(!bash.isParsingFinished())
		return;

	ui->ratingValueLineEdit->setText("(>＿<)");
	setEnabledOfRatingElements(false);

	bash.setBayan(currentQuote);
}

void Widget::reload()
{
	if(!bash.isParsingFinished())
		return;

	currentQuote = -1;
	bash.loadQuotes();
}

Widget::~Widget()
{
	delete ui;
}
