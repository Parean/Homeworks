#pragma once

#include <QMainWindow>
#include <QGridLayout>
#include <QSpinBox>
#include <QSignalMapper>
#include <QVector>

#include "eventhandler.h"

/**
 * @class The MainWindow class
 * Class contains the implementation of the main window for playing in tic tac toe
 * The program allows the user to choose the size of the field and length of winning chain,
 * however, it does not allow to do the length of the chain less than three or more than the size of the field
 * It also does not allow to do the size of the field less than three, because in that case the game becomes meaningless
 * The default length and size equal three
 */
class MainWindow : public QWidget
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

signals:
	void startGame() const;
	void finishGame() const;

private slots:
	/**
	 * @brief changeSizeOfField
	 * This slot is called when the user changes the size of the field
	 */
	void changeSizeOfField();

	/**
	 * @brief changeLengthOfChain
	 * This slot is called when the user changes the length of the winning chain
	 */
	void changeLengthOfChain();

	/**
	 * @brief startNewGame
	 * This slot is called when user clicked on the New Game button;
	 */
	void startNewGame();

	/**
	 * @brief showMessage
	 * This slot receives the gameOver signal, displays on the screen message from
	 * it and then asks the user about his desire to continue the game
	 */
	void showMessage(const QString &message);

private:
	int sizeOfField = 3;

	QSignalMapper *signalMapper = new QSignalMapper(this);
	QGridLayout *buttonsLayout = new QGridLayout();
	QSpinBox *spinBoxField = new QSpinBox();
	QSpinBox *spinBoxChain = new QSpinBox();
	QVector<PlayingButton *> buttons;
	EventHandler *eventHandler = nullptr;

	/**
	 * @brief fillTheFeild
	 * This function puts the buttons on the playing field
	 */
	void fillTheFeild();
	void deleteButtons();
};


