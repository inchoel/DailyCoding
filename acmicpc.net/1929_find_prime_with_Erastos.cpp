#include <iostream>
// #include <time.h>

using namespace std;

#define MAX_ARR_SIZE (1000000+1)


void initialize_array(int* n)
{
  for(size_t i=2; i<MAX_ARR_SIZE; i++)
    n[i] = i;
}

void show_prime_within_range(const int* n, const size_t s, const size_t e)
{
  for(size_t i=s; i<=e; i++) {
    if (n[i] != 0)
      cout << n[i] << endl;
  }
}

int main(void) {
  int start, end;
  cin >> start >> end;

  // clock_t t = clock();
  int num[MAX_ARR_SIZE];
  initialize_array(num);

  for(size_t i=2; i<MAX_ARR_SIZE; i++) {
    if (num[i] == 0)
      continue;

    for(size_t j=i+i; j<MAX_ARR_SIZE; j+=i) {
      num[j] = 0;
    }
  }

  show_prime_within_range(num, start, end);
  // t = clock() - t;
  // cout << "elapsed time = " << (float)t/CLOCKS_PER_SEC << endl;
  
  return 0;
}
