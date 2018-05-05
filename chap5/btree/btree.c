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
  char *root;
  if (len == 0 || (root = strchr(mid, pre[0])) == NULL) {
    return NULL;
  }

  int nl = root - mid;
  struct BTree *tl = btree_from_pre_mid(pre + 1, mid, nl);
  struct BTree *tr = btree_from_pre_mid(pre + nl + 1, root + 1, len - nl - 1);

  return btree_create(*root, tl, tr);
}

// TODO: DONE
// 根据后序`post`和中序`mid`遍历构建一棵二叉树
struct BTree *btree_from_post_mid(char *post, char *mid, int len) {
  char *root;
  if (len == 0 || (root = strchr(mid, post[len - 1])) == NULL) {
    return NULL;
  }

  int nl = root - mid;
  struct BTree *tl = btree_from_post_mid(post, mid, nl);
  struct BTree *tr = btree_from_post_mid(post + nl, root + 1, len - nl - 1);

  return btree_create(*root, tl, tr);
}

// 找出 mid 中节点在层次遍历 level中最先出现的一个
static char *find_min_level_char(char *level, char *mid, int len) {
  while (*level != '\0') {
    char *c = memchr(mid, *level, len);
    if (c != NULL) {
      return c;
    }
    level++;
  }
  return NULL;
}

// TODO: DONE
// 根据层次`level`和中序`mid`遍历构建一棵二叉树
struct BTree *btree_from_level_mid(char *level, char *mid, int len) {
  char *root;
  if (len == 0 || (root = find_min_level_char(level, mid, len)) == NULL) {
    return NULL;
  }

  int nl = root - mid;
  struct BTree *tl = btree_from_level_mid(level, mid, nl);
  struct BTree *tr = btree_from_level_mid(level, root + 1, len - nl - 1);

  return btree_create(*root, tl, tr);
}

// 二叉搜索树中插入一个节点
struct BTree *btree_insert(struct BTree *root, char value) {
  if (root == NULL) {
    root = btree_create(c, NULL, NULL);
  } else if (value < root->data) {
    root = btree_insert(root->left, value);
  } else if (value > root->data) {
    root = btree_insert(root->right, value);
  }

  return root;
}

// TODO: DONE
// 根据字符串`s`构建一棵搜索二叉树
struct BTree *btree_build_search_tree(char *s) {
  struct BTree *root = NULL;

  while (*s != '\0') {
    root = btree_insert(root, *s);
    s++;
  }

  return root;
}

// TODO: DONE
// 在二叉搜索树`root`中查找`value`，如果找到返回相应节点，否则返回NULL
struct BTree *btree_find(struct BTree *root, char value) {
  if (root == NULL || root->data == value) {
    return root;
  }

  if (value < root->data) {
    return btree_find(root->left, value);
  }
  return btree_find(root->right, value);
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

// TODO:
// 判断两棵树是否相同, 相同返回1， 不同返回0
bool btree_is_same(struct BTree *a, struct BTree *b) { return false; }

// TODO:
// 判断两棵树是否同构，即能够通过若干次左右子树的交换由a变为b，同构返回1，不同构返回2
bool btree_is_isomorphic(struct BTree *a, struct BTree *b) { return false; }
