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

  /* struct BTree *root = btree_from_pre_mid(pre, mid, strlen(pre)); */
  /* struct BTree *root = btree_from_post_mid(post, mid, strlen(pre)); */
  struct BTree *root = btree_from_level_mid(level, mid, strlen(pre));
  btree_pre_order(root);
  /* btree_mid_order(root); */
  /* btree_post_order(root); */
  putchar('\n');

  printf("%d leaves\n", btree_leaves(root));

  btree_print(root);

  btree_destroy(root);
}
