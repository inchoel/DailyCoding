#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void permutationCombi(const int n, stack<int>& sum, int& count)
{
  int s = (sum.empty()) ? 0: sum.top();

  if (n < s) {
    return;
  }
  else if (n == s) {
    count++;
    return;
  }

  for(int i=1; i<=3; i++) {
    sum.push(s+i);
    permutationCombi(n, sum, count);
    sum.pop();
  }
}

int main() {
  int tc;
  cin >> tc;

  int n, count;
  stack<int> sum;
  vector<int> result;
  for(int i=0; i<tc; i++) {
    count = 0;
    cin >> n;
    permutationCombi(n, sum, count);
    result.push_back(count);
  }

  for (auto e: result)
    cout << e << endl;

  return 0;
}
