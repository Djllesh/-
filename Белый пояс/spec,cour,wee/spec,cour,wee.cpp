#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct Specialization 
{
    string value; 
    explicit Specialization(string new_value)
    {
        value = new_value;
    }
};
struct Course
{
    string value; 
    explicit Course(string new_value)
    {
        value = new_value;
    }
};
struct Week
{
    string value; 
    explicit Week(string new_value) {
        value = new_value; 
    }
};
struct LectureTitle 
{
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization spec, Course cour, Week wee)
    {
        specialization = spec.value;
        course = cour.value;
        week = wee.value;
    }
};
int main()
{

    return 0;
}