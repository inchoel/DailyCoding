#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string a, const string b)
{
  size_t size = (a.size() < b.size() ?  a.size() : b.size());

  for(size_t i=0; i<size; i++) {
    if (a[i] < b[i])
      return true;
    else if (a[i] > b[i])
      return false;
  }

  if (a.size() < b.size())
    return true;
  else
    return false;
}

int main()
{
  string input;
  cin >> input;
  size_t inputSize = input.size();

  vector<string> subfix;
  for(size_t i=0; i<inputSize; i++) {
    subfix.push_back(input.substr(i, inputSize));
  }

  sort(subfix.begin(), subfix.end(), compare);
  for (auto e: subfix)
    cout << e << endl;

  return 0;
}
