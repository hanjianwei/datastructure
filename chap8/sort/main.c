#include "sort.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int compare_ints(const void *a, const void *b) {
  int arg1 = *(const int *)a;
  int arg2 = *(const int *)b;

  if (arg1 < arg2) {
    return -1;
  }
  if (arg1 > arg2) {
    return 1;
  }
  return 0;
}

bool is_sorted(int *a, int n) {
  for (int i = 1; i < n; i++) {
    if (compare_ints(&a[i-1], &a[i]) > 0) {
      return false;
    }
  }

  return true;
}

void test_sort_algorithms() {
  int N = 100000;
  /* int N = 10000000; */
  int *data = malloc(sizeof(int) * N);
  int *initial = malloc(sizeof(int) * N);

  // Generate random data
  srand(time(NULL));
  for (int i = 0; i < N; ++i) {
    initial[i] = rand();
  }

  // qsort
  memcpy(data, initial, N * sizeof(int));
  clock_t t = clock();
  qsort(data, N, sizeof(int), compare_ints);
  printf("qsort: %.3f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);
  printf("\t%s sorted\n", is_sorted(data, N) ? "is" : "not");

  // insertion_sort
  memcpy(data, initial, N * sizeof(int));
  t = clock();
  insertion_sort(data, N, compare_ints);
  printf("insertion_sort: %.3f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);
  printf("\t%s sorted\n", is_sorted(data, N) ? "is" : "not");

  // shell_sort
  memcpy(data, initial, N * sizeof(int));
  t = clock();
  shell_sort(data, N, compare_ints);
  printf("shell_sort: %.3f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);
  printf("\t%s sorted\n", is_sorted(data, N) ? "is" : "not");

  // selection_sort
  memcpy(data, initial, N * sizeof(int));
  t = clock();
  selection_sort(data, N, compare_ints);
  printf("selection_sort: %.3f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);
  printf("\t%s sorted\n", is_sorted(data, N) ? "is" : "not");

  // heap_sort
  memcpy(data, initial, N * sizeof(int));
  t = clock();
  heap_sort(data, N, compare_ints);
  printf("heap_sort: %.3f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);
  printf("\t%s sorted\n", is_sorted(data, N) ? "is" : "not");

  // bubble_sort
  memcpy(data, initial, N * sizeof(int));
  t = clock();
  bubble_sort(data, N, compare_ints);
  printf("bubble_sort: %.3f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);
  printf("\t%s sorted\n", is_sorted(data, N) ? "is" : "not");

  // quick_sort
  memcpy(data, initial, N * sizeof(int));
  t = clock();
  quick_sort(data, N, compare_ints);
  printf("quick_sort: %.3f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);
  printf("\t%s sorted\n", is_sorted(data, N) ? "is" : "not");

  // merge_sort
  memcpy(data, initial, N * sizeof(int));
  t = clock();
  merge_sort(data, N, compare_ints);
  printf("merge_sort: %.3f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);
  printf("\t%s sorted\n", is_sorted(data, N) ? "is" : "not");

  // radix_sort
  memcpy(data, initial, N * sizeof(int));
  t = clock();
  radix_sort(data, N, compare_ints);
  printf("radix_sort: %.3f s\n", (double)(clock() - t) / CLOCKS_PER_SEC);
  printf("\t%s sorted\n", is_sorted(data, N) ? "is" : "not");

  free(data);
  free(initial);
}

int main() {
  test_sort_algorithms();
  return 0;
}
