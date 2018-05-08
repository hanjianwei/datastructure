#pragma once

#include <stdbool.h>

struct BTree {
  char data;
  int freq;
  char code[8];
  struct BTree *left;
  struct BTree *right;
};

struct BTree *btree_create(char data, int freq, struct BTree *left,
                           struct BTree *right);

void btree_destroy(struct BTree *root);

int btree_depth(struct BTree *root);

int btree_leaves(struct BTree *root);

bool btree_is_same(struct BTree *a, struct BTree *b);

bool btree_is_isomorphic(struct BTree *a, struct BTree *b);
