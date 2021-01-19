#pragma once
#include <mutex>
using namespace std;
template <typename T>
class Synchronized {
public:
	explicit Synchronized(T initial = T()) : value_(move(initial)) {}

	struct Access
	{
		T& ref_to_value;
		lock_guard<mutex> guard_;
	};

	Access GetAccess();
private:
	T value_;
	mutex mutex_;
};


template <typename T>
typename Synchronized<T>::Access Synchronized<T>::GetAccess()
{
	return { value_, lock_guard(mutex_) };
}

