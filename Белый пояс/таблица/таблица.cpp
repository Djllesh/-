#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");
    int N = 0, M = 0;
    string value;
    input >> N;
    input >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M - 1; j++)
        {
            getline(input, value, ',');
            cout << right << setw(10) << stoi(value) << ' ';
           
        }
        input >> value;
        cout << right << setw(10);
        cout << stoi(value) << endl;
    }
    return 0;
}

