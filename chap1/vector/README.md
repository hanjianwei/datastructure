# 向量Vector

1. 实现下面几个函数，并在`main`函数中写出对应的测试代码。

~~~ c
// 将vec中的元素反过来，比如原来是1、2、3，调用后变成3、2、1
void vector_reverse(struct vector *vec);

// 交换a和b两个向量的内容
void vector_swap(struct vector *a, struct vector *b);

// 将vec的内存缩小到恰好能存放所有元素
void vector_shrink_to_fit(struct vector *vec);

// 取出向量的第index个元素，允许index越界：如果vec有5个元素，index为-1返回倒数第一个，index为5返回第一个，即越界时从向量另一边开始数
int at(struct vector *vec, int index);
~~~

2. 如何让`vector`支持所有的数据类型？写出代码及相应的测试代码。

3. 如何合理处理各种错误，提出你自己的方案，用代码实现并写出相应的测试代码。
