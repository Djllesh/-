#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
using namespace std;
#include "profile.h"
class Learner {
private:
    set<string> dict;

public:
    int Learn(const vector<string>& words) {
        const size_t old_size = dict.size();
        for (const auto& word : words) {
            dict.insert(word);
        }
        return static_cast<int>(dict.size() - old_size);
    }

    vector<string> KnownWords() {
        vector<string> result(dict.size());
        size_t i = 0;
        for (const auto& word : dict)
        {
            result[i] = word;
            i++;
        }
        return result;
    }
};
