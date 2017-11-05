#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
using namespace std;

int N;              //  모델명의 개수
map<string, pair<string, int>> m;

bool comp (const pair<string, pair<string, int>>& a, const pair<string, pair<string, int>>& b) {
  bool ret = false;
  if (a.second.second > b.second.second)
    ret = true;
  else if (a.second.second == b.second.second) {
    if (a.second.first[0] < b.second.first[0])
      ret = true;
  }

  return ret;
}

void Solve() {
  vector<pair<string, pair<string, int>> > v;
  for (auto& e : m)
    v.push_back(make_pair(e.first, e.second));

  sort (v.begin(), v.end(), comp);
  // for (auto& ee : v)
  //   printf("%s : index=%s, count=%d\n", ee.first.c_str(), ee.second.first.c_str(), ee.second.second);

  if (v[0].second.second < 2) {
    printf("unique\n");
    return;
  }

  int count = 0;
  int half = (N/2) + (N%2);
  for (int i=0; i<N; i++) {
    if (v[i].second.second < 2)
      break;

    printf("%s %s\n", v[i].first.c_str(), v[i].second.first.c_str());
    count += v[i].second.second;
    if (count >= half)
      break;
  }
}

void InputData() {
  string str;  //  모델명 저장
  string order;
  int count;
  cin >> N;
  for(int i=0 ; i<N ; i++) {
    cin >> str;
    if (m.find(str) != m.end()) {
      order = m[str].first+ " " + to_string(i+1);
      count = m[str].second + 1;
    }
    else {
      order = to_string(i+1);
      count = 1;
    }

    m[str] = make_pair(order, count);
  }
}

int main(){

  InputData();    //  입력 함수

  Solve();        //  문제 풀이

  return 0;
}
  
