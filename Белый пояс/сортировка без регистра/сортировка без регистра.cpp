#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void PrintVec(const vector<string>& v)
{
	for (const auto& el : v)
	{
		cout << el << " ";
	} 
}
bool convert_and_compare(string x, string y)
{
	transform(x.begin(), x.end(), x.begin(), [](unsigned char c) {return tolower(c); });
	transform(y.begin(), y.end(), y.begin(), [](unsigned char c) {return tolower(c); });
	return x < y;
}
int main()
{
	int n;
	cin >> n;
	vector<string> my_vec(n);
	for (auto& element : my_vec)
	{
		cin >> element;
	}
	sort(my_vec.begin(), my_vec.end(), convert_and_compare);
	PrintVec(my_vec);
	return 0;
}
