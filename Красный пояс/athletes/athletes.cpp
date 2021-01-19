#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
	const int MAX_ATHLETES = 100'000;
	list<int> sportsmen;
	vector<list<int>::iterator> athlete_pos(MAX_ATHLETES + 1, sportsmen.end());
	int N, current, next;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> current >> next;
		athlete_pos[current] = sportsmen.insert(athlete_pos[next], current);
	}

	for (auto x : sportsmen)
	{
		cout << x << "\n";
	}
	return 0;
}