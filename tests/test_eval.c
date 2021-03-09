#include "eval.h"
#include "common.h"
#include "test.h"

/* static void dump(struct field *field) */
/* { */
/*   printf("|-------------------------------------|\n"); */
/*   for (uint8_t y = 0; y < FIELD_HEIGHT; y++) { */
/*     printf("(%2u) ", y); */
/*     for (uint8_t x = 0; x < FIELD_WIDTH; x++) { */
/*       printf("%2u ", field->blocks[y][x]); */
/*     } */
/*     printf(" [%u]\n", field->block_line[y]); */
/*   } */
/*   printf("\n     "); */
/*   for (uint8_t x = 0; x < FIELD_WIDTH; x++) { */
/*     printf("%2u ", field->height_col[x]); */
/*   } */
/*   printf(" (col_height)\n"); */
/*   printf("|-------------------------------------|\n\n"); */
/* } */

TEST_F(delta_r)
{
  struct field *f = field_new();

  SET(f, 18, LINE({0, 0, 1, 2, 3, 0, 4, 0, 5, 0}));
  SET(f, 19, LINE({0, 6, 0, 7, 0, 8, 0, 9, 0, 1}));
  EXPECT_UINT_EQ(eval_delta_r(f), 15);

  free(f);
  return true;
}

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

const static struct test eval_tests[] = {
  TEST(delta_r),
  TEST(erosion),
};

TEST_SUITE(eval);
