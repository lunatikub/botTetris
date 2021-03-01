#ifndef __TETRIMINO_Z__
#define __TETRIMINO_Z__

/**
 * +---+
 * |XX |
 * | XX|
 * +---+
 */
static const struct rotation Z_1 = {
  {
    { 1, 1, 0, 0 },
    { 0, 1, 1, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 1, 0, 0, 0 },
  { 2, 2, 1, 0 },
  { 2, 2, 0, 0 },
  2,
  3,
};

/**
 * +--+
 * | X|
 * |XX|
 * |X |
 * +--+
 */
static const struct rotation Z_2 = {
  {
    { 0, 1, 0, 0 },
    { 1, 1, 0, 0 },
    { 1, 0, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 0, 1, 0, 0 },
  { 2, 3, 1, 0 },
  { 1, 2, 1, 0 },
  3,
  2,
};

static const struct tetrimino tetrimino_Z = {
  { &Z_1, &Z_2 },
  2,
};

#endif /* !__TETRIMINO_Z__ */
