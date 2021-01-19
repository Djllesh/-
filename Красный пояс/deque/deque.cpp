#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

template<class T>
class Deque
{
private: 
	vector<T> front, back;
	
	void Reassign()
	{
		reverse(front.begin(), front.end());
		if (back != front)
		{
			front = back;
			reverse(front.begin(), front.end());
		}
		reverse(front.begin(), front.end());
	}

	
public: 
	Deque() = default;
	bool Empty() const
	{
		if (front.empty())
		{
			return true; 
		}
		return false;
	}



	const size_t Size() const
	{
		return back.size();
	}

	T& operator[](size_t index)
	{
		Reassign();
		return At(index);
	}

	const T& operator[](size_t index) const
	{
		return At(index);
	}

	const T& At(size_t index) const
	{
		if (index <= back.size())
		{
			Reassign();
			return back[index];
		}
		else throw out_of_range("");
	}

	T& At(size_t index)
	{
		if (index <= back.size())
		{
			Reassign();
			return back[index];
		}
		else throw out_of_range("");
	}

	T& Back()
	{
		Reassign();
		return At(Size() - 1);
	}

	T& Front()
	{
		Reassign();
		return At(0);
	}

	const T& Back() const 
	{
		return At(Size()-1);
	}

	const T& Front() const 
	{
		return At(0);
	}

	void PushBack(const T& item)
	{
		Reassign();
		back.push_back(item);
		front.assign(back.rbegin() , back.rend());
	}

	void PushFront(const T& item)
	{
		Reassign();
		front.push_back(item);
		back.assign(front.rbegin(), front.rend());
	}
	
};