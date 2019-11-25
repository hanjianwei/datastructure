#include "sort.h"

#define SWAP(x, y)                                                             \
  do {                                                                         \
    int tmp = x;                                                               \
    x = y;                                                                     \
    y = tmp;                                                                   \
  } while (0)

static void insertion_sort_gap(int *a, int n, int start, int gap,
                               int (*comp)(const void *, const void *)) {
  for (int i = start + gap; i < n; i += gap) {
    int j = i - gap;
    int x = a[i];

    while (j >= 0 && comp(&a[j], &x) > 0) {
      a[j + gap] = a[j];
      j -= gap;
    }
    a[j + gap] = x;
  }
}

// TODO: DONE
// 插入排序
void insertion_sort(int *a, int n, int (*comp)(const void *, const void *)) {
  for (int i = 1; i < n; i++) {
    int j = i - 1;
    int x = a[i];

    while (j >= 0 && comp(&a[j], &x) > 0) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = x;
  }
}

// TODO: DONE
// 希尔排序
void shell_sort(int *a, int n, int (*comp)(const void *, const void *)) {
  int gaps[] = {5, 3, 1};
  int ng = sizeof(gaps) / sizeof(int);

  for (int g = 0; g < ng; g++) {
    for (int i = 0; i < gaps[g]; i++) {
      insertion_sort_gap(a, n, i, g, comp);
    }
  }
}

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
void heapify(int a[], int n, int i, int (*comp)(const void *, const void *)) {
  int largest = i;   // Initialize largest as root
  int l = 2 * i + 1; // left = 2*i + 1
  int r = 2 * i + 2; // right = 2*i + 2

  // If left child is larger than root
  if (l < n && comp(&a[l], &a[largest]) > 0)
    largest = l;

  // If right child is larger than largest so far
  if (r < n && comp(&a[r], &a[largest]) > 0)
    largest = r;

  // If largest is not root
  if (largest != i) {
    SWAP(a[i], a[largest]);

    // Recursively heapify the affected sub-tree
    heapify(a, n, largest, comp);
  }
}

// TODO: DONE
// 堆排序
void heap_sort(int *a, int n, int (*comp)(const void *, const void *)) {
  // Build heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(a, n, i, comp);
  }

  // One by one extract an element from heap
  for (int i = n - 1; i >= 0; i--) {
    // Move current root to end
    SWAP(a[0], a[i]);

    // call max heapify on the reduced heap
    heapify(a, i, 0, comp);
  }
}

// TODO: DONE
// 冒泡排序
void bubble_sort(int *a, int n, int (*comp)(const void *, const void *)) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    // Last i elements are already in place
    for (j = 0; j < n - i - 1; j++) {
      if (comp(&a[j], &a[j + 1]) > 0) {
        SWAP(a[j], a[j + 1]);
      }
    }
  }
}

void quicksort(int *a, int low, int high,
               int (*comp)(const void *, const void *)) {
  int pivot, i, j;
  if (low < high) {
    pivot = low; // select a pivot element
    i = low;
    j = high;
    while (i < j) {
      // increment i till you get a number greater than the pivot element
      while (comp(&a[i], &a[pivot]) <= 0 && i <= high)
        i++;
      // decrement j till you get a number less than the pivot element
      while (comp(&a[j], &a[pivot]) > 0 && j >= low)
        j--;
      // if i < j swap the elements in locations i and j
      if (i < j) {
        SWAP(a[i], a[j]);
      }
    }

    // when i >= j it means the j-th position is the correct position
    // of the pivot element, hence swap the pivot element with the
    // element in the j-th position
    SWAP(a[j], a[pivot]);
    // Repeat quicksort for the two sub-arrays, one to the left of j
    // and one to the right of j
    quicksort(a, low, j - 1, comp);
    quicksort(a, j + 1, high, comp);
  }
}
// TODO: DONE
// 快速排序
void quick_sort(int *a, int n, int (*comp)(const void *, const void *)) {
  quicksort(a, 0, n - 1, comp);
}

// Merges two subarrays of a[].
// First subarray is a[l..m]
// Second subarray is a[m+1..r]
void merge(int a[], int l, int m, int r,
           int (*comp)(const void *, const void *)) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  /* create temp arrays */
  int L[n1], R[n2];

  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++)
    L[i] = a[l + i];
  for (j = 0; j < n2; j++)
    R[j] = a[m + 1 + j];

  /* Merge the temp arrays back into a[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray
  while (i < n1 && j < n2) {
    if (comp(&L[i], &R[j]) <= 0) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
    k++;
  }

  /* Copy the remaining elements of L[], if there
     are any */
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  /* Copy the remaining elements of R[], if there
     are any */
  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}

/* l is for left index and r is right index of the
   sub-array of a to be sorted */
void mergeSort(int a[], int l, int r, int (*comp)(const void *, const void *)) {
  if (l < r) {
    // Same as (l+r)/2, but avoids overflow for
    // large l and h
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(a, l, m, comp);
    mergeSort(a, m + 1, r, comp);

    merge(a, l, m, r, comp);
  }
}

// TODO: DONE
// 归并排序
void merge_sort(int *a, int n, int (*comp)(const void *, const void *)) {
  mergeSort(a, 0, n - 1, comp);
}

// A utility function to get maximum value in a[]
int getMax(int a[], int n, int (*comp)(const void *, const void *)) {
  int mx = a[0];
  for (int i = 1; i < n; i++) {
    if (comp(&a[i], &mx) > 0) {
      mx = a[i];
    }
  }

  return mx;
}

// A function to do counting sort of a[] according to
// the digit represented by exp.
void countSort(int a[], int n, int exp,
               int (*comp)(const void *, const void *)) {
  int output[n]; // output array
  int i, count[10] = {0};

  // Store count of occurrences in count[]
  for (i = 0; i < n; i++) {
    count[(a[i] / exp) % 10]++;
  }

  // Change count[i] so that count[i] now contains actual
  //  position of this digit in output[]
  for (i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  // Build the output array
  for (i = n - 1; i >= 0; i--) {
    output[count[(a[i] / exp) % 10] - 1] = a[i];
    count[(a[i] / exp) % 10]--;
  }

  // Copy the output array to a[], so that a[] now
  // contains sorted numbers according to current digit
  for (i = 0; i < n; i++) {
    a[i] = output[i];
  }
}

// TODO: DONE
// 基数排序
void radix_sort(int *a, int n, int (*comp)(const void *, const void *)) {
  // Find the maximum number to know number of digits
  int m = getMax(a, n, comp);

  // Do counting sort for every digit. Note that instead
  // of passing digit number, exp is passed. exp is 10^i
  // where i is current digit number
  for (int exp = 1; m / exp > 0; exp *= 10) {
    countSort(a, n, exp, comp);
  }
}
