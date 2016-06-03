#include "quote.h"

Quote::Quote(const QString &id, const QString &quote, const QString &rating):
	id(id),
	quote(quote),
	rating(rating)
{}

QString Quote::getId() const
{
	return id;
}

QString Quote::getQuote() const
{
	return quote;
}

QString Quote::getRating() const
{
	return rating;
}
