#include "btree_vis.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void btree_to_array(struct BTree *root, struct BTree *arr[], int root_index) {
  if (root == NULL) {
    return;
  }

  arr[root_index] = root;
  btree_to_array(root->left, arr, 2 * root_index);
  btree_to_array(root->right, arr, 2 * root_index + 1);
}

void btree_xy_map(int depth, int x[], int y[]) {
  if (depth == 0) {
    return;
  }

  // Initialize xy map
  int num_nodes = (1 << depth);
  int i;
  for (i = 0; i < num_nodes; i++) {
    x[i] = -1;
    y[i] = -1;
  }

  // Fill left side of the tree
  i = (1 << (depth - 1));
  x[i] = 0;
  y[i] = 0;
  if (depth == 1) {
    return;
  }

  i /= 2;
  x[i] = 2;
  y[i] = 2;

  i /= 2;
  for (; i > 0; i /= 2) {
    x[i] = 2 * x[i * 2] + 1;
    y[i] = 2 * y[i * 2] + 1;
  }

  // Fill the remaining nodes
  for (i = 1; i < num_nodes; i++) {
    if (x[i] < 0 || y[i] < 0) {
      for (int d = 1; d < depth; d++) {
        int parent = (i >> d);
        int j = (((parent << 1) + 1) << d) - 1 - i;
        if (x[j] >= 0 && y[j] >= 0) {
          x[i] = 2 * x[parent] - x[j];
          y[i] = y[j];
          break;
        }
      }
    }
  }
}

void btree_print_line(int x0, int y0, int x1, int y1, char buffer[], int w,
                      int h) {
  int n = x1 - x0;
  char c = n > 0 ? '/' : '\\';

  if (n < 0) {
    n = -n;
  }

  for (int i = 1; i < n; i++) {
    int x = (i * x0 + (n - i) * x1) / n;
    int y = (i * y0 + (n - i) * y1) / n;
    buffer[y * w + x] = c;
  }
}

void btree_print(struct BTree *root) {
  if (root == NULL) {
    return;
  }

  int depth = btree_depth(root);
  int num_nodes = (1 << depth);
  int x[num_nodes];
  int y[num_nodes];

  btree_xy_map(depth, x, y);

  struct BTree *nodes[num_nodes];
  memset(nodes, 0, sizeof(struct BTree *) * num_nodes);
  btree_to_array(root, nodes, 1);

  int w = x[1] * 2 + 1;
  int h = y[1] + 1;
  char buffer[w * h];

  memset(buffer, ' ', w * h * sizeof(char));
  buffer[y[1] * w + x[1]] = root->data;
  for (int i = 2; i < num_nodes; i++) {
    if (nodes[i] == NULL) {
      continue;
    }
    buffer[y[i] * w + x[i]] = nodes[i]->data;

    int parent = i / 2;
    btree_print_line(x[i], y[i], x[parent], y[parent], buffer, w, h);
  }

  for (int j = h-1; j >= 0; j--) {
    for (int i = 0; i < w; i++) {
      putchar(buffer[j * w + i]);
    }
    putchar('\n');
  }
}
