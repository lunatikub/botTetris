#include "tetrimino.h"
#include "common.h"
#include "test.h"

#define HEIGHT 20
#define WIDTH  10

TEST_F(get_line)
{
  struct field *f = field_new(HEIGHT, WIDTH);

  SET(f, 18, LINE({0, 1, 0}));
  SET(f, 19, LINE({1, 1, 1}));

  const struct rotation *r = rotation_get(TETRIMINO_J, 1);

  EXPECT_EQ(get_line(f, r, 0), 18);
  EXPECT_EQ(get_line(f, r, 1), 18);
  EXPECT_EQ(get_line(f, r, 2), 19);
  EXPECT_EQ(get_line(f, r, 3), 20);

  r = rotation_get(TETRIMINO_T, 2);

  EXPECT_EQ(get_line(f, r, 0), 18);
  EXPECT_EQ(get_line(f, r, 1), 19);
  EXPECT_EQ(get_line(f, r, 2), 20);

  field_destroy(f);
  return true;
}

TEST_F(get_line_well)
{
  struct field *f = field_new(HEIGHT, WIDTH);

  SET(f, 16, LINE({1, 0, 1}));
  SET(f, 17, LINE({1, 0, 1}));
  SET(f, 18, LINE({1, 0, 1}));
  SET(f, 19, LINE({1, 0, 1}));

  const struct rotation *r = rotation_get(TETRIMINO_I, 1);

  EXPECT_EQ(get_line(f, r, 0), 16);
  EXPECT_EQ(get_line(f, r, 1), 20);
  EXPECT_EQ(get_line(f, r, 2), 16);

  field_destroy(f);
  return true;
}

const static struct test field_tests[] = {
  TEST(get_line),
  TEST(get_line_well),
};

TEST_SUITE(field);
