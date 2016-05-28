#include "bash.h"

#include <QString>
#include <QWebFrame>
#include <QWebElement>
#include <QNetworkRequest>

Bash::Bash()
{
	loadQuotes();
	connect(&page, SIGNAL(loadFinished(bool)),
			this, SLOT(parseQuotes()));
}



void Bash::loadQuotes()
{
	parsingFinished = false;
	page.mainFrame()->load(QUrl("http://bash.im"));
}

void Bash::clearQuotes()
{
	for(auto i : quotes)
		delete i;

	quotes.clear();
}

void Bash::parseQuotes()
{
	clearQuotes();
	auto container = page.mainFrame()->documentElement().findAll("div[class=quote]");

	for (auto i : container)
	{
		if (i.findFirst("div[class=actions]").isNull())
			continue;

		QString id = i.findFirst("a[class=id]").toPlainText().remove(0,1);
		QString quote = i.findFirst("div[class=text]").toPlainText();
		QString rating = i.findFirst("span[class=rating]").toPlainText();

		quotes.push_back(new Quote(id, quote, rating));
	}

	parsingFinished = true;
	endOfParsing();
}

bool Bash::isParsingFinished() const
{
	return parsingFinished;
}

int Bash::getNumberOfQuotes() const
{
	return quotes.size();
}

QString Bash::getQuote(int index) const
{
	return quotes.at(index)->getQuote();
}

QString Bash::getId(int index) const
{
	return quotes.at(index)->getId();
}

QString Bash::getRating(int index) const
{
	return quotes.at(index)->getRating();
}

void Bash::setRatingDown(int index)
{
	sendRequest(quotes.at(index)->getId(), QString("sux"));
}

void Bash::setRatingUp(int index)
{
	sendRequest(quotes.at(index)->getId(), QString("rulez"));
}

void Bash::setBayan(int index)
{
	sendRequest(quotes.at(index)->getId(), QString("bayan"));
}

void Bash::sendRequest(const QString &id, const QString &param)
{
	QNetworkAccessManager manager;
	QNetworkRequest request(QUrl(QString("http://bash.im/quote/%1/%2").arg(id, param)));
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	manager.post(request, QString("quote=%1&act=%2").arg(id, param).toUtf8());
}



