#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"
#include "btree_vis.h"
#include "huffman.h"

int main() {
  char *s = "go go gophers";
  char *t = "her sphere goes here";
  char *es = "0001100000110000011110110110111111100";

  struct BTree *h1 = huffman_build_using_array(s);
  struct BTree *h2 = huffman_build_using_heap(s);

  printf("h1 %c= h2\n", btree_is_isomorphic(h1, h2) ? '~' : '^');

  int n1 = huffman_encode(h1, s);
  int n2 = huffman_encode(h2, s);
  printf("n1 %c= n2\n", n1 == n2 ? '=' : '!');

  n1 = huffman_encode(h1, t);
  n2 = huffman_encode(h2, t);
  printf("n1 %c= n2\n", n1 == n2 ? '=' : '!');

  n1 = huffman_decode(h1, es);
  n2 = huffman_decode(h2, es);
  printf("n1 %c= n2\n", n1 == n2 ? '=' : '!');

  btree_destroy(h1);
  btree_destroy(h2);
}
