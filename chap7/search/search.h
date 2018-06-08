#pragma once

#include "vector.h"

// 使用comp对students进行排序
void sort(struct Vector *students, int (*comp)(const void *, const void *));

// 在students中查找stu，使用comp进行比较
// 返回查找元素的下标，如果找不到返回-1
int search(struct Vector *students, struct Student *stu, int (*comp)(const void *, const void *));

// 在students中用二分查找stu，使用comp进行比较
// 返回查找元素的下标，如果找不到返回-1
int bin_search(struct Vector *students, struct Student *stu, int (*comp)(const void *, const void *));
