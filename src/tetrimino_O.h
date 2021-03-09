#ifndef __TETRIMINO_O__
#define __TETRIMINO_O__

/**
 * +--+
 * |XX|
 * |XX|
 * +--+
 */
static const struct rotation O_1 = {
  {
    { 1, 1, 0, 0 },
    { 1, 1, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 0, 0, 0, 0 },
  { 2, 2, 0, 0 },
  { 2, 2, 0, 0 },
  2,
  2,
};

static const struct tetrimino tetrimino_O = {
  { &O_1 },
  1,
};

#endif /* !__TETRIMINO_O__ */
