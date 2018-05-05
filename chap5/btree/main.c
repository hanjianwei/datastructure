#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"
#include "btree_vis.h"

int main() {
  char *pre = "ABCDEFGHIJKL";
  char *mid = "CBEFDGAJIKLH";
  char *post = "CFEGDBJLKIHA";
  char *level = "ABHCDIEGJKFL";

  struct BTree *t1 = btree_from_pre_mid(pre, mid, strlen(pre));
  struct BTree *t2 = btree_from_post_mid(post, mid, strlen(pre));
  struct BTree *t3 = btree_from_level_mid(level, mid, strlen(pre));
  struct BTree *ts = btree_build_search_tree(pre);

  struct BTree *tf = btree_find(ts, 'F');
  struct BTree *tm = btree_find(ts, 'M');

  printf("F %s\n", tf == NULL ? "not found" : "found");
  printf("M %s\n", tm == NULL ? "not found" : "found");

  printf("post: ");
  btree_post_order(t1);
  putchar('\n');
  printf("mid: ");
  btree_mid_order(t2);
  putchar('\n');
  printf("level: ");
  btree_level_order(t2);
  putchar('\n');
  printf("pre: ");
  btree_pre_order(t3);
  putchar('\n');

  printf("t1 %c= t2\n", btree_is_same(t1, t2) ? '=' : '!');
  printf("t2 %c= t3\n", btree_is_same(t2, t3) ? '=' : '!');

  printf("Flip t3\n");
  btree_flip(t3);
  printf("t2 %c= t3\n", btree_is_same(t2, t3) ? '=' : '!');
  printf("t2 %c= t3\n", btree_is_isomorphic(t2, t3) ? '~' : '^');

  printf("%d leaves\n", btree_leaves(t1));
  btree_print(t1);

  btree_destroy(t1);
  btree_destroy(t2);
  btree_destroy(t3);
  btree_destroy(ts);
}
