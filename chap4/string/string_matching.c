#include "string_matching.h"
#include "string.h"
#include <stdio.h>

int BF_matching(char *s, char *pat) {
  int i, j;

  int M = strlen(s);
  int N = strlen(pat);

  for (i = 0; i < M - N; i++) {
    for (j = 0; j < N; j++) {
      if (pat[j] != s[i + j]) {
        break;
      }
    }

    if (j == N) {
      return i;
    }
  }

  return -1;
}

void compute_prefix(char *pat, int *prefix, int n) {
  prefix[0] = 0;

  for (int i = 1; i < n; i++) {
    int prev = prefix[i - 1];
    while (pat[i] != pat[prev] && prev > 0) {
      prev = prefix[prev - 1];
    }

    if (pat[i] == pat[prev]) {
      prev++;
    }
    prefix[i] = prev;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", prefix[i]);
  }
  printf("\n");
}

int KMP_matching(char *s, char *pat) {
  int s_len = strlen(s);
  int pat_len = strlen(pat);
  int prefix[pat_len];

  compute_prefix(pat, prefix, pat_len);

  int i = 0;
  int j = 0;
  while (i < s_len && j < pat_len) {
    if (s[i] == pat[j]) {
      i++;
      j++;
    } else if (j == 0) {
      i++;
    } else {
      j = prefix[j - 1];
    }
  }

  return j == pat_len ? (i - pat_len) : -1;
}

// TODO:
// 实现Boyer-Moore算法
int BM_matching(char *s, char* pat) {
  return -1;
}
