#pragma once

enum Status {
  STATUS_OK                   = 0,

  STATUS_ERR_ALLOC            = 1,
  STATUS_ERR_INVALID_CAPACITY = 2,
  STATUS_ERR_INVALID_RANGE    = 3,
  STATUS_ERR_MAX_CAPACITY     = 4,
  STATUS_ERR_KEY_NOT_FOUND    = 6,
  STATUS_ERR_VALUE_NOT_FOUND  = 7,
  STATUS_ERR_OUT_OF_RANGE     = 8,

  STATUS_ITER_END             = 9,
};

#define SWAP(x, y, T)                           \
  do {                                          \
    T SWAP = x;                                 \
    x = y;                                      \
    y = SWAP;                                   \
  } while (0)
