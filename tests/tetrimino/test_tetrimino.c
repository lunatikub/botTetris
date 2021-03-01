#include "tetrimino.h"
#include "test.h"

static inline bool test_height(const struct rotation *r)
{
  uint8_t h = 0;
  for (uint8_t x = 0; x < TETRIMINO_SZ; ++x) {
    for (uint8_t y = 0; y < TETRIMINO_SZ; y++) {
      if (r->blocks[y][x] && y + 1 > h) {
        h = y + 1;
      }
    }
  }
  return h == r->height;
}

static inline bool test_width(const struct rotation *r)
{
  uint8_t w = 0;
  for (int8_t y = 0; y < TETRIMINO_SZ; ++y) {
    for (uint8_t x = 0; x < TETRIMINO_SZ; ++x) {
      if (r->blocks[y][x] && x + 1 > w) {
        w = x + 1;
      }
    }
  }
  return w == r->width;
}

static inline bool test_block_line(const struct rotation *r)
{
  for (uint8_t y = 0; y < r->height; ++y) {
    uint8_t nr_block = 0;
    for (uint8_t x = 0; x < r->width; ++x) {
      if (r->blocks[y][x]) {
        ++nr_block;
      }
    }
    if (nr_block != r->block_line[y]) {
      return false;
    }
  }
  return true;
}

static inline bool test_height_col(const struct rotation *r)
{
  for (uint8_t x = 0; x < r->width; ++x) {
    uint8_t h = 0;
    for (uint8_t y = 0; y < r->height; ++y) {
      if (r->blocks[y][x]) {
        h = r->height - y;
        break;
      }
    }
    if (h != r->height_col[x]) {
      return false;
    }
  }
  return true;

}

static inline bool test_tetrimino(enum tetrimino_type t)
{
  const struct tetrimino *tetrimino = tetrimino_get(t);

  for (uint8_t r = 0; r < tetrimino->nr_rotation; ++r) {
    const struct rotation *rotation= rotation_get(t, r);
    INFO("rotation %u", r);
    EXPECT_TRUE(test_height(rotation));
    EXPECT_TRUE(test_width(rotation));
    EXPECT_TRUE(test_block_line(rotation));
    EXPECT_TRUE(test_height_col(rotation));
  }
  return true;
}

TEST_F(tetrimino_I)
{
  return test_tetrimino(TETRIMINO_I);
}

TEST_F(tetrimino_J)
{
  return test_tetrimino(TETRIMINO_J);
}

const static struct test tetrimino_tests[] = {
  TEST(tetrimino_I),
  TEST(tetrimino_J),
};

TEST_SUITE(tetrimino);
