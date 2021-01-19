#pragma once
#include <cstdlib>


template <typename T>
class SimpleVector
{
public:
	SimpleVector();
	explicit SimpleVector(size_t size);
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	T* begin();
	T* end();
	const T* begin() const;
	const T* end() const;
	size_t Size() const;
	size_t Capacity() const;
	void PushBack(const T& value);
	~SimpleVector();

private:
	T* data;
	size_t size_;
	size_t capacity;
};


template <typename T>
SimpleVector<T>::SimpleVector()
{
	data = nullptr;

	size_ = 0;
	capacity = 0;
}


template <typename T>
SimpleVector<T>::SimpleVector(size_t size)
{
	data = new T[size];

	size_ = size;
	capacity = size;
}


template<typename T>
T& SimpleVector<T>::operator[](size_t index)
{
	return data[index];
}


template<typename T>
const T& SimpleVector<T>::operator[](size_t index) const
{
	return data[index];
}


template <typename T>
T* SimpleVector<T>::begin()
{
	return data;
}


template <typename T>
const T* SimpleVector<T>::begin() const
{
	return data;
}


template <typename T>
T* SimpleVector<T>::end()
{
	return data + size_;
}


template <typename T>
const T* SimpleVector<T>::end() const
{
	return data + size_;
}


template <typename T>
size_t SimpleVector<T>::Size() const
{
	return size_;
}


template <typename T>
size_t SimpleVector<T>::Capacity() const
{
	return capacity;
}


template<typename T>
void SimpleVector<T>::PushBack(const T& value)
{
	if (data == nullptr)
	{
		data = new T[1];
		size_ = 1;
		capacity = 1;
		(*this)[0] = value;
		return;
	}

	if (Size() == Capacity())
	{
		T* old_data = new T[Capacity() + 1];

		for (size_t i = 0; i < Size(); i++)
		{
			old_data[i] = data[i];
		}
		old_data[Size()] = value;

		delete[] data;
		data = new T[2 * Capacity()];

		for (size_t i = 0; i < Size(); i++)
		{
			data[i] = old_data[i];
		}
		data[Size()] = value;
		delete[] old_data;

		capacity *= 2;
		size_++;
	}
	else
	{
		data[Size()] = value;
		size_++;
	}

}


template<typename T>
SimpleVector<T>::~SimpleVector()
{
	delete[] data;
}
