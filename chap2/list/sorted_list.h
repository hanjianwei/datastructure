#pragma once

#include "list.h"

// Merge sorted list src1 and src2 to dst
// src1和src2是从小到大排好序的链表，将它们所有节点移到dst中，并按照从小到大的顺序排列
enum Status merge_sorted_lists(struct List *dst, struct List *src1,
                               struct List *src2);

// Merge k lists
// srcs是n个从小到大排好序的链表，将它们所有节点移到dst中，并按照从小到大的顺序排列
enum Status merge_multiple_lists(struct List *dst, struct List **srcs, int n);
