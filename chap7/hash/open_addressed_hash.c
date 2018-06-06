#include "open_addressed_hash.h"
#include "log.h"

#include <stdlib.h>

void open_addressed_hash_init(struct OpenAddressedHash *h, int buckets) {
  h->buckets = buckets;
  h->size = 0;
  h->table = malloc(buckets * sizeof(int));
  h->empty = malloc(buckets * sizeof(bool));

  for (int i = 0; i < buckets; i++) {
    h->empty[i] = true;
  }
}

void open_addressed_hash_destroy(struct OpenAddressedHash *h) {
  free(h->table);
  free(h->empty);
  h->buckets = 0;
  h->size = 0;
}

static int open_addressed_hash_key_to_index(struct OpenAddressedHash *h,
                                            int key) {
  int index = key % h->buckets;
  if (index < 0) {
    index += h->buckets;
  }

  return index;
}

void open_addressed_hash_insert(struct OpenAddressedHash *h, int key) {
  log("Insert %d\n", key);
  if (h->buckets == h->size) {
    log("\tNo room for %d\n", key);
    return;
  }

  int index = open_addressed_hash_key_to_index(h, key);
  log("\tCheck %d\n", index);
  while (!h->empty[index]) {
    index = (index + 1) % h->buckets;
    log("\tCheck %d\n", index);
  }

  h->table[index] = key;
  h->empty[index] = false;
  h->size++;

  log("\t=> position %d\n", index);
}

int open_addressed_hash_lookup(struct OpenAddressedHash *h, int key) {
  int index = open_addressed_hash_key_to_index(h, key);

  int pos;
  for (int i = 0; i < h->buckets; i++) {
    pos = (index + i) % h->buckets;
    if (h->empty[pos] || h->table[pos] == key) {
      break;
    }
  }

  if (!h->empty[pos] && h->table[pos] == key) {
    return pos;
  }

  return -1;
}

int open_addressed_hash_size(struct OpenAddressedHash *h) { return h->size; }
