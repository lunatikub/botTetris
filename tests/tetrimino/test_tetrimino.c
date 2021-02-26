#include "tetrimino.h"
#include "test.h"

static inline bool test_block_line(const struct rotation *r)
{
  for (uint8_t i = 0; i < TETRIMINO_SZ; ++i) {
    uint8_t nr_block = 0;
    for (uint8_t j = 0; j < TETRIMINO_SZ; ++j) {
      if (r->blocks[i][j]) {
        ++nr_block;
      }
    }
    if (nr_block != r->block_line[i]) {
      return false;
    }
  }
  return true;
}

static inline bool test_height(const struct rotation *r)
{
  uint8_t h = 1;
  for (uint8_t i = 0; i < TETRIMINO_SZ; ++i) {
    for (uint8_t j = 0; j < TETRIMINO_SZ; ++j) {
      if (r->blocks[i][j]) {
        return TETRIMINO_SZ - i == r->height;
      }
    }
  }
  return h == r->height;
}

static inline bool test_tetrimino(enum tetrimino_type t)
{
  const struct tetrimino *tetrimino = tetrimino_get(t);

  for (uint8_t r = 0; r < tetrimino->nr_rotation; ++r) {
    const struct rotation *rotation= rotation_get(t, r);
    EXPECT_TRUE(test_block_line(rotation));
    EXPECT_TRUE(test_height(rotation));
  }
  return true;
}

TEST(tetrimino_I)
{
  return test_tetrimino(TETRIMINO_I);
}

static struct test tetrimino_tests[] = {
  ADD_TEST(tetrimino_I),
};

int main(void)
{
  return RUN_ALL_TESTS("tetrimino", tetrimino_tests);
}
