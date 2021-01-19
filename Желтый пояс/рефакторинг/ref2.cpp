#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <locale>
using namespace std;
string SetAction(const string& type)
{
    if (type == "Student") return " sings a song: ";
    else if (type == "Teacher") return " teaches: ";
    else return " checks ";
}
class Person
{
public:
    
    Person(const string& _type, const string _name) : type(_type), name(_name), action(SetAction(type)) {  }
  
    virtual void Walk(const string& destination) const {
        cout << type << ": " << name << " walks to: " << destination << endl;
    }
    
    virtual void Act(const string& object) const
    {
        cout << type << ": " << name << action << object;
    }

    const string type, name, action;
};


class Student : public Person {
public:

    Student(string name, string favouriteSong) : Person("Student", name), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << type << ": " << name << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        Person::Walk(destination);
        cout << type << ": " << name << " walks to: " << destination << endl;
        Act(FavouriteSong);
        cout << endl;
    }

    void SingSong() const {
        Act(FavouriteSong);
        cout << endl;
    }

public:

    const string FavouriteSong;
};

class Teacher : public Person {
public:
    
    Teacher(const string& name, const string& subject) : Person("Teacher", name), Subject(subject) {}

    void Teach() const {
        Act(Subject);
        cout << endl;
    }

public:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(string name) : Person("Policeman", name) {}
    void Check(Person p) const
    {
        //раньше тут был tolower но в некоторых компиляторах он жалуется
        Act(p.type);
        cout  << ". " << p.type << "'s name is " << p.name << endl;
    }
};

void VisitPlaces(Person p, vector<string> places)
{
    for (const auto& pl : places)
    {
        p.Walk(pl);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    t.Teach();
    s.Learn();
    p.Check(s);
    p.Check(p);
    return 0;
}
