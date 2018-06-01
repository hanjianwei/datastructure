#pragma once

struct Date {
  int year;
  int month;
  int day;
};

struct Student {
  int id;
  char name[64];
  struct Date birthday;
};
