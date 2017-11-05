#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

bool checkVPS(void)
{
// static int cnt = 1;
  bool valid = true;
  char input;
  char tmp;
  stack<char> st;
  map<char, char> pair = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

  while (cin.get(input) && input!='\n') {
    if (input=='(' || input=='{' || input=='[') {
      st.push(input);
    }
    else if (input==')' || input=='}' || input==']') {
      if (!st.empty() && pair[st.top()] == input) {
        st.pop();
      }
      else {
        valid = false;
        break;
      }
    }
    else {
      // cout << "else char : " << input << endl;
      continue;
    }
  }

  if (!st.empty()) {
    // cout << cnt << " not empty" << endl;
    valid = false;
  }
// cnt++;
  return valid;
}

int main(void)
{
  int n;
  char tmp;
  queue<string> output;

  cin >> n;
  cin.get(tmp);
  while (n > 0) {
    if (checkVPS())
      output.push("YES");
    else
      output.push("NO");
    n--;
  }
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  while (!output.empty()) {
    cout << output.front() << endl;
    output.pop();
  }
  return 0;
}
