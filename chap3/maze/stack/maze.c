#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Maze[10][10];

struct Offset {
  int dx;
  int dy;
};

/* struct Offset dirs[8] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1}, */
/*                          {1, 0},  {1, -1}, {0, -1}, {-1, -1}}; */
struct Offset dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void maze_solver(Maze maze, int entry_row, int entry_col, int exit_row,
                 int exit_col);

int main() {
  // clang-format off
  Maze maze = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  };
  // clang-format on

  maze_solver(maze, 1, 1, 8, 8);

  return 0;
}

void maze_solver(Maze maze, int entry_row, int entry_col, int exit_row,
                 int exit_col) {
  int num_dirs = sizeof(dirs) / sizeof(dirs[0]);
  Stack s;
  stack_init(&s, 10);

  stack_push(&s, (struct Position){.row = entry_row, .col = entry_col});
  maze[entry_row][entry_col] = 2;

  bool found = false;
  while (!stack_empty(&s) && !found) {
    struct Position last = stack_peek(&s);
    int dir;

    // Find next step
    for (dir = 0; dir < num_dirs; dir++) {
      struct Position next = {.row = last.row + dirs[dir].dx,
                              .col = last.col + dirs[dir].dy};

      if (next.row == exit_row && next.col == exit_col) {
        found = true;
        break;
      } else if (maze[next.row][next.col] == 0) {
        // Can visit and not visited
        stack_push(&s, next);
        maze[next.row][next.col] = 2;
        break;
      }
    }

    // Not found
    if (dir == num_dirs) {
      stack_pop(&s);
    }
  }

  if (found) {
    for (int i = 0; i < s.size; ++i) {
      printf("(%d, %d) -> ", s.buffer[i].row, s.buffer[i].col);
    }
    printf("(%d, %d)\n", exit_row, exit_col);
  }

  stack_destroy(&s);
}
