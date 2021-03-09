#include "tetrimino.h"
#include "common.h"
#include "test.h"

TEST_F(line_get)
{
  struct field *f = field_new();

  SET(f, 18, LINE({0, 1, 0}));
  SET(f, 19, LINE({1, 1, 1}));

  const struct rotation *r = rotation_get(TETRIMINO_J, 1);

  EXPECT_UINT_EQ(line_get(f, r, 0), 18);
  EXPECT_UINT_EQ(line_get(f, r, 1), 18);
  EXPECT_UINT_EQ(line_get(f, r, 2), 19);
  EXPECT_UINT_EQ(line_get(f, r, 3), 20);

  r = rotation_get(TETRIMINO_T, 2);

  EXPECT_UINT_EQ(line_get(f, r, 0), 18);
  EXPECT_UINT_EQ(line_get(f, r, 1), 19);
  EXPECT_UINT_EQ(line_get(f, r, 2), 20);

  free(f);
  return true;
}

TEST_F(line_get_well)
{
  struct field *f = field_new();

  SET(f, 16, LINE({1, 0, 1}));
  SET(f, 17, LINE({1, 0, 1}));
  SET(f, 18, LINE({1, 0, 1}));
  SET(f, 19, LINE({1, 0, 1}));

  const struct rotation *r = rotation_get(TETRIMINO_I, 1);

  EXPECT_UINT_EQ(line_get(f, r, 0), 16);
  EXPECT_UINT_EQ(line_get(f, r, 1), 20);
  EXPECT_UINT_EQ(line_get(f, r, 2), 16);

  free(f);
  return true;
}

TEST_F(rotation_put_1)
{
  struct field *f = field_new();

  rotation_put(f, TETRIMINO_J, 1, 0);
  rotation_put(f, TETRIMINO_O, 0, 0);

  EXPECT_TRUE(EQ(f, 15, LINE({1, 1})));
  EXPECT_TRUE(EQ(f, 16, LINE({1, 1})));
  EXPECT_TRUE(EQ(f, 17, LINE({1, 0})));
  EXPECT_TRUE(EQ(f, 18, LINE({1, 0})));
  EXPECT_TRUE(EQ(f, 19, LINE({1, 1})));

  EXPECT_UINT_EQ(f->height_col[0], 5);
  EXPECT_UINT_EQ(f->height_col[1], 5);

  EXPECT_UINT_EQ(f->block_line[15], 2);
  EXPECT_UINT_EQ(f->block_line[16], 2);
  EXPECT_UINT_EQ(f->block_line[17], 1);
  EXPECT_UINT_EQ(f->block_line[18], 1);
  EXPECT_UINT_EQ(f->block_line[19], 2);

  free(f);
  return true;
}

TEST_F(rotation_put_2)
{
  struct field *f = field_new();

  rotation_put(f, TETRIMINO_J, 1, 0);
  rotation_put(f, TETRIMINO_O, 0, 1);

  EXPECT_TRUE(EQ(f, 17, LINE({1, 1, 1})));
  EXPECT_TRUE(EQ(f, 18, LINE({1, 1, 1})));
  EXPECT_TRUE(EQ(f, 19, LINE({1, 1})));

  EXPECT_UINT_EQ(f->height_col[0], 3);
  EXPECT_UINT_EQ(f->height_col[1], 3);
  EXPECT_UINT_EQ(f->height_col[2], 3);

  free(f);
  return true;
}

TEST_F(line_clear)
{
  struct field *f = field_new();

  rotation_put(f, TETRIMINO_I, 0, 0);
  rotation_put(f, TETRIMINO_I, 0, 4);
  rotation_put(f, TETRIMINO_O, 0, 8);

  EXPECT_TRUE(EQ(f, 18, LINE({0, 0, 0, 0, 0, 0, 0, 0, 0, 0})));
  EXPECT_TRUE(EQ(f, 19, LINE({0, 0, 0, 0, 0, 0, 0, 0, 1, 1})));

  EXPECT_UINT_EQ(f->height_col[8], 1);
  EXPECT_UINT_EQ(f->height_col[9], 1);
  EXPECT_UINT_EQ(f->block_line[18], 0);
  EXPECT_UINT_EQ(f->block_line[19], 2);

  rotation_put(f, TETRIMINO_I, 0, 0);
  rotation_put(f, TETRIMINO_I, 0, 4);

  EXPECT_TRUE(EQ(f, 18, LINE({0, 0, 0, 0, 0, 0, 0, 0, 0, 0})));
  EXPECT_TRUE(EQ(f, 19, LINE({0, 0, 0, 0, 0, 0, 0, 0, 0, 0})));
  EXPECT_UINT_EQ(f->height_col[8], 0);
  EXPECT_UINT_EQ(f->height_col[9], 0);
  EXPECT_UINT_EQ(f->block_line[18], 0);
  EXPECT_UINT_EQ(f->block_line[19], 0);

  free(f);
  return true;
}

TEST_F(line_clear_with_hole)
{
  struct field *f = field_new();

  SET(f, 18, LINE({0, 0, 1, 1, 1, 1, 1, 1, 1, 1}));
  SET(f, 19, LINE({0, 1, 1, 1, 1, 1, 1, 1, 1, 0}));

  rotation_put(f, TETRIMINO_S, 0, 0);

  EXPECT_UINT_EQ(f->height_col[0], 0);
  EXPECT_UINT_EQ(f->height_col[1], 2);
  EXPECT_UINT_EQ(f->height_col[2], 2);
  EXPECT_UINT_EQ(f->height_col[3], 1);
  EXPECT_UINT_EQ(f->height_col[4], 1);
  EXPECT_UINT_EQ(f->height_col[5], 1);
  EXPECT_UINT_EQ(f->height_col[6], 1);
  EXPECT_UINT_EQ(f->height_col[7], 1);
  EXPECT_UINT_EQ(f->height_col[8], 1);
  EXPECT_UINT_EQ(f->height_col[9], 0);

  free(f);
  return true;
}

const static struct test field_tests[] = {
  TEST(line_get),
  TEST(line_get_well),
  TEST(rotation_put_1),
  TEST(rotation_put_2),
  TEST(line_clear),
  TEST(line_clear_with_hole),
};

TEST_SUITE(field);
