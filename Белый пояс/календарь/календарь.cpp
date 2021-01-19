#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std; 
int iter = 0;

vector<vector<string>> next(vector<vector<string>>& v, vector<int> days)
{
	if (iter < 11)
	{
		iter++;
		if (days[iter] > days[iter - 1])
		{
			v.resize(days[iter]);
		}
		else
		{
			vector<vector<string>> v2 = v;
			v.resize(days[iter]);
			for (int i = days[iter]; i <= days[iter-1]-1; i++)
			{
				for (auto c : v2[i])
				{
					v[days[iter] - 1].push_back(c);
				}
			}
		}
	}
	else
	{
		iter = 0;
		v.resize(days[iter]);
	}
	return v;
}

int main()
{
	vector<int> days = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	vector<vector<string>> duties(days[0]);
	int q;
	string s;
	cin >> q;
	
	for  (int i = 0; i < q; i++)
	{
		cin >> s;
		if (s == "ADD")
		{
			int add_pos;
			string duty;
			cin >> add_pos >> duty;
			duties[add_pos - 1].push_back(duty);
		}
		if (s == "DUMP")
		{
			int dump_day;
			cin >> dump_day;
			cout << duties[dump_day - 1].size() << ' ';
			for (auto c : duties[dump_day - 1])
			{
				cout << c << ' ';
			}
			cout << endl;
		}
		if (s == "NEXT")
		{
			duties = next(duties, days);
		}
	}
	return 0;
}
