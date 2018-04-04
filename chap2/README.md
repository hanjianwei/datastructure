# 第2章 线性表

## 课件

[下载](https://github.com/hanjianwei/datastructure/raw/master/chap2/chap2.ppt)

## 代码

- [向量vector](./vector)
- [支持泛型的向量generic_vector](./generic_vector)
- [单链表list](./list)
- [双向链表dlist](./dlist)
- [循环链表 clist](./clist)

## 第1次作业

在[vector](https://github.com/hanjianwei/datastructure/tree/e8193613dd5466ee75a47ea19ac992f8fa560e1d/chap2/vector)基础上，实现以下几个功能:

1. 实现下面几个函数，并在`main`函数中写出对应的测试代码。（[参考答案](https://github.com/hanjianwei/datastructure/tree/master/chap2/vector/vector.c#L139-L163)）

~~~ c
// 将vec中的元素反过来，比如原来是1、2、3，调用后变成3、2、1
void vector_reverse(struct Vector *vec);

// 交换a和b两个向量的内容
void vector_swap(struct Vector *a, struct vector *b);

// 将vec的内存缩小到恰好能存放所有元素
void vector_shrink_to_fit(struct Vector *vec);

// 取出向量的第index个元素，允许index越界：如果vec有5个元素，index为-1返回倒数第一个，index为5返回第一个，即越界时从向量另一边开始数
int vector_at(struct Vector *vec, int index);
~~~

2. 如何合理处理各种错误，提出你自己的方案，用代码实现并写出相应的测试代码。([参考答案](https://github.com/hanjianwei/datastructure/tree/master/chap2/vector))

3. 如何让`vector`支持所有的数据类型？写出代码及相应的测试代码。([参考答案](https://github.com/hanjianwei/datastructure/tree/master/chap2/generic_vector))

## 第2次作业

1. 阅读单链表实现的代码[list](./list/)，完成下面两个函数（参见[sorted_list.h](./list/sorted_list.h)、[sorted_list.c](./list/sorted_list.c)，并完成标有`TODO`的函数).([参考答案](./list/sorted_list.c))
~~~ c
// Merge sorted list src1 and src2 to dst
// src1和src2是从小到大排好序的链表，将它们所有节点移到dst中，并按照从小到大的顺序排列
enum Status merge_sorted_lists(struct List *dst, struct List *src1,
                               struct List *src2);

// Merge k lists
// srcs是n个从小到大排好序的链表，将它们所有节点移到dst中，并按照从小到大的顺序排列
enum Status merge_multiple_lists(struct List *dst, struct List **srcs, int n);
~~~
2. 参考单链表[list](./list/)的实现，分别完成双向链表[dlist](./dlist)、循环链表[clist](./clist)，分别实现其中标`TODO`的函数，使得两个程序能够正确运行。(参考答案见相关文件)
