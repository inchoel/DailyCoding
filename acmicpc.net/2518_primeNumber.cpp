#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

void display_prime_number(vector<int>& p) {
  vector<int>::iterator it = p.begin();
  while (it != p.end()) {
    cout << (*it) << " ";
    it++;
  }
  cout << "\n";
}

void display_result(vector<int>& p) {
  int sum = 0;
  vector<int>::iterator it = p.begin();
  while (it != p.end()) {
    sum += (*it);
    it++;
  }
  cout << sum << endl;
  cout << p[0] << endl;
}

void find_prime_number(int s, int e, vector<int>& p) {
  bool is_prime;
  for(int i=s; i<=e; i++) {
    if (i==1) {
      continue;
    }
    else if (i==2) {
      p.push_back(i);
      continue;
    }
    is_prime = true;
    for(int j=2; j<i; ++j) {
      if ( i%j == 0 ) {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
      p.push_back(i);
  }
}

int main(void) {
  int m, n;

  cin >> m;
  cin >> n;

  if (m > n) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> pn;
  find_prime_number(m, n, pn);
  if (pn.empty()) {
    cout << -1 << endl;
    return 0;
  }
  display_result(pn);

  pn.clear();
  return 0;
}
