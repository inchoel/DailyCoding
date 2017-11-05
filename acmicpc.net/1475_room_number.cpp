#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  string room_number;
  cin >> room_number;

  int require_num_set = 0;
  vector<int> num_set(10, 0);
  for(size_t i=0; i<room_number.size(); i++) {
    int index = room_number[i] - '0';
    num_set[index]++;
    // cout << index << " : " << num_set[index] << endl;

    if (index!=6 && index!=9) {
      if (require_num_set < num_set[index])
        require_num_set = num_set[index];
    }
  }

  int temp = num_set[6] + num_set[9];
  int six_nine_num_set = temp/2 + temp%2;

  if (require_num_set < six_nine_num_set)
    require_num_set = six_nine_num_set;

  cout << require_num_set << endl;

  return 0;
}
