#include "eval.h"
#include "common.h"
#include "test.h"

TEST_F(erosion)
{
  struct field *f = field_new();

  SET(f, 18, LINE({0, 0, 0, 1, 1, 1, 1, 1, 1, 1}));
  SET(f, 19, LINE({1, 0, 1, 1, 1, 1, 1, 1, 1, 1}));
  rotation_put(f, TETRIMINO_T, 2, 0);
  EXPECT_UINT_EQ(eval_erosion(f), 8);

  SET(f, 19, LINE({0, 0, 1, 1, 1, 1, 1, 1, 1, 1}));
  rotation_put(f, TETRIMINO_O, 0, 0);
  EXPECT_UINT_EQ(eval_erosion(f), 2);

  rotation_put(f, TETRIMINO_I, 0, 0);
  EXPECT_UINT_EQ(eval_erosion(f), 0);

  SET(f, 16, LINE({0, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
  SET(f, 17, LINE({0, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
  SET(f, 18, LINE({0, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
  SET(f, 19, LINE({0, 1, 1, 1, 1, 1, 1, 1, 1, 1}));

  rotation_put(f, TETRIMINO_I, 1, 0);
  EXPECT_UINT_EQ(eval_erosion(f), 16);

  free(f);
  return true;
}

TEST_F(hlt)
{
  struct field *f = field_new();

  SET(f, 18, LINE({1, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
  SET(f, 19, LINE({1, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
  rotation_put(f, TETRIMINO_T, 0, 1);
  EXPECT_UINT_EQ(f->hlt, 3);

  free(f);
  return true;
}

TEST_F(delta_l)
{
  struct field *f = field_new();

  SET(f, 18, LINE({0, 0, 1, 2, 3, 0, 4, 0, 5, 0}));
  SET(f, 19, LINE({0, 6, 0, 7, 0, 8, 0, 9, 0, 1}));
  EXPECT_UINT_EQ(eval_delta_l(f), 15);

  free(f);
  return true;
}

TEST_F(delta_c)
{
  struct field *f = field_new();

  SET(f, 18, LINE({0, 0, 1, 2, 3, 0, 5, 0, 6, 0}));
  SET(f, 19, LINE({0, 7, 0, 8, 0, 9, 0, 1, 0, 2}));
  EXPECT_UINT_EQ(eval_delta_c(f), 13);

  free(f);
  return true;
}

TEST_F(holes)
{
  struct field *f = field_new();

  SET(f, 16, LINE({1, 0, 0, 0, 1, 0, 0, 0, 0, 0}));
  SET(f, 17, LINE({0, 1, 0, 0, 0, 0, 0, 0, 0, 0}));
  SET(f, 18, LINE({0, 0, 1, 0, 1, 0, 0, 0, 0, 0}));
  SET(f, 20, LINE({0, 0, 0, 1, 0, 0, 0, 0, 0, 0}));

  dump(f);

  EXPECT_UINT_EQ(eval_holes(f), 8);

  free(f);
  return true;
}

const static struct test eval_tests[] = {
  TEST(erosion),
  TEST(hlt),
  TEST(delta_l),
  TEST(delta_c),
  TEST(holes),
};

TEST_SUITE(eval);
