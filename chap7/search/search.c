#include "search.h"

#include <stdlib.h>

// TODO: DONE
// 使用comp对students进行排序
void sort(struct Vector *students, int (*comp)(const void *, const void *)) {
  qsort(students->buffer, students->size, sizeof(struct Student), comp);
}

// TODO: DONE
// 在students中查找stu，使用comp进行比较
// 返回查找元素的下标，如果找不到返回-1
int search(struct Vector *students, struct Student *stu,
           int (*comp)(const void *, const void *)) {
  for (int i = 0; i < students->size; ++i) {
    if (comp(students->buffer + i, stu) == 0) {
      return i;
    }
  }

  return -1;
}

// TODO: DONE
// 在students中用二分查找stu，使用comp进行比较
// 返回查找元素的下标，如果找不到返回-1
int bin_search(struct Vector *students, struct Student *stu,
               int (*comp)(const void *, const void *)) {
  /* struct Student *s = bsearch(stu, students->buffer, students->size, */
  /*                             sizeof(struct Student), comp); */
  /* return s == NULL ? -1 : s - students->buffer; */

  int lo = 0;
  int hi = students->size - 1;

  while (lo <= hi) {
    int m = (lo + hi) / 2;
    int c = comp(students->buffer + m, stu);

    if (c < 0) {
      lo = m + 1;
    } else if (c > 0) {
      hi = m - 1;
    } else {
      return m;
    }
  }

  return -1;
}
