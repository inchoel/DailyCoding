
#if 0
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Score_ {
  char name[11];
  int k;
  int e;
  int m;
} Score;

bool comp (const Score& l, const Score& r) {
  if (l.k != r.k)
    return (l.k > r.k) ? true : false;

  if (l.e != r.e)
    return (l.e < r.e) ? true : false;

  if (l.m != r.m)
    return (l.m > r.m) ? true : false;

  string lName = l.name;
  string rName = r.name;
  transform(lName.begin(), lName.end(), lName.begin(), ::tolower);
  transform(rName.begin(), rName.end(), rName.begin(), ::tolower);
  size_t length = min(lName.size(),rName.size());
  for (size_t i=0; i<length; i++) {
    if ( lName[i] == rName[i] )
      continue;

    return (lName[i] < rName[i]) ? true : false;
  }

  return false;
}

int main()
{
  int n;
  scanf (" %d", &n);

  vector<Score> v;
  Score s;
  for (int i=0; i<n; i++) {
    scanf ("%s %d %d %d", s.name, &s.k, &s.e, &s.m);
    v.push_back(s);
  }

  sort (v.begin(), v.end(), comp);
  for (auto& s : v)
    printf("%s\n", s.name);
    // printf("%s %d %d %d\n", s.name, s.k, s.e, s.m);

  return 0;
}

#else
#include<iostream>
#include<algorithm>
#include<tuple>
#include<string>
using namespace std;
tuple<int, int, int, string> tp[100000];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> get<3>(tp[i]) >> get<0>(tp[i]) >> get<1>(tp[i]) >> get<2>(tp[i]),
        get<0>(tp[i]) *= -1, get<2>(tp[i]) *= -1;

  for (int i = 0; i<n; i++) {
    cout << get<3>(tp[i]) << " " << get<0>(tp[i]) << " " << get<1>(tp[i]) << " " << get<2>(tp[i]) << endl;
  }

  sort(tp, tp + n);
  for (int i = 0; i < n; i++) cout << get<3>(tp[i]) + '\n';
  return 0;
}
#endif
