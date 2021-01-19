#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
	T* Allocate()
	{
		if ((bool)Deallocated.empty())
		{
			auto data = new T;
			auto it = Allocated.insert(data);
			return *it.first;
		}
		else
		{
			auto it = Allocated.insert(Deallocated.front());
			Deallocated.pop();
			return *it.first;
		}
	}

	T* TryAllocate()
	{
		if ((bool)Deallocated.empty()) return nullptr;
		else return Allocate();
	}

	void Deallocate(T* object)
	{
		
		if (Allocated.find(object) != Allocated.end())
		{
			Deallocated.push(object);
			Allocated.erase(object);
		}
		else
		{
			throw invalid_argument("No such an object found in allocated memory");
		}
	}

	~ObjectPool()
	{
		auto italloc = Allocated.begin();
		while ((bool)!Allocated.empty() || (bool)!Deallocated.empty())
		{
			
			if (italloc != Allocated.end())
			{
				delete* italloc;
				italloc = Allocated.erase(italloc);			
			}
			if ((bool)!Deallocated.empty())
			{
				delete Deallocated.front();
				Deallocated.pop();
			}
		}
	}

private:
	// Добавьте сюда поля
	set<T*> Allocated;
	queue<T*> Deallocated;
};

void TestObjectPool() {
	ObjectPool<string> pool;

	auto p1 = pool.Allocate();
	auto p2 = pool.Allocate();
	auto p3 = pool.Allocate();
	
	*p1 = "first";
	*p2 = "second";
	*p3 = "third";

	pool.Deallocate(p2);
	ASSERT_EQUAL(*pool.Allocate(), "second");

	pool.Deallocate(p3);
	pool.Deallocate(p1);
	ASSERT_EQUAL(*pool.Allocate(), "third");
	ASSERT_EQUAL(*pool.Allocate(), "first");

	pool.Deallocate(p1);

}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestObjectPool);
	return 0;
}
