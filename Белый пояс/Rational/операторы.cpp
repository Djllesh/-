#include <iostream>



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

        p = numerator;

        q = denominator;

        SignedFactional();

        p = Numerator();

        q = Denominator();

    }



    void SignedFactional()

    {

        if(p == 0)

        {

            q = 1;

        }

        else if(p < 0 && q < 0)

        {

            p = abs(p);

            q = abs(q);

        }

        else if(p < 0 || q < 0)

        {

            p = abs(p) * (-1);

            q = abs(q);

        }

        divider = Divider();

    }



    int Divider() {

        if(p == q)

        {

            return p;

        }

        else if(p == 0 && q!= 0)

        {

            return q;

        }

        else if(p != 0 && q == 0)

        {

            return p;   //bad case!

        }

        else

        {

            int dividend_t = 0;

            int divider_t = 0;

            int reminder = 0;



            if(p > q)

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

            while(reminder != 0)

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



    const bool operator == (const Rational& a) const

    {

        if((a.p == p) && (a.q == q))

            return true;

        else return false;

    }



    Rational operator + (const Rational& x)

    {

        Rational result;

        if(x.q == q)

        {

            result.p = x.p + p;

            result.q = x.q;

        }

        else

        {

            result.p = (x.p * q) + (p * x.q);

            result.q = x.q * q;

        }

        result.SignedFactional();

//        cout << result.divider << endl;

        result.p = result.Numerator();

//        cout << result.p << endl;

        result.q = result.Denominator();

//        cout << result.q << endl;

        return result;

    }



    Rational operator - (const Rational& x)

    {

        Rational result;

        if(x.q == q)

        {

            result.p = p - x.p;

            result.q = x.q;

        }

        else

        {

            result.p = (p * x.q) - (x.p * q);

            result.q = x.q * q;

        }

        result.SignedFactional();

        //cout << result.divider << endl;

        result.p = result.Numerator();

        //cout << result.p << endl;

        result.q = result.Denominator();

        //cout << result.q << endl;

        return result;

    }





private:

    int divider;

    int p;

    int q;

    // Добавьте поля

};



int main() {

    {

        Rational r1(4, 6);

        Rational r2(2, 3);

        bool equal = r1 == r2;

        if (!equal) {

            cout << "4/6 != 2/3" << endl;

            return 1;

        }

    }



    {

        Rational a(2, 3);

        Rational b(4, 3);

        Rational c = a + b;

        bool equal = c == Rational(2, 1);

        if (!equal) {

            cout << "2/3 + 4/3 != 2" << endl;

            return 2;

        }

    }



    {

        Rational a(5, 7);

        Rational b(2, 9);

        Rational c = a - b;

        bool equal = c == Rational(31, 63);

        if (!equal) {

            cout << "5/7 - 2/9 != 31/63" << endl;

            //getchar();

            return 3;

        }

    }



    cout << "OK" << endl;

    getchar();

    return 0;

}