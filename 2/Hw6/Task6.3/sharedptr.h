#pragma once

/**
 * @class SharedPtr
 * The template class which provides the implementation of a smart pointer
 * that knows how to count references to an allocated memory
 */
template <typename T>
class SharedPtr
{
public:
	SharedPtr(T *pointer);
	SharedPtr(const SharedPtr<T> &sharedPtr);

	/**
	 * @return a pointer to the managed object
	 */
	T *get() const;

	/**
	 * @return the number of different sharedPtr instances (this included)
	 * managing the current object
	 */
	int useCount() const;

	/**
	 * @brief Checks if *this is the only sharedPtr instance managing the current
	 * object, i.e. whether referenceCount == 1
	 *
	 * @return true if *this is the only sharedPtr instance managing the current
	 * object, false otherwise.
	 */
	bool unique() const;

	/**
	 * @brief Exchanges the contents of *this and sharedPtr
	 */
	void swap(SharedPtr<T> &sharedPtr);

	/**
	 * @return the result of dereferencing the stored pointer, i.e., *get()
	 */
	T &operator * () const;

	/**
	 * @brief operator = Replaces the managed object with the one managed by sharedPtr
	 */
	void operator = (const SharedPtr<T> &sharedPtr);

	~SharedPtr();

private:

	/**
	 * @struct Storage
	 * Contains pointer pointer to the managed object and the
	 * number of different sharedPtr instances
	 */
	struct Storage
	{
		T *pointer = nullptr;
		int referenceCount = 1;

		Storage(T *pointer):
			pointer(pointer)
		{}

		~Storage()
		{
			delete pointer;
		}
	};

	Storage *storage;
};

template <typename T>
SharedPtr<T>::SharedPtr(T *pointer): storage(new Storage(pointer)){}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &sharedPtr):
	storage(sharedPtr.storage)
{
	storage->referenceCount++;
}

template <typename T>
T *SharedPtr<T>::get() const
{
	return storage->pointer;
}

template <typename T>
int SharedPtr<T>::useCount() const
{
	return storage->referenceCount;
}

template <typename T>
bool SharedPtr<T>::unique() const
{
	return storage->referenceCount == 1;
}

template <typename T>
void SharedPtr<T>::swap(SharedPtr<T> &sharedPtr)
{
	SharedPtr<T> temp(sharedPtr);
	sharedPtr = *this;
	*this = temp;
}

template <typename T>
void SharedPtr<T>::operator = (const SharedPtr<T> &sharedPtr)
{
	delete this;
	this->storage = sharedPtr.storage;
	this->storage->referenceCount++;
}

template <typename T>
T &SharedPtr<T>::operator * () const
{
	return *(storage->pointer);
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
	storage->referenceCount--;

	if (storage->referenceCount == 0)
		delete storage;
}
