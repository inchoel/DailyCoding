#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void display_input(const vector<char>& v) {
   for(size_t i=0; i<v.size(); i++)
     cout << v[i];
   cout << endl;
}

inline bool comp(char a, char b) {
  return ((a > b)? true: false);
}

int main(void) {
  vector<char> input;
  char c = '\0';

  do {
    c = fgetc(stdin);
    if (c != '\n')
      input.push_back(c);
  } while (c != '\n');

  // display_input(input);
  sort(input.begin(), input.end(), comp);
  display_input(input);

  return 0;
}
