#include "btree.h"

#include <stdio.h>

void pre_traveral(struct BTree *root) {
  if (root == NULL) {
    return;
  }

  putchar(root->data);
  pre_traveral(root->left);
  pre_traveral(root->right);
}

void mid_traveral(struct BTree *root) {
  if (root == NULL) {
    return;
  }

  mid_traveral(root->left);
  putchar(root->data);
  mid_traveral(root->right);
}

void post_traveral(struct BTree *root) {
  if (root == NULL) {
    return;
  }

  post_traveral(root->left);
  post_traveral(root->right);
  putchar(root->data);
}

int max(int a, int b) { return a > b ? a : b; }

int depth(struct BTree *root) {
  if (root == NULL) {
    return 0;
  }

  return 1 + max(depth(root->left), depth(root->right));
}
