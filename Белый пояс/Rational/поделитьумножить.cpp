#include <iostream>

#include <sstream>



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

        Initialize(numerator, denominator);

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

    Rational operator * (const Rational& x)

    {

        Rational result;

        result.p = x.p * p;

        result.q = x.q * q;

        result.SignedFactional();

        result.p = result.Numerator();

        result.q = result.Denominator();

        return result;

    }



    Rational operator / (const Rational& x)

    {

        Rational result;

        result.p = x.q * p;

        result.q = x.p * q;

        result.SignedFactional();

        result.p = result.Numerator();

        result.q = result.Denominator();

        return result;

    }

    

private:

    int divider;

    int p;

    int q;

    // Добавьте поля

};
int main() {

   
}