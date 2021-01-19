#include <iostream>
#include <exception>
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
        if (denominator == 0)
        {
            throw invalid_argument("denum is zero");
        }
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

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    if (lhs.Denominator() * rhs.Numerator() == 0)
    {
        throw domain_error("zero is below");
    }
    return Rational(lhs.Numerator()*rhs.Denominator(), rhs.Numerator()*rhs.Denominator());
}
// Вставьте сюда реализацию operator / для класса Rational

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    }
    catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    }
    catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
