#include <iostream>
#include <algorithm>
using namespace std;
#include "sum_reverse_sort.h"
int Sum(int x, int y)
{
    return x + y;
}

string Reverse(string s)
{
    string res = s;
    for (size_t i = 0; i <= s.size() - 1; i++)
    {
        res[i] = s[s.size() - i - 1];
    }
    return res;
}

void Sort(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
}

