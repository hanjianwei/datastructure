# 字符串解码

根据编码过的字符串，返回解码后的字符串。

编码规则是`k[encoded_string]`，其中`k`是1位的正整数，表示方括弧中字符串重复的次数。

比如：

~~~
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
~~~

要求：完成[main.c](./main.c)中标有`TODO`的函数，可以使用[stack](../stack)或者[queue](../queue).
