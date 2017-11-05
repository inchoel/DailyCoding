#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main()
{
  int n, k;
  char cmd[10];
  queue<int> q;
  vector<int> v;

  scanf (" %d", &n);
  for (int i=0; i<n; i++) {
    scanf (" %s", cmd);
    switch (cmd[1]) {
      case 'u': // push
        scanf (" %d", &k);
        q.push(k);
        break;
      case 'o': // pop
        if (q.empty())
          v.push_back(-1);
        else {
          v.push_back(q.front());
          q.pop();
        }
        break;
      case 'i': // size
        v.push_back(q.size());
        break;
      case 'm': // empty
        v.push_back(q.empty());
        break;
      case 'r': // front
        if (q.empty())
          v.push_back(-1);
        else
          v.push_back(q.front());
        break;
      case 'a': // back
        if (q.empty())
          v.push_back(-1);
        else
          v.push_back(q.back());
        break;
    }
  }

  for (auto& e : v)
    printf("%d\n", e);

  return 0;
}
