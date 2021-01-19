#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;
//эта функция - выполнение третьего пункта задания (упростить добавление новых абстракций в программу)
//так как пользователь может захотеть добавить другой "тип" людей, например пожарника, который тушит дом по определенному адресу
//чтобы использовать метод Act необходимо будет установить действия, которые умеет совершать человек

string SetAction(const string& type);

//говорят, что комментарии повышают читабельность кода 
//а еще исцеляют многие болезни
class Person
{
public:
    //пытаемся сохранить константность и при этом соблюсти культуру списков инициализации
    //здесь я инициализирую поле action в зависимости от уже известного мне "типа" людей
    Person(const string& _type, const string _name) : type(_type), name(_name), action(type == "Student" ? " sings a song: " : " teaches: ") {  }
    //ходят все, поэтому логичным решением будет унифицировать метод для всех "типов" людей
    virtual void Walk(const string& destination) const {
        cout << type << ": " << name << " walks to: " << destination << endl;
    }
    //студенты поют песню, а учителя преподают какой-то конкретный предмет, удобно будет вынести взаимодействие
    //с абстрактными предметами в отдельный метод в базовом классе, чтобы только давать команду действовать, а не прописывать такой похожий код 3 раза 
    virtual void Act(const string& object) const
    {
        cout << type << ": " << name << action << object << endl;
    }

    const string type, name, action;
};


class Student : public Person {
public:

    Student(string name, string favouriteSong) : Person("Student", name), FavouriteSong(favouriteSong) {}
    
    void Learn() const {
        cout << type << ": " << name << " learns" << endl;
    }

    void Walk(const string& destination) const override{
        cout << type << ": " << name << " walks to: " << destination << endl;
        Act(FavouriteSong);
    }

    void SingSong() const {
        Act(FavouriteSong);
    }

public:

    string FavouriteSong;
};

class Teacher : public Person{
public:
    //иметь отдельное поле Subject - подозрительно легкий путь к решению, 
    //но я на это смотрел как на ремесло, профессию, которую учитель обретает во время инициализации
    Teacher(string name, string subject) : Person("Teacher", name) 
    {
        Subject = subject;
    }

    void Teach() const {
        Act(Subject);
    }

public:
    string Subject;
};


class Policeman : public Person{
public:
    Policeman(string name) : Person("Policeman", name) {}
    void Check(shared_ptr<Person> p) const
    {
        string s = p->type;
        transform(s.begin(), s.end(), s.begin(), tolower);
        cout << type << ": " << name << " checks " << s << ". " << s << "'s name is " << p->name << endl;
    }
};

void VisitPlaces(shared_ptr<Person> p, vector<string> places)
{
    for (const auto& pl : places)
    {
        p->Walk(pl);
    }
}


int main() {
    auto t = make_shared<Teacher>(Teacher("Jim", "Math"));
    auto s = make_shared<Student>(Student ("Ann", "We will rock you"));
    auto p = make_shared<Policeman>(Policeman ("Bob"));

    VisitPlaces(t, { "Moscow", "London" });
    p->Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    t->Teach();
    s->Learn();
    p->Check(s);
    p->Check(p);
    return 0;
}
