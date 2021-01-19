#include <iostream>
#include <exception>

using namespace std;

int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return GreatestCommonDivisor(b, a % b);
    }
}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }
    Rational(int new_numerator, int new_denominator) {
        if (new_denominator == 0) {
            // бросаем исключение в случае нулевого знаменателя
            throw invalid_argument("Invalid argument");
        }
        const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};
ostream& operator<<(ostream& stream, const Rational& r)
{
    return stream << r.Numerator() << '/' << r.Denominator();
}
Rational operator + (const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    // проверяем делитель на 0 (что равносильно проверке на 0 его числителя)
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}
 
int main()
{
    try {
        int p1, q1, p2, q2;
        char sl, op;
        cin >> p1 >> sl >> q1 >> op >> p2 >> sl >> q2;
        Rational fr_1 = { p1, q1 };
        Rational fr_2 = { p2, q2 };
        if (op == '+')
        {
            cout << fr_1 + fr_2;
        }
        if (op == '-')
        {
            cout << fr_1 - fr_2;
        }
        if (op == '*')
        {
            cout << fr_1 * fr_2;
        }
        if (op == '/')
        {
            cout << fr_1 / fr_2;
        }
    }
    catch (exception& ex)
    {
        cout << ex.what();
    }
    return 0;
}