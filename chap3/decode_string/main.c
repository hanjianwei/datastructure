#include <stdio.h>

// TODO:
void decode_string(char *s)
{
  
}

int main()
{
  decode_string("3[a]2[bc]");  // 输出 aaabcbc
  decode_string("3[a2[c]]");  // 输出 accaccacc
  decode_string("2[abc]3[cd]ef");  // 输出 abcabccdcdcdef
}
