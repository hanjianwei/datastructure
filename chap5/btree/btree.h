#pragma once

struct BTree {
  char data;
  struct BTree *left;
  struct BTree *right;
};

void pre_traveral(struct BTree *root);

void mid_traveral(struct BTree *root);

void post_traveral(struct BTree *root);

int depth(struct BTree *root);
