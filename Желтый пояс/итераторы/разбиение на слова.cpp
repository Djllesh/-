#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<string> SplitIntoWords(const string& s)
{
    vector<string> result;
    const char space = ' ';
    auto it = s.begin();
    auto it2 = s.begin();
    while (true)
    {
        it2 = find(it, s.end(), space);
        result.push_back(string(it, it2));
        if (it2 != s.end())
        {
            it = ++it2;
        }
        else
        {
            break;
        }
        
    }
    return result;
}