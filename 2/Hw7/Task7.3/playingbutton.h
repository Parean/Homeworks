#pragma once

#include <QPushButton>

/**
 * @brief The PlayingButton class
 * Represents the implementation of the playing button that stores its coordinates
 */
class PlayingButton : public QPushButton
{
public:
	PlayingButton(int x, int y);
	~PlayingButton() {}

	int getX() const;
	int getY() const;

	void setX(int value);
	void setY(int value);

private:
	int x = 0;
	int y = 0;
};
