#include "huffman.h"
#include "heap.h"

#include <stdio.h>
#include <string.h>

// 更新字符频率
static void huffman_update_freq(int *freq, char *s) {
  while (*s != '\0') {
    freq[*s]++;
    s++;
  }
}

// 构建叶子节点
static void huffman_create_leaves(int *freq, struct Vector *ht) {
  for (int i = 0; i < 256; ++i) {
    if (freq[i] > 0) {
      vector_push_back(ht, btree_create(i, freq[i], NULL, NULL));
    }
  }
}

// 找出freq最小的，返回其下标
static int huffman_find_min_freq(struct Vector *ht) {
  int k = ht->size == 0 ? -1 : 0;
  for (int i = 1; i < ht->size; ++i) {
    if (ht->buffer[i]->freq < ht->buffer[k]->freq) {
      k = i;
    }
  }

  return k;
}

static struct BTree *huffman_pop_min_freq(struct Vector *ht) {
  int k = huffman_find_min_freq(ht);
  if (k < 0) {
    return NULL;
  }

  struct BTree *node = ht->buffer[k];
  SWAP(ht->buffer[k], ht->buffer[ht->size - 1], struct BTree *);
  vector_pop_back(ht);

  return node;
}

static void huffman_build_codebook(struct BTree *ht, struct BTree *parent,
                                   enum Side side, char **cb) {
  if (ht == NULL) {
    return;
  }

  if (parent != NULL) {
    strcpy(ht->code, parent->code);
    strcat(ht->code, side == SIDE_LEFT ? "0" : "1");
  }

  if (ht->left == NULL && ht->right == NULL) {
    cb[ht->data] = ht->code;
  } else {
    huffman_build_codebook(ht->left, ht, SIDE_LEFT, cb);
    huffman_build_codebook(ht->right, ht, SIDE_RIGHT, cb);
  }
}

// TODO:
// 使用堆构建一个 Huffman 树
struct BTree *huffman_build_using_heap(char *s) {
  int freq[256] = {0};
  huffman_update_freq(freq, s);

  Heap ht;
  heap_init(&ht);

  huffman_create_leaves(freq, &ht);
  heap_rebuild(&ht);

  struct BTree *a, *b, *new_node;
  while (heap_size(&ht) > 1) {
    a = heap_pop(&ht);
    b = heap_pop(&ht);
    new_node = btree_create('O', a->freq + b->freq, a, b);
    heap_insert(&ht, new_node);
  }

  heap_destroy(&ht);

  return new_node;
}

// TODO: DONE
// 用数组构建一个 Huffman 树
struct BTree *huffman_build_using_array(char *s) {
  int freq[256] = {0};
  huffman_update_freq(freq, s);

  struct Vector ht;
  vector_init(&ht, 10);

  huffman_create_leaves(freq, &ht);

  struct BTree *a, *b, *new_node;
  while (ht.size > 1) {
    a = huffman_pop_min_freq(&ht);
    b = huffman_pop_min_freq(&ht);
    new_node = btree_create('O', a->freq + b->freq, a, b);
    vector_push_back(&ht, new_node);
  }

  vector_destroy(&ht);

  return new_node;
}

// TODO:
// 用 Huffman 树ht对字符串 s
// 进行编码，打印出编码结果（0、1字符串），并返回编码后的长度
int huffman_encode(struct BTree *ht, char *s) {
  char *codebook[256] = {NULL};
  int n = 0;

  huffman_build_codebook(ht, NULL, SIDE_LEFT, codebook);

  while (*s != '\0') {
    if (codebook[*s] == NULL) {
      fprintf(stderr, "Char %c is not in codebook\n", *s);
      return -1;
    } else {
      printf("%s", codebook[*s]);
      n += strlen(codebook[*s]);
    }
    s++;
  }
  printf("\n");

  return n;
}

// TODO:
// 用 Huffman 树 ht 对字符串 s
// （由0、1组成）进行解码，打印出解码结果，并返回解码后的长度
int huffman_decode(struct BTree *ht, char *s) {
  int n = 0;

  if (ht == NULL) {
    fprintf(stderr, "Empty huffman tree\n");
    return -1;
  }

  struct BTree *t = ht;
  while (*s != '\0') {
    if (*s == '0') {
      t = t->left;
    } else if (*s == '1') {
      t = t->right;
    } else {
      fprintf(stderr, "Invalid char %c\n", *s);
      break;
    }

    if (t == NULL) {
      fprintf(stderr, "Parsing error\n");
      break;
    }

    if (t->left == NULL && t->right == NULL) {
      putchar(t->data);
      n++;
      t = ht;
    }

    s++;
  }
  putchar('\n');

  if (*s != '\0' || t != ht) {
    fprintf(stderr, "Parsing error\n");
    return -1;
  }

  return n;
}
