#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int max_count_id;
vector<pair<int, int>> v;
vector<pair<int, int>> id;

void show(const vector<pair<int,int>>& v) {
  for (auto e : v)
    printf("%d %d\n", e.first, e.second);
}

bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
  return (a.first < b.first);
}

bool cmp2 (const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}

bool isFull() {
  bool ret = true;
  for (auto e : id) {
    if (e.second == 0) {
      ret = false;
      break;
    }
  }
  return ret;
}

void InputData() {
  scanf (" %d", &N);
  pair<int, int> d;
  for (int i=0; i<N; i++) {
    scanf(" %d %d", &d.first, &d.second);
    v.push_back(d);
  }
}

int main() {
  InputData();
 
  // sort id
  int pre = -1;
  sort(v.begin(), v.end(), cmp2);
  for (auto e : v) {
    if (pre != e.second) {
      id.push_back(make_pair(e.second, 0));
      pre = e.second;
    }
  }
  max_count_id = id.size();

  int wStart, wEnd;
  // sort position order
  sort(v.begin(), v.end(), cmp);
  for (int i=0; i<N; i++) {
    wStart = v[i].first;
    if (isFull()) {
      if (wEnd - wStart < min_length)
        min_length = wEnd-wStart;
    }
  }

  return 0;
}
