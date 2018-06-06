#pragma once
#include <stdbool.h>

struct OpenAddressedHash {
  int buckets;
  int size;
  int *table;
  bool *empty;
};

void open_addressed_hash_init(struct OpenAddressedHash *h, int buckets);

void open_addressed_hash_destroy(struct OpenAddressedHash *h);

void open_addressed_hash_insert(struct OpenAddressedHash *h, int key);

int open_addressed_hash_lookup(struct OpenAddressedHash *h, int key);

int open_addressed_hash_size(struct OpenAddressedHash *h);
