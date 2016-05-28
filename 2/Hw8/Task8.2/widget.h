#pragma once

#include "bash.h"

#include <QWidget>

namespace Ui {
class Widget;
}

/**
 * @class Widget
 * Class contains the implementation of the main window for watching quotes from bash.im
 * The program allows the user to change rating of quotes
 */
class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

private slots:

	///Functions for change rating called when user click on the appropriate button
	void setRatingDown();
	void setRatingUp();
	void setBayan();

	///Allows get next quote when user click on button "Next"
	void getNextQuote();

	///Funtion loads quote anew
	void reload();


private:
	Bash bash;
	Ui::Widget *ui;
	int currentRating = 0;
	int currentQuote = -1;

	///It makes elements active or inactive depending on the passed parameter
	void setEnabledOfRatingElements(bool isActive);
};

