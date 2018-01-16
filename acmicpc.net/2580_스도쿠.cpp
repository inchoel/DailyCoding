#include <cstdio>
#include <vector>
using namespace std;

void show_sdoku(int (*d)[9]) {
  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int sdoku[9][9];
  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      scanf(" %d", &sdoku[i][j]);
      if (sdoku[i][j] == 0) {
      }
    }

    if (empty_count == 1) {
    }
  }

  return 0;
}
