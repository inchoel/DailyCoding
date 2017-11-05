#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


int main() {
  vector<pair<int, int> > positions;
  int n, x, y;

  cin >> n;
  while (n--) {
    cin >> x >> y;
    positions.push_back(make_pair(x,y));
  }

  sort(positions.begin(), positions.end());

  for (auto e: positions)
    cout << e.first << " " << e.second << endl;
  return 0;
}


#if 0
typedef struct Position_ {
  int x;
  int y;
} Position;

bool comp(Position a, Position b)
{
  if (a.x < b.x)
    return true;

  if (a.x == b.x) {
    if (a.y < b.y)
      return true;
  }

  return false;
}

int main() {
  vector<Position> pos;  // 시간초과
  Position temp;
  int n;
  cin >> n;

  while (n--) {
    cin >> temp.x >> temp.y;
    pos.push_back(temp);
  }

  sort(pos.begin(), pos.end(), comp);

  for (auto e: pos)
    cout << e.x << " " << e.y << endl;

  return 0;
}
#endif
