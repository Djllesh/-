#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return GreatestCommonDivisor(b, a % b);
    }
}

//class Rational {
//public:
//    Rational() {  // дробь по умолчанию — 0/1
//        numerator = 0;
//        denominator = 1;
//    }
//    Rational(int new_numerator, int new_denominator) {
//        const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
//        // сократим дробь, разделив числитель и знаменатель на их НОД
//        numerator = new_numerator / gcd;
//        denominator = new_denominator / gcd;
//        // знаменатель должен быть положительным
//        if (denominator < 0) {
//            denominator = -denominator;
//            numerator = -numerator;
//        }
//    }
//
//    int Numerator() const {
//        return numerator;
//    }
//
//    int Denominator() const {
//        return denominator;
//    }
//
//private:
//    int numerator;
//    int denominator;
//};
bool operator == (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
        lhs.Denominator() == rhs.Denominator();
}
bool operator != (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() != rhs.Numerator() ||
        lhs.Denominator() != rhs.Denominator();
}
ostream& operator << (ostream& os, const Rational& r) {
    return os << r.Numerator() << '/' << r.Denominator();
}
template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

//void Assert(bool b, const string& hint) {
//    AssertEqual(b, true, hint);
//}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};


void TestNegative()
{
    Rational denom_neg = { 1, -2 };
    Rational comp = { -1, 2 };
    Rational both_neg = { -1, -2 };
    Rational comp2 = { 1, 2 };
    Rational empty;
    Rational forced_empty = { 0, 1 };
    Rational zero = { 0 , 124124 };
    Rational neg_zero = { 0 , -124124 };
    AssertEqual(denom_neg, comp);
    AssertEqual(both_neg, comp2);
    AssertEqual(empty, forced_empty);
    AssertEqual(empty, zero);
    AssertEqual(empty, neg_zero);
}
void TestDivision()
{
    Rational r1 = { 6, 4 }, r2 = { 3, 2 };
    Rational r3 = { 10, 5 }, r4 = { 2, 1 };
    Rational r5 = { 2, -4 }, r6 = { -1, 2 };
    Rational r7 = { -3, -9 }, r8 = { 1, 3 };
    Rational r9 = { -15, 3 }, r10 = { 5, -1 };
    AssertEqual(r1, r2);
    AssertEqual(r3, r4);
    AssertEqual(r5, r6);
    AssertEqual(r7, r8);
    AssertEqual(r9, r10);

}
int main() {
    TestRunner runner;
    runner.RunTest(TestNegative, "TestNegative");
    runner.RunTest(TestDivision, "TestDivision");
    // добавьте сюда свои тесты
    return 0;
}
