#include <iostream>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class RouteSystem
{
public:
    RouteSystem() = default;
    void AddRoute(const int a, const int b)
    {
        routes[a].insert(b);
        routes[b].insert(a);
    }
    int Go(int start, int finish)
    {
        int result = abs(start - finish);

        if (routes.count(start) < 1)
        {
            return result;
        }
        set<int>& possible_finishes = routes.at(start);
        const auto finish_pos = possible_finishes.lower_bound(finish);
        if (finish_pos != end(possible_finishes))
        {
            result = min(result, abs(finish - *finish_pos));
        }
        if (finish_pos != begin(possible_finishes))
        {
            result = min(result, abs(finish - *prev(finish_pos)));
        }
        return result;
    }

private:
    map<int, set<int>> routes;
};



int main()
{
    int q, start, finish;
    cin >> q;
    string command;
    RouteSystem rs;
    for (int i = 0; i < q; i++)
    {
        cin >> command >> start >> finish;
        if (command == "ADD")
        {
            rs.AddRoute(start, finish);
        }
        else if (command == "GO")
        {
            cout << rs.Go(start, finish) << '\n';
        }
    }
    return 0;
}