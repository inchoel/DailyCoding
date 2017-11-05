#include <iostream>
#include <vector>
using namespace std;

#define MAX_PROJECT (15) 
typedef struct {
  int start_date;
  int end_date;
}DATA;

int     N;
DATA    project_info[MAX_PROJECT];

void Data_Input(void) {
  cin >> N;
  for (int i = 0; i<N; i++) {
    cin >> project_info[i].start_date >> project_info[i].end_date;
  }
}

void Solve (int& sol) {
  vector<DATA> v;
  bool overlapped;

  for (int i=0; i<N-1; i++) {
    v.push_back(project_info[i]);
    for (int j=0; j<N; j++) {
      if (j == i)
        continue;

      overlapped = false;
      for (auto& d : v) {
        if (!(d.end_date < project_info[j].start_date
          || d.start_date > project_info[j].end_date)) {
          overlapped = true;
          break;
        }
      }
      if (overlapped == false)
        v.push_back(project_info[j]);
    }

    if (sol < v.size())
      sol = v.size();

    v.clear();
  }
}

int main(void) {
  int sol = 0;
  Data_Input();

  Solve(sol);
  cout << sol << endl;
  return 0;
}
