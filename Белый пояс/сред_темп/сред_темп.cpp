#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(const vector<int>& v)
{
	for (auto c : v)
	{
		cout << c << ' ';
	}
}

vector<int> averTemp(const vector<int>& v)
{
	int aver = 0;
	int i = 0;
	for (auto c : v)
	{
		aver += c;
	}
	aver /= v.size();
	for (auto c : v)
	{
		if (c > aver)
		{
			i++;
		}
	}
	vector<int> res;
	res.push_back(i);
	int j = 0;
	for (auto c : v)
	{
		if (c > aver)
		{
			res.push_back(j);
		}
		j++;
	}
	return res;
}


int main()
{
	int n;
	cin >> n;
	vector<int> temp(n);
	for (int i = 0; i< n; i++)
	{
		cin >> temp[i];
	}
	for (auto c : averTemp(temp))
	{
		//cout << averTemp(temp)[0] << endl;
		cout << c << ' ';
	}
	return 0;
}
