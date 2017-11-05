#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int getInput(vector<string>& words) {
  int count = 0;
  string line;
  string token;

  getline(cin, line);
  stringstream ssCount(line);
  ssCount >> token;
  count = atoi(token.c_str());

  getline(cin, line);
  stringstream ss(line);
  for (int i = 0 ; i < count ; i++) {
    ss >> token;
    words.push_back(token);
  }

  return count;
}

void solve() {
  int count = 0;
  int total_len = 0;
  vector<string> words;

  count = getInput(words);

  sort (words.begin(), words.end());

  for (auto& e : words)
    printf("%s ", e.c_str());
  printf("\n");

  string s = words[0];
  for (size_t i=1; i<words.size(); i++) {
    if (i % 2)
      s = s + words[i];
    else
      s = words[i] + s;
  }

  printf("%s\n", s.c_str());
  printf("%c\n", s[s.size()/3]);
}

int main() {
  solve();
  return 0;
}
