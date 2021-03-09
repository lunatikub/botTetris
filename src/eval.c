#include "eval.h"

int eval_erosion(const struct field *f)
{
  return f->erosion;
}

int eval_hlt(const struct field *f)
{
  return f->hlt;
}

static inline
bool is_delta(const struct field *f,
              uint8_t y1, uint8_t x1,
              uint8_t y2, uint8_t x2)
{
  return
    (f->blocks[y1][x1] == 0 && f->blocks[y2][x2] != 0) ||
    (f->blocks[y1][x1] != 0 && f->blocks[y2][x2] == 0);
}

int eval_delta_l(const struct field *f)
{
  int dr = 0;
  for (uint8_t y = 0; y < FIELD_HEIGHT; ++y) {
    for (uint8_t x = 0; x < FIELD_WIDTH - 1; ++x) {
      if (is_delta(f, y, x, y, x + 1)) {
        ++dr;
      }
    }
  }
  return dr;
}

int eval_delta_c(const struct field *f)
{
  int dc = 0;
  for (uint8_t x = 0; x < FIELD_WIDTH; ++x) {
    for (uint8_t y = 0; y < FIELD_HEIGHT - 1; ++y) {
      if (is_delta(f, y, x, y + 1, x)) {
        ++dc;
      }
    }
  }
  return dc;
}

int eval_holes(const struct field *f)
{
  int ho = 0;

  for (uint8_t x = 0; x < FIELD_WIDTH; ++x) {
    for (uint8_t y = FIELD_HEIGHT - f->height_col[x] + 1; y < FIELD_HEIGHT; ++y) {
      ho += (f->blocks[y][x] == 0);
    }
  }
  return ho;
}
