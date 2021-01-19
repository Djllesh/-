#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

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

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

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

bool IsPalindrom(string s) {
    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

void TestPalindromic()
{
    Assert(IsPalindrom("madam"), "Real palindrome error");
    Assert(IsPalindrom("seses"), "Real palindrome error");
    Assert(IsPalindrom("level"), "Real palindrome error");
    Assert(IsPalindrom("wasitacaroracatisaw"), "Real palindrome error");
    Assert(IsPalindrom(""), "Real palindrome error");
    Assert(IsPalindrom("a"), "Real palindrome error");
    Assert(IsPalindrom("1"), "Real palindrome error");
    Assert(!IsPalindrom("mada m"), "Not a palindrome");
    Assert(!IsPalindrom("m adam"), "Not a palindrome");
    Assert(!IsPalindrom("m a da m"), "Not a palindrome");
    Assert(!IsPalindrom("mada"), "Not a palindrome");
    Assert(!IsPalindrom("adam"), "Not a palindrome");
    Assert(!IsPalindrom("seabes"), "Not a palindrome");
    Assert(!IsPalindrom("aabaaa"), "Not a palindrome");
    Assert(!IsPalindrom("aaabaa"), "Not a palindrome");
    Assert(!IsPalindrom("wasitacaroracatisav"), "Not a palindrome");
    Assert(!IsPalindrom("Xasitacaroracatisaw"), "Not a palindrome");
    Assert(!IsPalindrom("wasitacaroracatisaW"), "Not a palindrome");
    Assert(!IsPalindrom("Wasitacaroracatisaw"), "Not a palindrome");
    Assert(IsPalindrom("            "), "Real palindrome error");
    Assert(!IsPalindrom("w asit acaror acat isaw"), "Not a palindrome");
    Assert(!IsPalindrom("wasitacaraoracatisaw"), "Not a palindrome");
    Assert(!IsPalindrom("Wasitacaaroracatisaw"), "Not a palindrome");
    Assert(!IsPalindrom("Wasitaacaroracatisaw"), "Not a palindrome");
    Assert(!IsPalindrom("Wasiatacaroracatisaw"), "Not a palindrome");
    Assert(!IsPalindrom("Wasaitacaroracatisaw"), "Not a palindrome");
    Assert(!IsPalindrom("Waasitacaroracatisaw"), "Not a palindrome");
}

int main() {
    TestRunner runner;
    runner.RunTest(TestPalindromic, "TestPalindromic");
    // добавьте сюда свои тесты
    return 0;
}
