#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int FindMaxRepetitionCount(const vector<Region>& regions)
{
    int result = 0;
    map<Region, int> region_count;
    for (const Region& region : regions)
    {
        result = max(result, ++region_count[region]);
    }
    return result;
}

bool operator<(const Region& lhs, const Region& rhs)
{
    if (tie(lhs.names, lhs.parent_std_name, lhs.population, lhs.std_name)
        < tie(rhs.names, rhs.parent_std_name, rhs.population, rhs.std_name))
    {
        return true;
    }
    return false;
}