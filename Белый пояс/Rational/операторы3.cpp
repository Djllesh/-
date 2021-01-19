#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        p = 0;
        q = 1;
        divider = 1;
    }
    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        if (numerator == 0)
        {
            p = numerator;
            q = 1;
        }
        else if (numerator < 0 && denominator < 0)
        {
            p = abs(numerator);
            q = abs(denominator);
        }
        else if (numerator < 0 || denominator < 0)
        {
            p = abs(numerator) * (-1);
            q = abs(denominator);
        }
        else
        {
            p = numerator;
            q = denominator;
        }
        divider = Divider();
    }
    void Initialize(const int& n, const int& d)
    {
        p = n;
        q = d;
        SignedFactional();
        p = Numerator();
        q = Denominator();
    }
    int GetP() const
    {
        return p;
    }
    int GetQ() const
    {
        return q;
    }
    void SignedFactional()
    {
        if (p == 0)
        {
            q = 1;
        }
        else if (p < 0 && q < 0)
        {
            p = abs(p);
            q = abs(q);
        }
        else if (p < 0 || q < 0)
        {
            p = abs(p) * (-1);
            q = abs(q);
        }
        divider = Divider();
    }
    int Divider() {
        if (p == q)
        {
            return p;
        }
        else if (p == 0 && q != 0)
        {
            return q;
        }
        else if (p != 0 && q == 0)
        {
            return p;   //bad case!
        }
        else
        {
            int dividend_t = 0;
            int divider_t = 0;
            int reminder = 0;
            if (p > q)
            {
                dividend_t = p;
                divider_t = q;
            }
            else
            {
                dividend_t = q;
                divider_t = p;
            }
            reminder = dividend_t % divider_t;
            while (reminder != 0)
            {
                dividend_t = divider_t;
                divider_t = reminder;
                reminder = dividend_t % divider_t;
            }
            return abs(divider_t);
        }

    }
    int Numerator() const {
        // Реализуйте этот метод
        return (p / divider);
    }
    int Denominator() const {
        // Реализуйте этот метод
        return (q / divider);
    }
private:
    int divider;
    int p;
    int q;
    // Добавьте поля
};

const bool operator==(const Rational& lhs, const Rational& rhs)
{
    if (lhs.GetQ() == rhs.GetQ() && lhs.GetP() == rhs.GetP())
    {
        return true;
    }
    else return false;
}
const bool operator!=(const Rational& lhs, const Rational& rhs)
{
    if (lhs.GetQ() != rhs.GetQ() && lhs.GetP() != rhs.GetP())
    {
        return true;
    }
    else return false;
}
const bool operator>(const Rational& lhs, const Rational& rhs)
{
    if (lhs.GetP() * rhs.GetQ() > lhs.GetQ() * rhs.GetP())
    {
        return true;
    }
    else return false;
}
const bool operator<(const Rational& lhs, const Rational& rhs)
{
    if (lhs.GetP() * rhs.GetQ() < lhs.GetQ() * rhs.GetP())
    {
        return true;
    }
    else return false;
}
// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

int main() {
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
