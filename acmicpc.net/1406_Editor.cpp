#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

int main()
{
  list<char> l;
  char c;

  while ( (c = getchar()) && (c != '\n') ) {
    l.push_back(c);
  }

  auto cursor = l.end();
  int n;
  char cmd[5];
  scanf("%d", &n);
  while (getchar() != '\n');

  for (int i=0; i<n; i++) {
    scanf("%[^\n]s", cmd);
    while (getchar() != '\n');
    switch (cmd[0]) {
      case 'L':
        if (!l.empty() && cursor != l.begin())
          cursor--;
        break;

      case 'D':
        if (!l.empty() && cursor != l.end())
          cursor++;
        break;

      case 'B':
        if (!l.empty() && cursor != l.begin())
          cursor = l.erase(--cursor);
        break;

      case 'P':
        if (l.empty()) {
          l.push_back(cmd[2]);
          cursor = l.end();
        }
        else
          l.insert(cursor, cmd[2]);
        break;
    }
  }

  for (auto& e : l)
    printf("%c", e);
  printf("\n");

  return 0;
}
