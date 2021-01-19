#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input("input.txt");
    string line;

    ofstream output("output.txt");
    if (input) {
        while (getline(input, line))
        {
            output << line << endl; 
        }
        cout << endl; 
    }
    return 0;
}
