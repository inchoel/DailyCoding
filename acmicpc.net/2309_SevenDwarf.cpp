#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

const static size_t LENGTH = 9;
const static size_t PICK = 7;
const static int HEIGHT_LIMIT = 100;
static bool findCase = false;
static array<bool, LENGTH> isVisit;

void selectDrawfs(const array<int, LENGTH>& input, array<int, PICK>& output)
{
  size_t k = 0;
  for (size_t j=0; j<LENGTH; ++j) {
    if (isVisit[j] == true) { output[k++] = input[j]; }
  }

  sort(output.begin(), output.end());
}

void displayCase(const array<int, PICK>& input)
{
  for (size_t j=0; j<PICK; ++j)
    cout << input[j] << endl;
}

bool isEqualWithLimit(const array<int, LENGTH>& input, const int limit)
{
  int sum = 0;

  for (size_t j=0; j<LENGTH; ++j)
    if (isVisit[j] == true) { sum += input[j]; }

  if (sum == limit)
    return true;
  else
    return false;
}

void findDrawfs(const array<int, LENGTH>& input)
{
  findCase = isEqualWithLimit(input, HEIGHT_LIMIT);
  if (findCase) {
    array<int, PICK> realDrawfs;
    selectDrawfs(input, realDrawfs);
    displayCase(realDrawfs);
  }
}

void combination(array<int, LENGTH>& input, size_t n, size_t r)
{
  if (findCase)
    return;

  if (n == r) {
    for (size_t i=0; i<n; ++i)
      isVisit[i] = true;

    findDrawfs(input);

    for (size_t k=0; k<n; ++k)
      isVisit[k] = false;

    return;
  }

  if (r == 1) {
    for (size_t i=0; i<n; ++i) {
      isVisit[i] = true;

      findDrawfs(input);

      isVisit[i] = false;
    }
    return;
  }

  isVisit[n-1] = true;
  combination(input, n-1, r-1);
  isVisit[n-1] = false;
  combination(input, n-1, r);
}

int main()
{
  array<int, LENGTH> drawfs;
  for(size_t i=0; i<LENGTH; ++i)
    cin >> drawfs[i];

  isVisit.fill(false);
  combination(drawfs, LENGTH, PICK);
  return 0;
}
