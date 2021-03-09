#include "eval.h"

int eval_delta_r(const struct field *f)
{
  int dr = 0;
  for (uint8_t y = 0; y < FIELD_HEIGHT; ++y) {
    for (uint8_t x = 0; x < FIELD_WIDTH - 1; ++x) {
      if ((f->blocks[y][x] == 0 && f->blocks[y][x + 1] != 0) ||
          (f->blocks[y][x] != 0 && f->blocks[y][x + 1] == 0)) {
        ++dr;
      }
    }
  }
  return dr;
}

int eval_erosion(const struct field *f)
{
  return f->erosion;
}
