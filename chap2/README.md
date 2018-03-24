# 第2章 线性表

## 第1次作业

在[vector](https://github.com/hanjianwei/datastructure/tree/e8193613dd5466ee75a47ea19ac992f8fa560e1d/chap2/vector)基础上，实现以下几个功能:

1. 实现下面几个函数，并在`main`函数中写出对应的测试代码。（[参考答案](https://github.com/hanjianwei/datastructure/tree/b195267f2a27ba1ac136df88ed6e93bd9dd6a951/chap2/vector/vector.c#L160-L198)）

~~~ c
// 将vec中的元素反过来，比如原来是1、2、3，调用后变成3、2、1
void vector_reverse(struct vector *vec);

// 交换a和b两个向量的内容
void vector_swap(struct vector *a, struct vector *b);

// 将vec的内存缩小到恰好能存放所有元素
void vector_shrink_to_fit(struct vector *vec);

// 取出向量的第index个元素，允许index越界：如果vec有5个元素，index为-1返回倒数第一个，index为5返回第一个，即越界时从向量另一边开始数
int vector_at(struct vector *vec, int index);
~~~

2. 如何让`vector`支持所有的数据类型？写出代码及相应的测试代码。([参考答案](https://github.com/hanjianwei/datastructure/tree/master/chap2/vector))

3. 如何合理处理各种错误，提出你自己的方案，用代码实现并写出相应的测试代码。([参考答案](https://github.com/hanjianwei/datastructure/tree/master/chap2/generic_vector))
