#include <iostream>
#include <stack>
using namespace std;

void transformNumber(const unsigned int n, const unsigned int m, stack<int>& transform)
{
  unsigned int num = n;

  while (num >= m) {
    transform.push(num%m);
    num = num / m;
  }
  if (num)
    transform.push(num);
}

void presentTransformed(stack<int>& s)
{
  int num;
  char ch;
  while (!s.empty()) {
    num = s.top();
    if (num >= 10) {
      ch = 'A' + (num - 10);
      cout << ch;
    }
    else
      cout << num;

    s.pop();
  }
  cout << endl;
}

int main() {
  unsigned int number, mode;
  stack<int> changed;

  cin >> number >> mode;

  transformNumber(number, mode, changed);
  presentTransformed(changed);
  return 0;
}
