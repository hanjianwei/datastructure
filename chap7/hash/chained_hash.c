#include "chained_hash.h"
#include "log.h"

#include <stdlib.h>

void chained_hash_init(struct ChainedHash *h, int buckets) {
  h->buckets = buckets;
  h->table = malloc(buckets * sizeof(struct List));
  for (int i = 0; i < buckets; i++) {
    list_init(&h->table[i]);
  }
}

void chained_hash_destroy(struct ChainedHash *h) {
  for (int i = 0; i < h->buckets; i++) {
    list_destroy(&h->table[i]);
  }
  free(h->table);
  h->buckets = 0;
}

static int chained_hash_key_to_index(struct ChainedHash *h, int key) {
  int index = key % h->buckets;
  if (index < 0) {
    index += h->buckets;
  }

  return index;
}

void chained_hash_insert(struct ChainedHash *h, int key) {
  int index = chained_hash_key_to_index(h, key);
  list_push_back(&h->table[index], key);
  log("Insert %d at position %d\n", key, index);
}

struct ListNode *chained_hash_lookup(struct ChainedHash *h, int key) {
  int index = chained_hash_key_to_index(h, key);
  struct List *chain = h->table + index;

  struct ListNode *p = chain->head;
  while (p != NULL) {
    if (p->data == key) {
      break;
    }
    p = p->next;
  }

  return p;
}

int chained_hash_size(struct ChainedHash *h) {
  int n = 0;

  for (int i = 0; i < h->buckets; i++) {
    n += list_size(h->table + i);
  }

  return n;
}
