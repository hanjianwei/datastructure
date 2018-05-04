#pragma once

#include "btree.h"

// Build a huffman tree from a string
struct BTree *huffman_build(char *s);

void huffman_encode(struct BTree *t, char *s);

void huffman_decode(struct BTree *t, char *s);
