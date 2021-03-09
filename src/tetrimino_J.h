#ifndef __TETRIMINO_J__
#define __TETRIMINO_J__

/**
 * +---+
 * |  X|
 * |XXX|
 * +---+
 */
static const struct rotation J_1 = {
  {
    { 0, 0, 1, 0 },
    { 1, 1, 1, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 0, 0, 0, 0 },
  { 1, 1, 2, 0 },
  { 1, 3, 0, 0 },
  2,
  3,
};

/**
 * +--+
 * |X |
 * |X |
 * |XX|
 * +--+
 */
static const struct rotation J_2 = {
  {
    { 1, 0, 0, 0 },
    { 1, 0, 0, 0 },
    { 1, 1, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 0, 0, 0, 0 },
  { 3, 1, 0, 0 },
  { 1, 1, 2, 0 },
  3,
  2,
};

/**
 *
 * +---+
 * |XXX|
 * |X  |
 * +---+
 */
static const struct rotation J_3 = {
  {
    { 1, 1, 1, 0 },
    { 1, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 0, 1, 1, 0 },
  { 2, 2, 2, 0 },
  { 3, 1, 0, 0 },
  2,
  3,
};

/**
 * +--+
 * |XX|
 * | X|
 * | X|
 * +--+
 */
static const struct rotation J_4 = {
  {
    { 1, 1, 0, 0 },
    { 0, 1, 0, 0 },
    { 0, 1, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 2, 0, 0, 0 },
  { 3, 3, 0, 0 },
  { 2, 1, 1, 0 },
  3,
  2,
};

static const struct tetrimino tetrimino_J = {
  { &J_1, &J_2, &J_3, &J_4 },
  4,
};

#endif /* !__TETRIMINO_I__ */
