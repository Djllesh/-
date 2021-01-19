#include "parse.h"

string_view Strip(string_view s){
  // ------DONE
  s.remove_prefix(min(s.find_first_not_of(' '), s.size()));
  s.remove_suffix(s.find_last_not_of(' ') == s.npos - 1 ? 0 : s.size() - s.find_last_not_of(' ') - 1);
  return s;
}

vector<string_view> SplitBy(string_view s, char sep) {
  vector<string_view> result;
  while (!s.empty()) {
    size_t pos = s.find(sep);
    result.push_back(s.substr(0, pos));
    s.remove_prefix(pos != s.npos ? pos + 1 : s.size());
  }
  return result;
}

