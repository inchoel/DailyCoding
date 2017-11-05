#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int main()
{
  int n, a, b;
  scanf("%d", &n);

  vector<pair<int, int> > input;

  for (int i=0; i<n; i++) {
    scanf("%d %d", &a, &b);
    input.push_back(make_pair(a, b));
  }

  for (int i=0; i<n; i++) {
    printf("Case #%d: %d + %d = %d\n", i+1, input[i].first, input[i].second, input[i].first+input[i].second);
  }
  return 0;
}
