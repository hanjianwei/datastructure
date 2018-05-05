#pragma once

#include "btree.h"

// 使用堆构建一个 Huffman 树
struct BTree *huffman_build_using_heap(char *s);

// 用数组构建一个 Huffman 树
struct BTree *huffman_build_using_array(char *s);

// 用 Huffman 树 ht 对字符串 s 进行编码，打印出编码结果（0、1字符串），并返回编码后的长度
int huffman_encode(struct BTree *ht, char *s);

// 用 Huffman 树 ht 对字符串 s （由0、1组成）进行解码，打印出解码结果，并返回解码后的长度
int huffman_decode(struct BTree *ht, char *s);
