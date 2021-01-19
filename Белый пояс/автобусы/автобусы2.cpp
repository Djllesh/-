#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int q;
	cin >> q;
	map<vector<string>, int> stops_and_buses;
	for (int i = 0; i < q; i++)
	{
		int n;
		cin >> n;
		vector<string> temp_stops;
		string stop;
		bool pr = false;
		for (int i = 0; i < n; i++)
		{
			cin >> stop;
			temp_stops.push_back(stop);
		}
		if (stops_and_buses.size() != 0)
		{
			for (const auto& item : stops_and_buses)
			{
				if (item.first == temp_stops)
				{
					cout << "Already exists for " << item.second << endl;
					pr = true;
					break;
				}
			}
		}

		if(stops_and_buses.size() == 0 || !pr)
		{
			int new_val = stops_and_buses.size();
			stops_and_buses[temp_stops] = new_val + 1;
			cout << "New bus " << new_val + 1 << endl;
		}
	}
	return 0;
}
