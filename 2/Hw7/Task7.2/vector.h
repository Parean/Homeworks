#pragma once

#pragma once

class OutOfRange {};

/** @class Vector
 * Template class that contains implementation of n-dimensional vector
 */
template <int n>
class Vector
{
public:

	/**
	 * @brief Create null vector
	 */
	Vector();
	/**
	 * @brief Create vector of elements from input array
	 */
	Vector(const int *array);
	Vector(const Vector<n> &inputVector);

	bool isNull() const;

	/**
	 * @return Return i-th coordinate of vector
	 */
	int at(const int i) const throw(OutOfRange);

	/**
	 * @brief operator == check of vector equality
	 */
	bool operator == (const Vector<n> &secondVector) const;

	/**
	 * @brief operator - represents difference of vectors
	 */
	Vector<n> operator - (const Vector<n> &secondVector) const;

	/**
	 * @brief operator + represents sum of vectors
	 */
	Vector<n> operator + (const Vector<n> &secondVector) const;

	/**
	 * @brief operator * represents scalar product of vectors
	 */
	int operator * (const Vector<n> &secondVector) const;

private:
	int vector[n];
};

template <int n>
Vector<n>::Vector()
{
	for (int i = 0; i < n; i++)
		vector[i] = 0;
}

template <int n>
Vector<n>::Vector(const int *array)
{
	for (int i = 0; i < n; i++)
		vector[i] = array[i];
}

template <int n>
Vector<n>::Vector(const Vector<n> &inputVector)
{
	for (int i = 0; i < n; i++)
		vector[i] = inputVector.at(i);
}

template <int n>
int Vector<n>::at(const int i) const throw(OutOfRange)
{
	if (i < 0 || i >= n)
		throw OutOfRange();

	return vector[i];
}

template <int n>
bool Vector<n>::isNull() const
{
	for (int i = 0; i < n; i++)
		if (vector[i])
			return false;

	return true;
}

template <int n>
Vector<n> Vector<n>::operator + (const Vector<n> &secondVector) const
{
	int newVector[n];

	for (int i = 0; i < n; i++)
		newVector[i] = this->at(i) + secondVector.at(i);

	return Vector<n>(newVector);
}

template <int n>
Vector<n> Vector<n>::operator - (const Vector<n> &secondVector) const
{
	int newVector[n];

	for (int i = 0; i < n; i++)
		newVector[i] = this->at(i) - secondVector.at(i);

	return Vector<n>(newVector);
}

template <int n>
int Vector<n>::operator * (const Vector<n> &secondVector) const
{
	int product = 0;
	for (int i = 0; i < n; i++)
		product += this->at(i) * secondVector.at(i);

	return product;
}

template <int n>
bool Vector<n>::operator == (const Vector<n> &secondVector) const
{
	for (int i = 0; i < n; i++)
		if (this->at(i) != secondVector.at(i))
			return false;

	return true;
}
