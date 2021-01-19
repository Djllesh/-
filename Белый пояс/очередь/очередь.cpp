#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void Worry(vector<bool>& v, int n)
{
	v[n] = true;
}

void Quiet(vector<bool>& v, int n)
{
	v[n] = false;
}
void Come(vector<bool>& v, int n)
{
	if (n > 0) 
	{
		for (int i = 0; i < n; i++)
		{
			v.push_back(false);
		}
	}
	else
	{
		while (n < 0)
		{
			v.pop_back();
			n++;
		}
	}
}
int Worry_Count(vector<bool>& v)
{
	int i = 0;
	for (auto c : v)
	{
		if (c)
		{
			i++;
		}
	}
	return i;
}
int main()
{
	int q;
	cin >> q;
	string s;
	vector<bool> queue;
	while (q>0)
	{
		cin >> s;
		if (s == "COME")
		{
			int n;
			cin >> n;
			Come(queue, n);
		}
		else if (s == "WORRY")
		{
			int n;
			cin >> n;
			Worry(queue, n);
		}
		else if (s == "QUIET")
		{
			int n;
			cin >> n;
			Quiet(queue, n);
		}
		else if (s == "WORRY_COUNT")
		{
			cout << Worry_Count(queue) << "\n";
		}
		q--;
	}
	return 0;
}