#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void PrintVector(const vector<string>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
}
void PrintMap(const map<string, vector<string>>& m)
{
	for (const auto& item : m)
	{
		cout << "Bus "<< item.first<< ": ";
		PrintVector(item.second);
		cout << endl;
	}
	
}

int main()
{
	int q; 
	cin >> q;
	string operation_name;
	map<string, vector<string>> buses_and_stops;
	vector<string> bus_order;
	for (int i = 0; i < q; i++)
	{
		cin >> operation_name;
		if (operation_name == "NEW_BUS")
		{
			string bus;
			int stop_count;
			cin >> bus >> stop_count;
			
			bus_order.push_back(bus);
			vector<string> stops;
			for (int i = 0; i < stop_count; i++)
			{
				string temp;
				cin >> temp;
				stops.push_back(temp);
			}
			buses_and_stops[bus] = stops;
			//PrintMap(buses_and_stops);
			//PrintVector(bus_order);
		}
		else if (operation_name == "BUSES_FOR_STOP")
		{
			string stop; 
			cin >> stop;
			bool pr = false;
			for (const auto& item : buses_and_stops)
			{
				if (count(item.second.begin(), item.second.end(), stop) == 1)
				{
					pr = true;
					break;
				}
			}
			if(pr)
			{
				for (int j = 0; j < bus_order.size(); j++)
				{
					if (count(buses_and_stops[bus_order[j]].begin(), buses_and_stops[bus_order[j]].end(), stop) == 1)
					{
						cout << bus_order[j] << " ";
					}
				}
				cout << endl;
			}
			else
			{
				cout << "No stop" << endl;
			}
		}
		else if (operation_name == "STOPS_FOR_BUS")
		{
			string bus;
			cin >> bus;
			bool presence = false;
			if (buses_and_stops.count(bus) == 0 || buses_and_stops.size()==0)
			{
				cout << "No bus" << endl;
			}
			else
			{
				for (const auto& st : buses_and_stops[bus])
				{
					for (const auto& item : buses_and_stops)
					{
						if (count(item.second.begin(), item.second.end(), st) == 1 && item.first != bus)
						{
							presence = true;
							break;
						}
					}
					if (presence)
					{
						cout << "Stop " << st << ": ";
						for (int j = 0; j< bus_order.size(); j++)
						{
							if (count(buses_and_stops[bus_order[j]].begin(), buses_and_stops[bus_order[j]].end(), st) == 1 && bus_order[j] != bus)
							{
								cout << bus_order[j] << " ";
							}
						}
						cout << endl;
						presence = false;
					}
					else if (!presence)
					{
						cout << "Stop " << st << ": no interchange" << endl;
					}
				}
			}
		}
		else if (operation_name == "ALL_BUSES")
		{
			if (buses_and_stops.size() == 0)
			{
				cout << "No buses" << endl;
			}
			else
			{
				PrintMap(buses_and_stops);
			}
		}
	}
	return 0;
}
