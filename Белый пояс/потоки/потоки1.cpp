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
    if (input) {
        while (getline(input, line))
        {
            cout << line << endl; 
        }
      //  cout << endl; 
    }
    return 0;
}
