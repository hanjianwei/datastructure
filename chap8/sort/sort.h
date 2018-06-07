#pragma once

// 插入排序
void insertion_sort(int *a, int n, int (*comp)(const void *, const void *));

// 希尔排序
void shell_sort(int *a, int n, int (*comp)(const void *, const void *));

// 选择排序
void selection_sort(int *a, int n, int (*comp)(const void *, const void *));

// 堆排序
void heap_sort(int *a, int n, int (*comp)(const void *, const void *));

// 冒泡排序
void bubble_sort(int *a, int n, int (*comp)(const void *, const void *));

// 快速排序
void quick_sort(int *a, int n, int (*comp)(const void *, const void *));

// 归并排序
void merge_sort(int *a, int n, int (*comp)(const void *, const void *));

// 基数排序
void radix_sort(int *a, int n, int (*comp)(const void *, const void *));
