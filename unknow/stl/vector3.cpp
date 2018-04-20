#include <iostream>
#include <vector>
using namespace std;

void print(int* arr, int size)
{
  for (int i=0; i<size; i++)
    cout << arr[i] << endl;
}

int main()
{
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  print(arr, 10);


  vector<int> v = {1,2,3,4,5,6,7,8,9,10};

  print(&v[0], v.size());
  print(v.data(), v.size());
}
