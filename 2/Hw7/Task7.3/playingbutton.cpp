#include "playingbutton.h"

PlayingButton::PlayingButton(int x, int y):
	x(x),
	y(y){}

int PlayingButton::getX() const
{
	return x;
}

int PlayingButton::getY() const
{
	return y;
}

void PlayingButton::setX(int value)
{
	x = value;
}

void PlayingButton::setY(int value)
{
	y = value;
}
