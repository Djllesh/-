#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	set<string> min_str;
	for (int i = 0; i <n; i++)
	{
		cin >> s;
		min_str.insert(s);
	}
	cout << min_str.size();
	return 0;
}
