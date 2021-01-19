#include <iostream>
#include <sstream>
#include <iomanip>
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
    if (lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator())
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
// Вставьте сюда реализацию operator == для класса Rational из второй части
ostream& operator<<(ostream& stream, const Rational& r)
{
    return stream << r.Numerator() << '/' << r.Denominator();
}

//istream& operator>>(istream& stream, Rational& r)
//{ 
//    int p, q; 
//    char mid, slash = '/';
//    if (stream)
//    {
//        stream >> p;
//        if (stream)
//        {
//            stream >> mid; 
//            if (stream && mid == slash)
//            {
//                stream >> q; 
//                if (stream)
//                {
//                    r = Rational(p, q);
//                    return stream;
//                }
//                return stream;
//            }
//            return stream;
//        }
//       return stream;
//    }
//    return stream;  
//}
istream& operator>>(istream& stream, Rational& r)
{
    string ratio;
    int p = -1, q = -1, i;
    char slash = '/';
    if (stream)
    {
        stream >> ratio;

        if (stream)
        {
            i = ratio.find(slash);

            if (i > 0)
            {
                p = atoi(ratio.substr(0, i).c_str());
                q = atoi(ratio.substr(i + 1, ratio.length() - i - 1).c_str());

                if (p > 0 || q > 0)
                    r = Rational(p, q);
            }
        }

        return stream;
    }
    return stream;
}
// Реализуйте для класса Rational операторы << и >>

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }
    {
        Rational r = {5, 3};

        istringstream input("5/f6");
        
        input >> r; 
        cout << r;
    }
    {
        istringstream input("5/f 6/4");
        Rational r1, r2;
        input >> r1 >> r2;
        bool equal1 = r1 == Rational(0, 1);
        bool equal2 = r2 == Rational(3, 2);
        if (!equal1 || !equal2) {
            cout << "read:\n" << r1 << '\n' << r2;
            return 1;
        }
    }
    cout << "OK" << endl;
    return 0;
}
