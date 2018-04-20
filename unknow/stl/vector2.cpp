#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v(10, 0);

  v.resize(7);

  cout << v.size() << endl;
  cout << v.capacity() << endl;

  v.push_back(0);
  cout << v.size() << endl;
  cout << v.capacity() << endl;

  v.pop_back();
  cout << v.size() << endl;
  cout << v.capacity() << endl;

  v.shrink_to_fit();
  cout << v.size() << endl;
  cout << v.capacity() << endl;


  v.push_back(0);
  cout << v.size() << endl;
  cout << v.capacity() << endl;


  return 0;
}
