#include <QSignalMapper>
#include <QLineEdit>
#include <QMainWindow>

#include "calculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	QSignalMapper *signalMapper;
	QLineEdit *lineEdit;
	Ui::MainWindow *ui;
	Calculator *calculator;

private slots:

	/**
	* Automatically called when the button is pressed so
	* that the text of a button is a parametr
	*/
	void clicked(const QString &text);
	void calculate();
	void clear();
};


