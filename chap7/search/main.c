#include "search.h"
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int name_comp(struct Student *a, struct Student *b) {
  return strcmp(a->name, b->name);
}

int main() {
  struct Vector students;
  vector_init(&students, 10);

  vector_push_back(
      &students,
      (struct Student){.id = 1,
                       .name = "Tom",
                       .birthday = {.year = 1999, .month = 2, .day = 10}});
  vector_push_back(
      &students,
      (struct Student){.id = 2,
                       .name = "Jack",
                       .birthday = {.year = 2000, .month = 3, .day = 20}});
  vector_push_back(
      &students,
      (struct Student){.id = 3,
                       .name = "Mike",
                       .birthday = {.year = 1999, .month = 8, .day = 7}});

  sort(&students, name_comp);

  int m = search(&students, &(struct Student){.name = "Mike"}, name_comp);
  int t = bin_search(&students, &(struct Student){.name = "Tom"}, name_comp);

  vector_destroy(&students);

  return 0;
}
