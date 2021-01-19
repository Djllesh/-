#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool IsPalindrom(string n)
{
	string s = n;
	reverse(n.begin(), n.end());
	if (s == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string ss;
	cin >> ss;
	cout << IsPalindrom(ss);
	return 0;
}
