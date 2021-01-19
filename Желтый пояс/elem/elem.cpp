#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <exception>
using namespace std;
template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key elem)\
{
	const auto found = m.find(elem);
	if (found != m.cend())
	{
		return m[elem];
	}
	else
	{
		throw runtime_error("");
	}
}