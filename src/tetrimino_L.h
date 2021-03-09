#ifndef __TETRIMINO_L__
#define __TETRIMINO_L__

/**
 * +---+
 * |X  |
 * |XXX|
 * +---+
 */
static const struct rotation L_1 = {
  {
    { 1, 0, 0, 0 },
    { 1, 1, 1, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 0, 0, 0, 0 },
  { 2, 1, 1, 0 },
  { 1, 3, 0, 0 },
  2,
  3,
};

/**
 * +--+
 * |XX|
 * |X |
 * |X |
 * +--+
 */
static const struct rotation L_2 = {
  {
    { 1, 1, 0, 0 },
    { 1, 0, 0, 0 },
    { 1, 0, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 0, 2, 0, 0 },
  { 3, 3, 0, 0 },
  { 2, 1, 1, 0 },
  3,
  2,
};

/**
 * +---+
 * |XXX|
 * |  X|
 * +---+
 */
static const struct rotation L_3 = {
  {
    { 1, 1, 1, 0 },
    { 0, 0, 1, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 1, 1, 0, 0 },
  { 2, 2, 2, 0 },
  { 3, 1, 0, 0 },
  2,
  3,
};

/**
 * +--+
 * | X|
 * | X|
 * |XX|
 * +--+
 */
static const struct rotation L_4 = {
  {
    { 0, 1, 0, 0 },
    { 0, 1, 0, 0 },
    { 1, 1, 0, 0 },
    { 0, 0, 0, 0 },
  },
  { 0, 0, 0, 0 },
  { 1, 3, 0, 0 },
  { 1, 1, 2, 0 },
  3,
  2,
};

static const struct tetrimino tetrimino_L = {
  { &L_1, &L_2, &L_3, &L_4 },
  4,
};

#endif /* !__TETRIMINO_L__ */
