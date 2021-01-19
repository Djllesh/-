#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> FormNamesHistory(int year, map<int, string>& data)
{
    vector<string> result;
    int limit = data.begin()->first;
    for (int i = year; i >= limit; --i)
    {
        if (data.count(i))
            result.push_back(data[i]);
    }
    return result;
}

string FindName(const int year, const map<int, string>& data)
{
    string name;
    for (const auto& item : data)
    {
        if (item.first <= year)
            name = item.second;
        else
            break;
    }
    return name;
}

string GetHistoryNames(const vector<string>& data)
{
    string result;// = " (";
    string check = data[0];
    unsigned int limit = data.size() - 1;
    for (unsigned int i = 1; i < limit; ++i)
    {
        if (check != data[i])
        {
            result += data[i] + ", ";
            check = data[i];
        }
    }
    if (data[limit] != check)
        result += data[limit];
    if (!result.empty())
    {
        return " (" + result + ")";
    }
    //result += ")";
    return result;
}

int BirthYear(const map<int, string>& m) 
{
    int birth_year = m.begin()->first;
    return birth_year;
}

class Person {
public:
    Person(const string& name, const string& surn, int year)
    {
        firstName[year] = name;
        lastName[year] = surn;
    }
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        if (year >= BirthYear(firstName))
        {
            firstName[year] = first_name;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        if (year >= BirthYear(lastName))
        {
            lastName[year] = last_name;
        }
    }
    string GetFullName(int year) const {
        if (year >= BirthYear(firstName) || year >= BirthYear(lastName))
        {
            string name = FindName(year, firstName);
            string surname = FindName(year, lastName);
            if (!name.empty() && !surname.empty())
                return name + " " + surname;
            else if (!name.empty())
                return name + " with unknown last name";
            else if (!surname.empty())
                return surname + " with unknown first name";
            else return "Incognito";
        }
        else
        {
            return "No person";
        }
        // получить имя и фамилию по состоянию на конец года year
    }
    string GetFullNameWithHistory(int year) const {
        if (year >= BirthYear(firstName) || year >= BirthYear(lastName))
        {
            vector<string> names = FormNamesHistory(year, firstName);
            vector<string> surnames = FormNamesHistory(year, lastName);
            string result;
            if (!names.empty() && !surnames.empty())
            {
                result = names[0];
                if (names.size() > 1)
                {
                    result += GetHistoryNames(names);
                }
                result += (" " + surnames[0]);
                if (surnames.size() > 1)
                {
                    result += GetHistoryNames(surnames);
                }
                return result;
            }
            else if (!names.empty())
            {
                result = names[0];
                if (names.size() > 1)
                {
                    result += GetHistoryNames(names);
                }
                result += " with unknown last name";
            }
            else if (!surnames.empty())
            {
                result = surnames[0];
                if (surnames.size() > 1)
                {
                    result += GetHistoryNames(surnames);
                }
                result += " with unknown first name";
            }
            else result = "Incognito";
            return result;
        }
        else
        {
            return "No person";
        }
    }
private:
    map<int, string> firstName;
    map<int, string> lastName;
    // приватные поля
};



int main()
{
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
    
}