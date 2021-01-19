#pragma once

#include <cstdlib>
#include <algorithm>
// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
	SimpleVector();
	SimpleVector(const SimpleVector& other);
	explicit SimpleVector(size_t size);
	

	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	void operator=(const SimpleVector& other);

	T* begin();
	T* end();
	const T* begin() const;
	const T* end() const;

	size_t Size() const;
	size_t Capacity() const;
	void PushBack(const T& value);
	~SimpleVector();

private:
	// Добавьте поля для хранения данных вектора
	T* data;
	size_t size;
	size_t capacity;
};

template <typename T>
SimpleVector<T>::SimpleVector()
{
	data = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
SimpleVector<T>::SimpleVector(const SimpleVector<T>& other) : data(new T[other.capacity]), size(other.size), capacity(other.capacity)
{
	std::copy(other.begin(), other.end(), begin());
}

template <typename T>
SimpleVector<T>::SimpleVector(size_t size_)
{
	data = new T[size_];
	size = size_;
	capacity = size_;
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
void SimpleVector<T>::operator=(const SimpleVector& rhs) {
	if (rhs.size <= capacity) {
		
		std::copy(rhs.begin(), rhs.end(), begin());
		size = rhs.size;
	}
	else {
		SimpleVector<T> tmp(rhs);
		std::swap(tmp.data, data);
		std::swap(tmp.size, size);
		std::swap(tmp.capacity, capacity);
	}
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
	return data + size; 
}


template <typename T>
const T* SimpleVector<T>::end() const 
{
	return data + size; 
}

template <typename T>
size_t SimpleVector<T>::Size() const
{ 
	return size; 
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
		size = 1; 
		capacity = 1;
		(*this)[0] = value;
		return;
	}
	if(Size() == Capacity())
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
		size++;
	}
	else
	{
		data[Size()] = value;
		size++;
	}
	
}

template<typename T>
SimpleVector<T>::~SimpleVector()
{
	delete[] data;
}