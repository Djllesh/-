#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class ReversibleString 
{
public:
    ReversibleString(){}
    ReversibleString(const string& some_string) { our_string = some_string; }
    void Reverse()
    {
        int len = our_string.length();
        int n = len - 1;
        for (int i = 0; i < (len / 2); i++) {
            //Using the swap method to switch values at each index
            swap(our_string[i], our_string[n]);
            n = n - 1;
        }
    }
    string ToString() const 
    {
        return our_string;
    }
private:
    string our_string;
};
