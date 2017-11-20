#include <cstdio>
#include <algorithm>
using namespace std;

void D (int& n) {
  n = n*2 % 10000;
}

void S (int& n) {
  if (--n == 0)
    n = 9999;
}

void L (int& n) {
}

void R (int& n) {
}

void getConvertCommand(const int a, const int b, vector<string>& ans) {
  // BFS
}

int main() {
  int T, a, b;
  vector<string> ans;

  scanf (" %d", &T);
  while (T--) {
    scanf (" %d %d", &a, &b);

    getConvertCommand(a, b, ans);
  }

  for (auto& e : ans)
    printf("%s\n", e.c_str());

  return 0;
}
