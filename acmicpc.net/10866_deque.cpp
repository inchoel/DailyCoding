#include <cstdio>
#include <deque>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, int> m = { {"push_front", 1},
                            {"push_back", 2},
                            {"pop_front", 3},
                            {"pop_back", 4},
                            {"size", 5},
                            {"empty", 6},
                            {"front", 7},
                            {"back", 8}
                          };
int main()
{
  int n;
  scanf("%d", &n);

  char cmd[20];
  deque<int> deq;
  vector<int> v;
  for (int i=0; i<n; i++) {
    scanf("%s", cmd);
    switch (m[string(cmd)]) {
      case 1:
        {
          int val;
          scanf("%d", &val);
          deq.push_front(val);
          break;
        }
      case 2:
        {
          int val;
          scanf("%d", &val);
          deq.push_back(val);
          break;
        }
      case 3:
        {
          int ret = -1;
          if (!deq.empty()) {
            ret = deq.front();
            deq.pop_front();
          }
          v.push_back(ret);
          break;
        }
      case 4:
        {
          int ret = -1;
          if (!deq.empty()) {
            ret = deq.back();
            deq.pop_back();
          }
          v.push_back(ret);
          break;
        }
      case 5:
        v.push_back(deq.size());
        break;
      case 6:
        {
          int ret = 0;
          if (deq.empty())
            ret = 1;
          v.push_back(ret);
          break;
        }
      case 7:
        {
          int ret = -1;
          if (!deq.empty())
            ret = deq.front();
          v.push_back(ret);
        } 
        break;
      case 8:
        {
          int ret = -1;
          if (!deq.empty())
            ret = deq.back();
          v.push_back(ret);
        }
        break;
    }
  }

  for (auto ret : v)
    printf("%d\n", ret);

  return 0;
}
