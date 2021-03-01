#ifndef __TETRIMINO_T__
#define __TETRIMINO_T__

/**
 * +---+
 * | X |
 * |XXX|
 * +---+
 */
static const struct rotation T_1 = {
  {
    { 0, 1, 0, 0 },
    { 1, 1, 1, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 0, 0, 0, 0 },
  { 1, 2, 1, 0 },
  { 1, 3, 0, 0 },
  2,
  3,
};

/**
 * +--+
 * |X |
 * |XX|
 * |X |
 * +--+
 */
static const struct rotation T_2 = {
  {
    { 1, 0, 0, 0 },
    { 1, 1, 0, 0 },
    { 1, 0, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 0, 1, 0, 0 },
  { 3, 2, 1, 0 },
  { 1, 2, 1, 0 },
  3,
  2,
};

/**
 * +---+
 * | X |
 * |XXX|
 * +---+
 */
static const struct rotation T_3 = {
  {
    { 1, 1, 1, 0 },
    { 0, 1, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 1, 0, 1, 0 },
  { 2, 2, 2, 0 },
  { 3, 1, 0, 0 },
  2,
  3,
};

/**
 * +--+
 * | X|
 * |XX|
 * | X|
 * +--+
 */
static const struct rotation T_4 = {
  {
    { 0, 1, 0, 0 },
    { 1, 1, 0, 0 },
    { 0, 1, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 1, 0, 0, 0 },
  { 2, 3, 1, 0 },
  { 1, 2, 1, 0 },
  3,
  2,
};

static const struct tetrimino tetrimino_T = {
  { &T_1, &T_2, &T_3, &T_4 },
  4,
};

#endif /* !__TETRIMINO_T__ */
