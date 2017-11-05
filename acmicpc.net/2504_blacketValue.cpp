#include <iostream>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
  int i=0, j=0, output=0, temp=0;
  char input;
  stack<pair<char, int>> st;

  while (cin.get(input) && input!='\n')
  {
    if (input=='(' || input=='[')
    {
      st.push(make_pair(input, 0));
    }
    else
    {
      if (input==')')
      {
        while (st.top().first!='(')
        {
          temp += st.top().second;
          st.pop();
        }
        st.pop();
        if (temp)
          temp *= 2;
        else
          temp = 2;

        st.push(make_pair('n', temp));
      }
      else
      {
        while (st.top().first!='[')
        {
          temp += st.top().second;
          st.pop();
        }
        st.pop();
        if (temp)
          temp *= 3;
        else
          temp = 3;

        st.push(make_pair('n', temp));
      }
      temp = 0;
    }
  }

  while (!st.empty() && st.top().first=='n')
  {
    output += st.top().second;
    st.pop();
  }

  if (!st.empty())
    output = 0;

  cout << output << endl;
  return 0;
}
