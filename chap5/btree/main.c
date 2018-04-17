#include <stdio.h>
#include <stdlib.h>

#include "btree.h"

int main() {
  struct BTree *plus = malloc(sizeof(struct BTree));
  struct BTree *mul = malloc(sizeof(struct BTree));
  struct BTree *div = malloc(sizeof(struct BTree));
  struct BTree *a = malloc(sizeof(struct BTree));
  struct BTree *b = malloc(sizeof(struct BTree));
  struct BTree *c = malloc(sizeof(struct BTree));
  struct BTree *d = malloc(sizeof(struct BTree));

  plus->data = '+';
  plus->left = mul;
  plus->right = div;

  mul->data = '*';
  mul->left = a;
  mul->right = b;

  div->data = '/';
  div->left = c;
  div->right = d;

  a->data = 'a';
  a->left = a->right = NULL;

  b->data = 'b';
  b->left = b->right = NULL;

  c->data = 'c';
  c->left = c->right = NULL;

  d->data = 'd';
  d->left = d->right = NULL;

  printf("Pre: ");
  pre_traveral(plus);
  printf("\n");
  printf("Mid: ");
  mid_traveral(plus);
  printf("\n");
  printf("Post: ");
  post_traveral(plus);
  printf("\n");
}
