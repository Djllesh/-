#include <map>
#include <iostream>
#include <string>
using namespace std;
void BuildCharCounters(const string& word1, const string& word2)
{
	map<char, int> counter1, counter2;
	for (int i = 0; i < word1.size(); i++)
	{
		++counter1[word1[i]];
	}
	for (int i = 0; i < word2.size(); i++)
	{
		++counter2[word2[i]];
	}
	if (counter1 == counter2)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO"<< endl;
	}
}

int main()
{
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		string word1, word2; 
		cin >> word1 >> word2;
		BuildCharCounters(word1, word2);
			
	}
	return 0;
}
