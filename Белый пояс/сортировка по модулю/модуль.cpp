#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void PrintVec(const vector<int>& v)
{
	for (const auto& el : v)
	{
		cout << el << " ";
	} 
}
int main()
{
	int n, element;
	cin >> n;
	vector<int> my_vec;
	for (int i = 0; i < n; i++)
	{
		cin >> element;
		my_vec.push_back(element);
	}
	sort(my_vec.begin(), my_vec.end(), [](int x, int y) {if (abs(x) < abs(y)) {return true;}return false;});
	PrintVec(my_vec);
	return 0;
}
