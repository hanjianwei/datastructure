#include "btree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BTree *btree_create(TreeDataType root, struct BTree *left, struct BTree *right) {
  struct BTree *root_node = malloc(sizeof(struct BTree));
  root_node->data = root;
  root_node->left = left;
  root_node->right = right;

  return root_node;
}

void btree_destroy(struct BTree *root) {
  if (root == NULL) {
    return;
  }

  btree_destroy(root->left);
  btree_destroy(root->right);
  free(root);
}

// TODO: DONE
// 在二叉搜索树`root`中查找`value`，如果找到返回相应节点，否则返回NULL
struct BTree *btree_find(struct BTree *root, TreeDataType value) {
  if (root == NULL) {
    return NULL;
  }

  if (value < root->data) {
    return btree_find(root->left, value);
  } else if (value > root->data) {
    return btree_find(root->right, value);
  } else {
    return root;
  }
}

int btree_depth(struct BTree *root) {
  if (root == NULL) {
    return 0;
  }

  int ld = btree_depth(root->left);
  int rd = btree_depth(root->right);

  return 1 + (ld > rd ? ld : rd);
}

int btree_leaves(struct BTree *root) {
  if (root == NULL) {
    return 0;
  }

  if (root->left == NULL && root->right == NULL) {
    return 1;
  }

  return btree_leaves(root->left) + btree_leaves(root->right);
}
