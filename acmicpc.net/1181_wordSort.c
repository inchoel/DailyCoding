#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

bool compare_len(const string &a, const string &b)
{
  return a.length() < b.length();
}

int main ()
{
  list<string> words_list;
  list<string>::iterator it;
  int n;

  cin >> n;
  while (n > 0) {
    string word;
    cin >> word;
    for(it = words_list.begin(); it != words_list.end(); ++it) {
      if (*it == word)
        break;
    }

    if (it == words_list.end())
      words_list.push_back (word);

    --n;
  }

  words_list.sort(compare_len);
  
  for(it = words_list.begin(); it != words_list.end(); ++it)
  {
    cout << (*it) << endl;
  }

  return 0;
}

