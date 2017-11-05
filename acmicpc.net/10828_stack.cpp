#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
  string cmd;
  int n = 0;
  int x = 0;
  map<string, int> menu = {{"push", 1}, {"pop", 2}, {"size", 3},
                           {"empty", 4}, {"top", 5}};
  stack<int> st;
  queue<int> output;

  cin >> n;
  map<string, int>::iterator it;
  while (n > 0) {
    cin >> cmd;
    it = menu.find(cmd);
    switch (it->second) {
      case 1:
        cin >> x;
        st.push(x);
        break;
      case 2:
        if (st.empty())
          output.push(-1);
        else {
          output.push(st.top());
          st.pop();
        }
        break;
      case 3:
        output.push(st.size());
        break;
      case 4:
        if (st.empty())
          output.push(1);
        else
          output.push(0);
        break;
      case 5:
        if (st.empty())
          output.push(-1);
        else
          output.push(st.top());
        break;
    }
    n--;
  }

  while (!output.empty()) {
    cout << output.front() << endl;
    output.pop();
  }
  return 0;
}
