#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
set<string> BuildMapValuesSet(const map<int, string>& m)
{
	set<string> our_new_set;
	for(const auto& item: m)
	{
		our_new_set.insert(item.second);
	}
	return our_new_set;
}