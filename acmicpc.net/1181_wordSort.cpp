#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void display_words(const vector<string>& v) {
  for(size_t i=0; i<v.size(); i++)
    cout << v[i] << endl;
}

void display_words_with_no_duplicate(const vector<string>& v) {
  size_t size = v.size();
  for(size_t i=0; i<size; i++) {
    cout << v[i] << endl;
    while (i+1 < size && v[i] == v[i+1]) {
      i++;
    }
  }
}

inline bool comp(string a, string b) {
  return (a.size()<b.size()?true:false);
}

bool comp2(string a, string b) {
  for(size_t i=0; i<a.size(); i++) {
    if (a[i] == b[i])
      continue;
    else if (a[i] > b[i])
      return false;
    else
      return true;
  }
  return true;
}

void sort_words(const vector<string>& input, vector<string>& output) {
  vector<string> temp;
  size_t size, j;
  size = input.size();
  for(size_t i=0; i<size; i++) {
    j = i;
    do {
      temp.push_back(input[j]);
      j++;
    } while (j < size && input[i].size() == input[j].size());
    i = j - 1;
    if (temp.size() > 1)
      sort(temp.begin(), temp.end(), comp2);
    for(size_t k=0; k<temp.size(); k++)
      output.push_back(temp[k]);
    temp.clear();
  }
}

int main(void) {
  int tc;
  cin >> tc;

  vector<string> words, sorted_words;
  string temp;
  while (tc != 0) {
    cin >> temp;
    words.push_back(temp);
    tc--;
  }

  sort(words.begin(), words.end(), comp);
  // display_words(words);
  sort_words(words, sorted_words);
  display_words_with_no_duplicate(sorted_words);

  return 0;
}
