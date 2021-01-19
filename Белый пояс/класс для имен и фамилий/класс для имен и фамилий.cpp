#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Person
{
public:
    void ChangeFirstName(int year, const string& first_name)
    {
        firstName[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name)
    {
        lastName[year] = last_name;
    }
    string GetFullName(int year)
    {
        bool foundName = false;
        bool foundSurn = false;
        string name, surname;
        int limit = firstName.begin()->first;
        for (int i = year; i >= limit; --i)
        {
            if (firstName.count(i))
            {
                name = firstName[i];
                foundName = true;
                break;
            }
        }
        limit = lastName.begin()->first;
        for (int i = year; i >= limit; --i)
        {
            if (lastName.count(i))
            {
                surname = lastName[i];
                foundSurn = true;
                break;
            }
        }
        if (foundName && foundSurn)
        {
            return name + " " + surname;
        }
        else if (foundName)
        {
            return name + " with unknown last name";
        }
        else if (foundSurn)
        {
            return surname + " with unknown first name";
        }
        else return "Incognito";
    }
private:
    map<int, string> firstName;
    map<int, string> lastName;
};


int main()
{
    Person Kate; 
    Kate.ChangeFirstName(2002, "Kate");
    Kate.ChangeLastName(2004, "Troinikova");
    cout << Kate.GetFullName(2003);
	return 0;
}
