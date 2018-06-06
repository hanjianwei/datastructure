#pragma once

#include "list.h"

struct ChainedHash {
  int buckets;
  struct List *table;
};

void chained_hash_init(struct ChainedHash *h, int buckets);

void chained_hash_destroy(struct ChainedHash *h);

void chained_hash_insert(struct ChainedHash *h, int key);

struct ListNode *chained_hash_lookup(struct ChainedHash *h, int key);

int chained_hash_size(struct ChainedHash *h);
