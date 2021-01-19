// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <exception>
#include <sstream>
using namespace std;
string comp_date;

string SearchForNumber(const string& s)
{
    string result;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            result += s[i];
        }
        else
        {
            break;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}
class Date {
public:
    Date()
    {
        year = 0;
        month = 0;
        day = 0;
    }
    Date(const int& new_year, const int& new_month, const int& new_day)
    {
        year = new_year;
        bool ismonth = new_month > 0 && new_month <= 12;
        bool isday = new_day > 0 && new_day <= 31;
        if (ismonth && isday)
        {
            month = new_month;
            day = new_day;
        }
        else
        {
            if (!ismonth)
            {
                throw runtime_error("Month value is invalid: " + to_string(new_month));
               // cout << "Month value is invalid: " + to_string(new_month) << endl;
            }
            else
            {
                throw runtime_error("Day value is invalid: " + to_string(new_day));
                //cout << "Day value is invalid: " + to_string(new_day) << endl;
            }
        }
    }
    int GetYear() const
    {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
private:
    int year; 
    int month;
    int day; 
};

int StreamValidityCheck(istream& is, string& s)
{
    char last_elem = s[s.size() - 1];
    char prev = s[s.size() - 2];
    if (is.peek() == '-')
    {
        int value; 
        is.ignore(1);
        if (is && (isdigit(is.peek()) || is.peek() == '+' || is.peek() == '-') && isdigit(last_elem))
        {
            is >> value; 
            if ((value == 0 && stoi(SearchForNumber(s)) == 0) || value != 0 )
            {
                return value;
            }
        }
    }
    stringstream errmsg;
    errmsg << "Wrong date format: " << s;
    throw runtime_error(errmsg.str());
}
bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() < rhs.GetYear())
    {
        return true;
    }
    else if (lhs.GetYear() > rhs.GetYear())
    {
        return false; 
    }
    else {
        if (lhs.GetMonth() < rhs.GetMonth())
        {
            return true;
        }
        else if (lhs.GetMonth() > rhs.GetMonth())
        {
            return false; 
        }
        else
        {
            if (lhs.GetDay() < rhs.GetDay())
            {
                return true;
            }
            return false;
        }
    }
}

ostream& operator<<(ostream& stream, const Date& date)
{
    stream << setw(4) << setfill('0') << date.GetYear() << '-' << setw(2) << date.GetMonth() << '-'<< setw(2) << date.GetDay();
    return stream;
}

istream& operator>>(istream& is, Date& date)
{
    int temp_year, temp_month, temp_day;
    is >> temp_year;
    temp_month = StreamValidityCheck(is, comp_date);
    temp_day = StreamValidityCheck(is, comp_date);
    date = Date(temp_year, temp_month, temp_day);
    return is;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        base[date].insert(event);
        set<string>::iterator it = base[date].end();
        it--;
        last_elem = *it;
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (base[date].count(event) != 0)
        {
            base[date].erase(event);
            return true;
        }
        return false;
    }
    int DeleteDate(const Date& date) {
        if (base.count(date) != 0)
        {
            int temp = base[date].size();
            base.erase(date);
            return temp;
        }
        return 0;
    }
    bool CheckTheDate(const Date& date) const
    {
        if (base.count(date) != 0) {
            return true;
        } return false;
    }
    set<string> Find(const Date& date) const {
        if (base.count(date) != 0)
        {
            return base.at(date);
        }
    }
    void Print() const
    {
        for (const auto& item : base)
        {
            for (const auto& ev : item.second)
            {
                cout << item.first << ' ' << ev << endl;
            }
        }
    }
private:
    map<Date, set<string>> base;
    string last_elem;
};

int main() {
    Database db;

    string command;
    try
    {
        while (getline(cin, command)) {
            if (!command.empty())
            {
                string request;
                stringstream stream(command);
                stream >> request;
                if (request == "Add")
                {
                    
                    Date new_date;
                    string temp;
                    stream >> temp;
                    comp_date = temp;
                    stringstream temp1(temp);
                    temp1 >> new_date;
                    string event;
                    stream >> event;
                    db.AddEvent(new_date, event);
                   
                }
                else if (request == "Del")
                {

                    Date del_date;
                    string event, temp;
                    stream >> temp;
                    comp_date = temp;
                    stringstream temp1(temp);
                    temp1 >> del_date;
                    stream >> event;
                    if (event.size() == 0)
                    {
                        int temp = db.DeleteDate(del_date);
                        cout << "Deleted " << temp << " events" << endl;
                    }
                    else
                    {
                        if (db.DeleteEvent(del_date, event))
                        {
                            cout << "Deleted successfully" << endl;
                        }
                        else
                        {
                            cout << "Event not found" << endl;
                        }
                    }
                }
                else if (request == "Find")
                {

                    Date new_date;
                    string temp;
                    stream >> temp;
                    comp_date = temp;
                    stringstream temp1(temp);
                    temp1 >> new_date;
                    if (db.CheckTheDate(new_date))
                    {
                        for (const auto& item : db.Find(new_date))
                        {
                            cout << item << endl;
                        }
                    }
                }
                else if (request == "Print")
                {
                    db.Print();
                }
                else
                {
                    stringstream errormsg;
                    errormsg << "Unknown command: " << request;
                    throw runtime_error(errormsg.str());
                }
            }
        }
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}