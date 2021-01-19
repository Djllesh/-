#include <map>
#include <iostream>
#include <string>
using namespace std;
bool isin(const map<string, string>& m, string word)
{
	for (const auto& item : m)
	{
		if (item.first == word)
		{
			return true;
		}
	}
	return false;
}

map<string, string> BuildReversedMap(const map<string, string>& m)
{
	map<string, string> result;
	for (auto item : m)
	{
		result[item.second] = item.first;
	}
	return result;
}

int main()
{
	int q;
	cin >> q;
	string operation_name;
	map<string, string> countries;
	for (int i = 0; i < q; i++)
	{
		cin >> operation_name;
		if (operation_name == "CHANGE_CAPITAL")
		{
			string country, new_capital;
			cin >> country >> new_capital;
			if (countries[country] != new_capital)
			{
				if (countries[country] == "")
				{
					cout << "Introduce new country " << country << " with capital " << new_capital << endl;
					countries[country] = new_capital;
				}
				else
				{
					cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << new_capital << endl;
					countries[country] = new_capital;
				}
			}
			else
			{
				cout << "Country " << country << " hasn't changed its capital" << endl;
			}
		}
		else if (operation_name == "RENAME")
		{
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			if(new_country_name == old_country_name || !isin(countries, old_country_name) || isin(countries, new_country_name))
			{
				cout << "Incorrect rename, skip" << endl;
			}
			else
			{
				cout << "Country " << old_country_name << " with capital " << countries[old_country_name] << " has been renamed to " << new_country_name << endl;
				string temp = countries[old_country_name];
				countries = BuildReversedMap(countries);
				countries[temp] = new_country_name;
				countries = BuildReversedMap(countries);
			}
		}
		else if (operation_name == "ABOUT")
		{
			string country;
			cin >> country;
			if (!isin(countries, country))
			{
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else
			{
				cout << "Country " << country << " has capital " << countries[country] << endl;
			}
		}
		else if (operation_name == "DUMP")
		{
			if (countries.size() == 0)
			{
				cout << "There are no countries in the world" << endl;
			}
			else
			{
				for (const auto& item : countries)
				{
					cout << item.first << "/" << item.second << endl;
				}
			}
		}
	}
	return 0;
}
