#include <stdio.h>

void print_num(int n, int base);

int main() {
  int n, base;

  scanf("%d%d", &n, &base);
  print_num(n, base);
}

void print_num(int n, int base) {
  if (n < base) {
    printf("%d", n);
  } else {
    print_num(n / base, base);
    printf("%d", n % base);
  }
}
