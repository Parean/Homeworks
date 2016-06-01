#pragma once

#include "quote.h"

#include <QtCore/QObject>
#include <QVector>
#include <QWebPage>

/**
 * @class Bash
 * Represents the storage of quotes from bash.im with the ability to send
 * requests to website
 */
class Bash : public QObject
{
	Q_OBJECT

public:

	Bash();
	virtual ~Bash() {}

	/**
	 * @brief getQuote
	 * @return the quote with with the specified index
	 */
	QString getQuote(int index) const;

	/**
	 * @brief getRating
	 * @return rating of the quote with the specified index
	 */
	QString getRating(int index) const;

	void setRatingUp(int index);
	void setRatingDown(int index);
	void setBayan(int index);

	/**
	 * @brief sendRequest
	 * Function called from setRatingUp(), setRatingDown() and setBayan() to send request which will change rating of quote
	 */
	void sendRequest(const QString &id, const QString &param);

	/**
	 * @brief loadQuotes
	 * Load data from bash.im
	 */
	void loadQuotes();

	/**
	 * @brief isParsingFinished
	 * @return true if parsing of quotes was finished
	 */
	bool isParsingFinished() const;

	/**
	 * @brief getNumberOfQuotes
	 * @return current number of quotes
	 */
	int getNumberOfQuotes() const;

signals:

	/**
	 * @brief endOfParsing
	 * Emit in the end funtion parseQuotes()
	 */
	void endOfParsing();

private slots:

	/**
	 * @brief parseQuotes
	 * Funtion parse data from bash.im
	 */
	void parseQuotes();

private:

	bool parsingFinished = false;
	QWebPage page;
	QVector<Quote *> quotes;

	/**
	 * @brief getId
	 * @return id of the quote with the specified index
	 */
	QString getId(int index) const;
	void clearQuotes();
};
