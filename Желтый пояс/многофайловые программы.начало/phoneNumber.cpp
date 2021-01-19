#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
using namespace std;
#include "phone_number.h"
pair<int, int> FindMinusIndices(string s)
{
	vector<int> indices;
	char minus = '-';
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == minus)
		{
			if (indices.size() < 2)
			{
				indices.push_back(i);
			}
			else
			{
				break;
			}

		}
	}
	if (indices.size() < 2)
	{
		throw invalid_argument("Too few minuses");
	}
	pair<int, int> result = make_pair(indices[0], indices[1]);
	return result;
}
PhoneNumber::PhoneNumber(const string& international_number)
{
	int i = -1;
	i = international_number.find("+");
	if (i == 0)
	{
		pair<int, int> indices = FindMinusIndices(international_number);
		if (international_number.substr(indices.second, international_number.size() - 1 - indices.second).empty())
		{
			throw invalid_argument("No local number");
		}
		country_code_ = international_number.substr(1, indices.first - 1);
		city_code_ = international_number.substr(indices.first + 1, indices.second - indices.first - 1);
		local_number_ = international_number.substr(indices.second + 1, international_number.size() - 1 - indices.second);
	}
	else
	{
		throw invalid_argument("Does not start with +");
	}
}

string PhoneNumber::GetCountryCode() const
{
	return country_code_;
}
string PhoneNumber::GetCityCode() const
{
	return city_code_;
}
string PhoneNumber::GetLocalNumber() const
{
	return local_number_;
}
string PhoneNumber::GetInternationalNumber() const
{
	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}