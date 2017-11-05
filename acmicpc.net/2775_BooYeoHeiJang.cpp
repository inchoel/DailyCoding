#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int tc, k, n;
  vector<int> resident, temp, result;

  cin >> tc;
  while (tc--) {
    cin >> k;
    cin >> n;

    for(int i=1; i<=n; i++) {
      resident.push_back(i);
    }

    for(int i=1; i<k; i++) {
      temp = resident;
      for(int j=0; j<n; j++) {
        int tmp = 0;
        for(int h=0; h<=j; h++) {
          tmp += temp[h];
        }
        resident[j] = tmp;
      }
    }

    int sum = 0;
    for(int i=0; i<n; i++)
      sum += resident[i];

    result.push_back(sum);

    resident.clear();
    temp.clear();
  }

  for(size_t i=0; i<result.size(); i++)
    cout << result[i] << endl;

  result.clear();

  return 0;
}
