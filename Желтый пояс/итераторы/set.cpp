#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border)
{
    auto border_it = find_if(elements.begin(), elements.end(),
        [border](T element) {return element > border; });
    vector<T> result;
    for (auto it = border_it; it != elements.end();)
    {
        result.push_back(*(it++));
    }
    return result;
}