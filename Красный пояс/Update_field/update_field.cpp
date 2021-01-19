#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;

istream& operator>>(istream& is, Date& d)
{
    is >> d.year;
    if (is.peek() == '-') is.ignore(1);
    is >> d.month;
    if (is.peek() == '-') is.ignore(1);
    is >> d.day;
    return is;
}

istream& operator>>(istream& is, Time& t)
{
    is >> t.hours;
    if (is.peek() == ':') is.ignore(1);
    is >> t.minutes;
    return is;
}
bool operator< (const Date& lhs, const Date& rhs)
{
    return make_tuple(lhs.year, lhs.month, lhs.day) < make_tuple(rhs.year, rhs.month, rhs.day);
}

bool operator< (const Time& lhs, const Time& rhs)
{
    return make_tuple(lhs.hours, lhs.minutes) < make_tuple(rhs.hours, rhs.minutes);
}

bool operator== (const Date& lhs, const Date& rhs)
{
    return make_tuple(lhs.day, lhs.month, lhs.year) == make_tuple(rhs.day, rhs.month, rhs.year);
}

bool operator== (const Time& lhs, const Time& rhs)
{
    return make_tuple(lhs.minutes, lhs.hours) == make_tuple(rhs.minutes, rhs.hours);
}

ostream& operator<< (ostream& out, const Date& date)
{
    out << date.day << '.' << date.month << '.' << date.year << endl;
    return out;
}

ostream& operator<< (ostream& out, const Time& time)
{
    out << time.hours << ":" << time.minutes << endl;
    return out;
}
#define UPDATE_FIELD(ticket, field, values)     \
{                                               \
    auto it = values.begin();\
    it = values.find(#field);\
    if(it!=values.end()){\
        istringstream is(values.at(#field));\
        is >> ticket.field;\
    }\
}

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
