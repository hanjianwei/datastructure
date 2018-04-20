#include "btree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BTree *btree_create(char root, struct BTree *left, struct BTree *right) {
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

struct BTree *btree_from_pre_mid(char *pre, char *mid, int len) {
  if (len == 0) {
    return NULL;
  }

  char *root = strchr(mid, pre[0]);
  if (root == NULL) {
    return NULL;
  }

  int ll = root - mid;
  struct BTree *left = btree_from_pre_mid(pre + 1, mid, ll);
  struct BTree *right =
      btree_from_pre_mid(pre + ll + 1, root + 1, len - ll - 1);

  return btree_create(*root, left, right);
}

// TODO:
// 根据后序`post`和中序`mid`遍历构建一棵二叉树
struct BTree *btree_from_post_mid(char *post, char *mid, int len) {
  return NULL;
}

// TODO:
// 根据层次`level`和中序`mid`遍历构建一棵二叉树
struct BTree *btree_from_level_mid(char *level, char *mid, int len) {
  return NULL;
}

// TODO:
// 根据字符串`s`构建一棵搜索二叉树
struct BTree *btree_build_search_tree(char *s) {
  return NULL;
}

// TODO:
// 在二叉搜索树`root`中查找`value`，如果找到返回相应节点，否则返回NULL
struct BTree *btree_find(struct BTree *root, char value) {
  return NULL;
}

void btree_pre_order(struct BTree *root) {
  if (root == NULL) {
    return;
  }

  putchar(root->data);
  btree_pre_order(root->left);
  btree_pre_order(root->right);
}

void btree_mid_order(struct BTree *root) {
  if (root == NULL) {
    return;
  }

  btree_mid_order(root->left);
  putchar(root->data);
  btree_mid_order(root->right);
}

void btree_post_order(struct BTree *root) {
  if (root == NULL) {
    return;
  }

  btree_post_order(root->left);
  btree_post_order(root->right);
  putchar(root->data);
}

// TODO:
// 对二叉树进行层次遍历
void btree_level_order(struct BTree *root) {}

int max(int a, int b) { return a > b ? a : b; }

int btree_depth(struct BTree *root) {
  if (root == NULL) {
    return 0;
  }

  return 1 + max(btree_depth(root->left), btree_depth(root->right));
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

void btree_flip(struct BTree *root) {
  if (root == NULL) {
    return;
  }

  struct BTree *tmp = root->left;
  root->left = root->right;
  root->right = tmp;

  btree_flip(root->left);
  btree_flip(root->right);
}
