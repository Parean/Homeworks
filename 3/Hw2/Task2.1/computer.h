#pragma once

#include <QString>

/**
 * @brief The Computer class
 * Virtual class implements computer without operating system
 */
class Computer
{
public:
	virtual ~Computer() {}

	/**
	 * @brief isInfected
	 * @return true if computer is infected and false if not
	 */
	bool isInfected() const
	{
		return computerInfected;
	}

	/**
	 * @brief setInfected
	 * Function to make computer infected
	 */
	void setInfected()
	{
		computerInfected = true;
	}

	/**
	 * @brief getProbability
	 * @return probability of infection
	 * The probability depends on the type derived class system
	 */
	virtual int getProbability() const = 0;

	/**
	 * @brief getSystem
	 * @return type of operating system
	 */
	virtual QString getSystem() const = 0;

protected:
	int const probabilityOfInfection = 0;

private:
	bool computerInfected = false;
};

