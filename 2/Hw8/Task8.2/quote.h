#pragma once

#include <QString>

/**
 * @class Quote
 * Represents a class that keep quotes
 */
class Quote
{
public:
	Quote(const QString &id, const QString &quote, const QString &rating);
	~Quote() {}

	QString getQuote() const;
	QString getId() const;
	QString getRating() const;

private:

	QString id = 0;
	QString quote;
	QString rating = 0;
};
