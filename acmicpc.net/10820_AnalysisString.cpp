#include <iostream>
#include <string>
using namespace std;

#define SAMPLE_MAX (100)

struct StringInfo
{
  int little;
  int big;
  int number;
  int space;

  void reset() {
    little = 0;
    big = 0;
    number = 0;
    space = 0;
  }
};

void analyzeString(const string s, struct StringInfo& info)
{
  info.reset();

  char target;
  for (size_t i=0; i<s.size(); i++) { 
    target = s[i];
    if (target >= 'a' && target <= 'z')
      info.little++;
    else if (target >= 'A' && target <= 'Z')
      info.big++;
    else if (target >= '0' && target <= '9')
      info.number++;
    else if (target == ' ')
      info.space++;
  }
}

int main()
{
  struct StringInfo info;
  string s;
  while (getline(cin, s)) {
    analyzeString(s, info);

    cout << info.little << " " \
         << info.big    << " " \
         << info.number << " " \
         << info.space  << endl;
  }

  return 0;
}
