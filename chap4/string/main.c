#include <stdio.h>

#include "string_matching.h"

int main() {
  char *s = "BBC ABCDAB ABCDABCDABDE";
  char *p = "ABCDABD";

  // int i = KMP_matching(s, p);
  // int i = BF_matching(s, p);
  int i = BM_matching(s, p);

  if (i >= 0) {
    printf("Matching position: %d\n", i);
  } else {
    printf("Mismatched\n");
  }
}
