#include "chained_hash.h"
#include "log.h"
#include "open_addressed_hash.h"

#include <stdlib.h>
#include <time.h>

void test_chained_hash() {
  struct ChainedHash h;

  chained_hash_init(&h, 13);

  for (int i = 0; i < 20; i++) {
    chained_hash_insert(&h, rand() % 100);
  }

  for (int i = 0; i < 5; i++) {
    int key = rand() % 100;
    struct ListNode *p = chained_hash_lookup(&h, key);
    log("Lookup %d ... %s\n", key, p == NULL ? "not found" : "found");
  }

  log("hash table size: %d\n", chained_hash_size(&h));

  chained_hash_destroy(&h);
}

void test_open_addressing() {
  struct OpenAddressedHash h;

  open_addressed_hash_init(&h, 29);

  for (int i = 0; i < 20; i++) {
    open_addressed_hash_insert(&h, rand() % 100);
  }

  for (int i = 0; i < 5; i++) {
    int key = rand() % 100;
    int pos = open_addressed_hash_lookup(&h, key);
    log("Lookup %d ... %s\n", key, pos < 0 ? "not found" : "found");
  }

  log("hash table size: %d\n", open_addressed_hash_size(&h));

  open_addressed_hash_destroy(&h);
}

int main() {
  srand(time(NULL));

  log("Test chained hash: \n");
  test_chained_hash();

  log("Test open addressing hash: \n");
  test_open_addressing();

  return 0;
}
