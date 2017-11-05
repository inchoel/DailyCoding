#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GCD (const int a, const int b)
{
  if (b == 0)
    return a;

  return GCD (b, a%b);
}

int combination(const vector<int>& data, int n, int r, vector<bool>& selected, const size_t index)
{
  int sum = 0;
  if (n == r) {
    int sum = 0;
    int k = 0;
    array<int, 2> pair;

    for (size_t i=index; i<data.size(); i++) {
      selected[i] = true;
    }

    for (size_t j=0; j<data.size(); j++) {
      if (selected[j] == true)
        pair[k++] = data[j];
    }
    sum = GCD(max(pair[0], pair[1]), min(pair[0], pair[1]));

    for (size_t i=index; i<data.size(); i++) {
      selected[i] = false;
    }
    return sum;
  }

  if (r == 1) {
    int sum = 0;
    int k = 0;
    array<int, 2> pair;

    for (size_t i=index; i<data.size(); i++) {
      selected[i] = true;
      k = 0;

      for (size_t j=0; j<data.size(); j++) {
        if (selected[j] == true)
          pair[k++] = data[j];
      }
      selected[i] = false;
      sum += GCD(max(pair[0], pair[1]), min(pair[0], pair[1]));
    }
    return sum;
  }

  selected[index] = true;
  sum += combination(data, n-1, r-1, selected, index+1);
  selected[index] = false;
  sum += combination(data, n-1, r, selected, index+1);

  return sum;
}

int main() {
  size_t tc;
  cin >> tc;
  int sum;
  vector<int> GCDs;
  while (tc--) {
    sum = 0;
    size_t size;
    int in;
    cin >> size;
    vector<int> data;
    vector<bool> selected;
    for(size_t i=0; i<size; i++) {
      cin >> in;
      data.push_back(in);
      selected.push_back(false);
    }
    sum = combination(data, size, 2, selected, 0);
    GCDs.push_back(sum);
  }

  for (auto e: GCDs)
    cout << e << endl;
  return 0;
}

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int sum = 0;

int GCD (const int a, const int b)
{
  if (b == 0)
    return a;

  GCD (b, a%b);
}

void combination(const vector<int>& data, int n, int r, vector<bool>& selected, const size_t index)
{
  if (n == r) {
    for (size_t i=index; i<data.size(); i++) {
      selected[i] = true;
    }

    array<int, 2> pair;
    int k = 0;
    for (size_t j=0; j<data.size(); j++) {
      if (selected[j] == true)
        pair[k++] = data[j];
    }
    sum += GCD(max(pair[0], pair[1]), min(pair[0], pair[1]));

    for (size_t i=index; i<data.size(); i++) {
      selected[i] = false;
    }
    return;
  }

  if (r == 1) {
    for (size_t i=index; i<data.size(); i++) {
      selected[i] = true;

      array<int, 2> pair;
      int k = 0;
      for (size_t j=0; j<data.size(); j++) {
        if (selected[j] == true)
          pair[k++] = data[j];
      }
      selected[i] = false;
      sum += GCD(max(pair[0], pair[1]), min(pair[0], pair[1]));
    }
    return;
  }

  selected[index] = true;
  combination(data, n-1, r-1, selected, index+1);
  selected[index] = false;
  combination(data, n-1, r, selected, index+1);
}

int main() {
  size_t tc;
  cin >> tc;

  vector<int> GCDs;
  while (tc--) {
    sum = 0;

    size_t size;
    int in;
    cin >> size;
    vector<int> data;
    vector<bool> selected;
    for(size_t i=0; i<size; i++) {
      cin >> in;
      data.push_back(in);
      selected.push_back(false);
    }
    combination(data, size, 2, selected, 0);
    GCDs.push_back(sum);
    sum = 0;
  }

  for (auto e: GCDs)
    cout << e << endl;
  return 0;
}
#endif
