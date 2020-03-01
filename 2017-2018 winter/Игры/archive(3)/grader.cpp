#include <stdio.h>

void move(int a[8][8], int c, int *x, int *y);

int main() {
  while (1) {
    int a[8][8];
    int c;
    int x, y;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    scanf("%d", &c);
    if (c == -1) {
      break;
    }
    move(a, c, &x, &y);
    printf("%d %d\n", x, y);
    fflush(stdout);
  }
  return 0;
}
