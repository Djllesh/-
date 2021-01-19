#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void add(map<string, set<string>>& m, string word1, string word2)
{
	m[word1].insert(word2);
	m[word2].insert(word1);
}

int main()
{
	int n;
	cin >> n;
	string operation_name;
	map<string, set<string>> syn_dict;
	
	for (int i = 0; i <n; i++)
	{
		cin >> operation_name;
		if (operation_name == "ADD")
		{
			string word1, word2;
			cin >> word1 >> word2;
			add(syn_dict, word1, word2);
		}
		else if(operation_name == "COUNT")
		{
			string word; 
			cin >> word;
			cout << syn_dict[word].size() << endl;
		}
		else if(operation_name == "CHECK")
		{
			string word1, word2; 
			cin >> word1 >> word2; 
			if (syn_dict[word1].count(word2) == 1)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}

	}
	
	return 0;
}
