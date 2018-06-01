#pragma once

#include "vector.h"

// 比较函数
typedef int StudentComp(struct Student *, struct Student *);

// 使用comp对students进行排序
void sort(struct Vector *students, StudentComp comp);

// 在students中查找stu，使用comp进行比较
// 返回查找元素的下标，如果找不到返回-1
int search(struct Vector *students, struct Student *stu, StudentComp comp);

// 在students中用二分查找stu，使用comp进行比较
// 返回查找元素的下标，如果找不到返回-1
int bin_search(struct Vector *students, struct Student *stu, StudentComp comp);
