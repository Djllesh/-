#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
void Reverse(vector<int>& v)
{
	reverse(begin(v), end(v));
}

vector<int> Reversed(const vector<int>& v)
{
	 vector<int> vv = v;
	 Reverse(vv);
	 return vv;
}