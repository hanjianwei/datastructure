#include "sort.h"

#define SWAP(x, y)                                                             \
  do {                                                                         \
    int tmp = x;                                                               \
    x = y;                                                                     \
    y = tmp;                                                                   \
  } while (0)

// TODO:
// 插入排序
void insertion_sort(int *a, int n, int (*comp)(const void *, const void *)) {}

// TODO:
// 希尔排序
void shell_sort(int *a, int n, int (*comp)(const void *, const void *)) {}

// TODO: DONE
// 选择排序
void selection_sort(int *a, int n, int (*comp)(const void *, const void *)) {
  for (int i = 0; i < n; i++) {
    int k = i;
    for (int j = i + 1; j < n; j++) {
      if (comp(&a[j], &a[k]) < 0) {
        k = j;
      }
    }
    if (k != i) {
      SWAP(a[i], a[k]);
    }
  }
}

// TODO:
// 堆排序
void heap_sort(int *a, int n, int (*comp)(const void *, const void *)) {}

// TODO:
// 冒泡排序
void bubble_sort(int *a, int n, int (*comp)(const void *, const void *)) {}

// TODO:
// 快速排序
void quick_sort(int *a, int n, int (*comp)(const void *, const void *)) {}

// TODO:
// 归并排序
void merge_sort(int *a, int n, int (*comp)(const void *, const void *)) {}

// TODO:
// 基数排序
void radix_sort(int *a, int n, int (*comp)(const void *, const void *)) {}
