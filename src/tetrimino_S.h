#ifndef __TETRIMINO_S__
#define __TETRIMINO_S__

/**
 * +---+
 * | XX|
 * |XX |
 * +---+
 */
static const struct rotation S_1 = {
  {
    { 0, 1, 1, 0 },
    { 1, 1, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 0, 0, 1, 0 },
  { 1, 2, 2, 0 },
  { 2, 2, 0, 0 },
  2,
  3,
};

/**
 * +--+
 * |X |
 * |XX|
 * | X|
 * +--+
 */
static const struct rotation S_2 = {
  {
    { 1, 0, 0, 0 },
    { 1, 1, 0, 0 },
    { 0, 1, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 1, 0, 0, 0 },
  { 3, 2, 1, 0 },
  { 1, 2, 1, 0 },
  3,
  2,
};

static const struct tetrimino tetrimino_S = {
  { &S_1, &S_2 },
  2,
};

#endif /* !__TETRIMINO_S__ */
