#pragma once

#include "playingbutton.h"

/**
 * @class The EventHandler class
 * This class contains the logic of the game
 */
class EventHandler : public QObject
{
	Q_OBJECT

public:

	/**
	 * @brief EventHandler
	 * The constructor takes the field size and the length of a winning chain, and
	 * then creates a two-dimensional array that stores the player's moves
	 */
	EventHandler(int size, int length);
	~EventHandler();

	/**
	 * @brief setLengthOfChain
	 * This function is called from MainWindow when you need to change the length of the chain
	 */
	void setLengthOfChain(int value);

	/**
	 * @brief move
	 * This function allows play in tic tac toe without graphical interface
	 */
	void move(int x, int y);

public slots:

	/**
	 * @brief clicked
	 * This slot is called when button was clicked and takes as a parameter the pressed button
	 */
	void move(QWidget *widget);

	/**
	 * @brief startNewGame
	 * This slot is called when user clicked on the New Game button;
	 */
	void startNewGame();

signals:

	/**
	 * @brief gameOver
	 * The signal emited when somebody have won or all buttons were clicked
	 */
	void gameOver(const QString &) const;

private:
	int numberOfButtons = 0;
	int sizeOfField = 0;
	int lengthOfChain = 0;
	int numberOfClickedButtons = 0;
	char **field;
	int currentX = 0;
	int currentY = 0;

	/**
	 * @brief updateField
	 * This function updates the field of play after the player's move
	 * As parameters it accepts coordinates in which the player has moved
	 */
	void updateField(int x, int y);

	/**
	 * @brief resetField
	 * This function reset all user`s moves (reset array)
	 */
	void resetField();

	/**
	 * @brief isSmbWin
	 * @return true if there is a winning chain on current move
	 * @return false if there is not
	 */
	bool isSmbWin() const;

	///All these funtions returns true if chain is winning
	bool checkColumn() const;
	bool checkString() const;
	bool checkMainDiagonal() const;
	bool checkSecondaryDiagonal() const;

	/**
	 * @brief getCurrentSymbol
	 * Determines which symbol you need to put on the button on this move
	 */
	char getCurrentSymbol() const;

	/**
	 * @brief setCurrentSymbol
	 * Put on the button current symbol
	 */
	void setCurrentSymbol(PlayingButton *button);
};
