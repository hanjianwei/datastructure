#include <stdio.h>

#include "queue.h"

char phone[10][4] = {
    {' ', '\0', '\0', '\0'},  // 0
    {'\0', '\0', '\0', '\0'}, // 1
    {'a', 'b', 'c', '\0'},    // 2
    {'d', 'e', 'f', '\0'},    // 3
    {'g', 'h', 'i', '\0'},    // 4
    {'j', 'k', 'l', '\0'},    // 5
    {'m', 'n', 'o', '\0'},    // 6
    {'p', 'q', 'r', 's'},     // 7
    {'t', 'u', 'v', '\0'},    // 8
    {'w', 'x', 'y', 'z'}      // 9
};

void print_recursion(Queue *letters, char c, char *remains);

void print_digit(Queue *letters, char *remains) {
  int digit = *remains - '0';
  for (int i = 0; i < 4 && phone[digit][i] != '\0'; i++) {
    print_recursion(letters, phone[digit][i], remains + 1);
  }
}

void print_recursion(Queue *letters, char c, char *remains) {
  Queue new_letters;
  queue_copy_init(&new_letters, letters);
  queue_enqueue(&new_letters, c);

  if (*remains == '\0') {
    // No more digits
    while (!queue_empty(&new_letters)) {
      putchar(queue_dequeue(&new_letters));
    }
    putchar(' ');
  } else {
    print_digit(&new_letters, remains);
  }

  queue_destroy(&new_letters);
}

// TODO: DONE
void print_letters(char *digits) {
  if (*digits != '\0') {
    print_digit(NULL, digits);
  }
}

int main() {
  print_letters("23"); // 打印: ad, ae, af, bd, be, bf, cd, ce, cf.
  printf("\n");
}
