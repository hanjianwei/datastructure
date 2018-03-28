#include "queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Maze[10][10];

#define MAZE_INDEX(row, col) (row * 10 + col)
#define ROW(index) (index / 10)
#define COL(index) (index % 10)

struct Offset {
  int dx;
  int dy;
};

struct Offset dirs[8] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                         {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
/* struct Offset dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; */

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

  Queue q;
  queue_init(&q);

  queue_enqueue(&q, (struct Position){.row = entry_row, .col = entry_col});
  maze[entry_row][entry_col] = 1;

  bool found = false;
  while (!queue_empty(&q) && !found) {
    struct Position last = queue_dequeue(&q);
    int index = MAZE_INDEX(last.row, last.col);
    int dir;

    // Find next step
    for (dir = 0; dir < num_dirs; dir++) {
      struct Position next = {.row = last.row + dirs[dir].dx,
                              .col = last.col + dirs[dir].dy};

      if (maze[next.row][next.col] == 0) {
        maze[next.row][next.col] = index;
        queue_enqueue(&q, next);
      }

      if (next.row == exit_row && next.col == exit_col) {
        found = true;
        break;
      }
    }
  }

  if (found) {
    int row = exit_row;
    int col = exit_col;
    int index = MAZE_INDEX(row, col);

    while (row != entry_row || col != entry_col) {
      printf("(%d, %d) <- ", row, col);
      index = maze[row][col];
      row = ROW(index);
      col = COL(index);
    }

    printf("(%d, %d)\n", entry_row, entry_col);
  }

  queue_destroy(&q);
}
