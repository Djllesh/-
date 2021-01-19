#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student {
public: 
    void append(const string& new_name, const string& new_last_name, int new_day, int new_month, int new_year)
    {
        name = new_name; 
        last_name = new_last_name;
        day = new_day; 
        month = new_month; 
        year = new_year; 
    }
    void PrintDate() const
    {
        cout << day << '.' << month << '.' << year << endl;
    }
    void PrintName() const
    {
        cout << name << ' ' << last_name << endl; 
    }
private:
    string name; 
    string last_name;
    int day;
    int month;
    int year;
};

int main() {
    int q, req; 
    cin >> q; 
    string name, last_name, operation;
    int day, month, year; 
    vector<Student> students; 
    for (int i = 0; i < q; i++)
    {
        Student new_student; 
        cin >> name >> last_name >> day >> month >> year; 
        new_student.append(name, last_name, day, month, year);
        students.push_back(new_student); 
    }
    cin >> req; 
    for (int i = 0; i < req; i++)
    {
        int index;
        cin >> operation >> index;
        if (operation == "name" && index <= students.size() && index > 0)
        {
            students[index -1].PrintName(); 
        }
        else if(operation == "date" && index <= students.size() && index > 0)
        {
            students[index - 1].PrintDate();
        }
        else
        {
            cout << "bad request" << endl;
        }
    }
    return 0;
}
