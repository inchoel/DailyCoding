#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

int H;    // 세로 크기
int W;    // 가로 크기
int map[50][50];  //지도

struct ANS {
  int count;  // room 개수
  int area;   // 가장 넓은 room 넓이
};

void InputData() {
  int i, j;
  cin >> H;
  cin >> W;
  for(i=0 ; i<H ; i++) {
    for(j=0 ; j<W ; j++) {
      cin >> map[i][j];
    }
  }
}

void CalcArea (const int i, const int j, const int val, int& area) {
  queue<pair<pair<int, int>, int>> q;
  bitset<4> wall(val);
  map[i][j] = -1;
  // printf("wall=%s\n", wall.to_string().c_str());
  // printf("%s, %s, %s, %s\n",
  //     wall.test(0) ? "true" : "false",
  //     wall.test(1) ? "true" : "false",
  //     wall.test(2) ? "true" : "false",
  //     wall.test(3) ? "true" : "false" );

  if (wall.test(0) == false) { // 서
    if (j-1 >= 0 && map[i][j-1]!=-1) {
      q.push (make_pair(make_pair(i, j-1), map[i][j-1]));
      map[i][j-1] = -1;
    }
    // printf("W ");
  }

  if (wall.test(1) == false) { // 북
    if (i-1 >= 0 && map[i-1][j]!=-1) {
      q.push (make_pair(make_pair(i-1, j), map[i-1][j]));
      map[i-1][j] = -1;
    }
    // printf("N ");
  }

  if (wall.test(2) == false) { // 동
    if (j+1 < W && map[i][j+1]!=-1) {
      q.push (make_pair(make_pair(i, j+1), map[i][j+1]));
      map[i][j+1] = -1;
    }
    // printf("E ");
  }

  if (wall.test(3) == false) { // 남
    if (i+1 < H && map[i+1][j]!=-1) {
      q.push (make_pair(make_pair(i+1, j), map[i+1][j]));
      map[i+1][j] = -1;
    }
    // printf("S\n");
  }

  while (!q.empty()) {
    pair<pair<int, int>, int> pos = q.front();
    // printf("queue - pos(%d, %d)\n", pos.first, pos.second);
    q.pop();
    CalcArea (pos.first.first, pos.first.second, pos.second, area);
  }

  area++;
}

void Solve(ANS& ans) {
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (map[i][j] == -1)
        continue;

      int area = 0;
      CalcArea (i, j, map[i][j], area);
      ans.count++;
      if (ans.area < area)
        ans.area = area;;
    }
  }
}

int main() {
  ANS ans = {0, 0};

  InputData();      //  입력 함수

  Solve(ans);

  cout << ans.count << endl;  //  정답 출력
  cout << ans.area << endl;   //  정답 출력
  return 0;
}

