#pragma once

struct BTree {
  char data;
  struct BTree *left;
  struct BTree *right;
};

struct BTree *btree_create(char root, struct BTree *left, struct BTree *right);

void btree_destroy(struct BTree *root);

struct BTree *btree_from_pre_mid(char *pre, char *mid, int len);

struct BTree *btree_from_post_mid(char *post, char *mid, int len);

struct BTree *btree_from_level_mid(char *level, char *mid, int len);

struct BTree *btree_build_search_tree(char *s);

struct BTree *btree_find(struct BTree *root, char value);

void btree_pre_order(struct BTree *root);

void btree_mid_order(struct BTree *root);

void btree_post_order(struct BTree *root);

void btree_level_order(struct BTree *root);

int btree_depth(struct BTree *root);

int btree_leaves(struct BTree *root);

void btree_flip(struct BTree *root);

int btree_is_same(struct BTree *a, struct BTree *b);

int btree_is_isomorphic(struct BTree *a, struct BTree *b);
