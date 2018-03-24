#pragma once

enum cc_stat {
  CC_OK                   = 0,

  CC_ERR_ALLOC            = 1,
  CC_ERR_INVALID_CAPACITY = 2,
  CC_ERR_INVALID_RANGE    = 3,
  CC_ERR_MAX_CAPACITY     = 4,
  CC_ERR_KEY_NOT_FOUND    = 6,
  CC_ERR_VALUE_NOT_FOUND  = 7,
  CC_ERR_OUT_OF_RANGE     = 8,

  CC_ITER_END             = 9,
};

#define SWAP(x, y, T)                           \
  do {                                          \
    T SWAP = x;                                 \
    x = y;                                      \
    y = SWAP;                                   \
  } while (0)
