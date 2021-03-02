#include "tetrimino.h"
#include "common.h"
#include "test.h"

#define HEIGHT 20
#define WIDTH  10

static void dump(struct field *field)
{
  for (uint8_t y = 0; y < field->height; y++) {
    printf("(%2u) ", y);
    for (uint8_t x = 0; x < field->width; x++) {
      printf("%2u ", field->blocks[y][x]);
    }
    printf(" [%u]\n", field->line[y]);
  }
  printf("\n     ");
  for (uint8_t x = 0; x < field->width; x++) {
    printf("%2u ", field->col[x]);
  }
  printf("\n");
}

TEST_F(get_line)
{
  struct field *f = field_new(HEIGHT, WIDTH);

  SET(f, 18, LINE({0, 1, 0}));
  SET(f, 19, LINE({1, 1, 1}));

  dump(f);

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

const static struct test field_tests[] = {
  TEST(get_line),
};

TEST_SUITE(field);
