#ifndef __TETRIMINO_I__
#define __TETRIMINO_I__

/*
 * +----+
 * |XXXX|
 * +----+
 */
static const struct rotation I_1 = {
  {
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 1, 1, 1, 1 },
  },
  { 0, 0, 0, 0 },
  { 1, 1, 1, 1 },
  { 4, 0, 0, 0 },
  1,
  4,
};

/*
 * +-+
 * |X|
 * |X|
 * |X|
 * |X|
 * +-+
 */
static const struct rotation I_2 = {
  {
    { 1, 0, 0, 0 },
    { 1, 0, 0, 0 },
    { 1, 0, 0, 0 },
    { 1, 0, 0, 0 },
  },
  { 0, 0, 0, 0 },
  { 4, 0, 0, 0 },
  { 1, 1, 1, 1 },
  4,
  1,
};

static const struct tetrimino tetrimino_I = {
  { &I_1, &I_2 },
  2,
};

#endif /* !__TETRIMINO_I__ */
