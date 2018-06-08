#include "search.h"
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int name_comp(const void *a, const void *b) {
  const struct Student *sa = a;
  const struct Student *sb = b;

  return strcmp(sa->name, sb->name);
}

void print_student(struct Student *stu) {
  printf("id: %d\n", stu->id);
  printf("name: %s\n", stu->name);
  printf("birthday: %d/%d/%d\n", stu->birthday.year, stu->birthday.month,
         stu->birthday.day);
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

  int m = search(&students, &(struct Student){.name = "Mike"}, name_comp);
  print_student(students.buffer + m);

  sort(&students, name_comp);
  int t = bin_search(&students, &(struct Student){.name = "Tom"}, name_comp);
  print_student(students.buffer + t);

  vector_destroy(&students);

  return 0;
}
