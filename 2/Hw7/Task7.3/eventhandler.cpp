#include "eventhandler.h"

EventHandler::EventHandler(int size, int length) :
	numberOfButtons(size * size),
	sizeOfField(size),
	lengthOfChain(length)
{
	field = new char *[sizeOfField];
	for(int i = 0; i < sizeOfField; i++)
		field[i] = new char[sizeOfField];

	resetField();
}

void EventHandler::resetField()
{
	for(int i = 0; i < sizeOfField; i++)
		for(int j = 0; j < sizeOfField; j++)
			field[i][j] = '-';
}

char EventHandler::getCurrentSymbol() const
{
	if (numberOfClickedButtons % 2)
		return '0';
	else
		return 'X';
}

void EventHandler::setCurrentSymbol(PlayingButton *button)
{
	button->setText(QString(getCurrentSymbol()));
	button->setEnabled(false);
}

void EventHandler::setLengthOfChain(int value)
{
	lengthOfChain = value;
}

void EventHandler::startNewGame()
{
	resetField();
	numberOfClickedButtons = 0;
}

void EventHandler::move(QWidget *widget)
{
	PlayingButton *button = static_cast<PlayingButton*>(widget);
	setCurrentSymbol(button);
	updateField(button->getX(), button->getY());
}

void EventHandler::move(int x, int y)
{
	updateField(x, y);
}

void EventHandler::updateField(int x, int y)
{
	currentX = x;
	currentY = y;
	field[currentX][currentY] = getCurrentSymbol();

	if (isSmbWin())
	{
		QString message(QString("Player %1 win").arg(QString(getCurrentSymbol())));
		emit gameOver(message);
	}
	else if (++numberOfClickedButtons == numberOfButtons)
	{
		QString message("Draw");
		emit gameOver(message);
	}
}

bool EventHandler::isSmbWin() const
{
	return (checkColumn() || checkString() ||
			checkMainDiagonal() || checkSecondaryDiagonal());
}


bool EventHandler::checkColumn() const
{
	int length = 1;

	int y = currentY - 1;
	while ((y >= 0) && (field[currentX][y] == getCurrentSymbol()))
	{
		length++;
		y--;
	}

	y = currentY + 1;
	while ((y < sizeOfField) && (field[currentX][y] == getCurrentSymbol()))
	{
		length++;
		y++;
	}

	return length >= lengthOfChain;
}

bool EventHandler::checkString() const
{
	int length = 1;

	int x = currentX - 1;
	while ((x >= 0) && (field[x][currentY] == getCurrentSymbol()))
	{
		length++;
		x--;
	}

	x = currentX + 1;
	while ((x < sizeOfField) && (field[x][currentY] == getCurrentSymbol()))
	{
		length++;
		x++;
	}

	return length >= lengthOfChain;
}

bool EventHandler::checkMainDiagonal() const
{
	int length = 1;

	int x = currentX - 1;
	int y = currentY - 1;
	while ((x >= 0) && (y >= 0) && (field[x][y] == getCurrentSymbol()))
	{
		length++;
		x--;
		y--;
	}

	x = currentX + 1;
	y = currentY + 1;
	while ((x < sizeOfField) && (y < sizeOfField) && (field[x][y] == getCurrentSymbol()))
	{
		length++;
		x++;
		y++;
	}

	return length >= lengthOfChain;
}

bool EventHandler::checkSecondaryDiagonal() const
{
	int length = 1;

	int x = currentX + 1;
	int y = currentY - 1;
	while ((x < sizeOfField) && (y >= 0) && (field[x][y] == getCurrentSymbol()))
	{
		length++;
		x++;
		y--;
	}

	x = currentX - 1;
	y = currentY + 1;
	while ((x >= 0) && (y < sizeOfField) && (field[x][y] == getCurrentSymbol()))
	{
		length++;
		x--;
		y++;
	}

	return length >= lengthOfChain;
}

EventHandler::~EventHandler()
{
	for(int i = 0; i < sizeOfField; i++)
		delete[] field[i];
	delete[] field;
}
