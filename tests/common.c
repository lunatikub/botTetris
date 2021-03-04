#include "common.h"

void line_set(struct field *field, uint8_t y, uint8_t *line, uint8_t sz)
{
  /* Copy the line. */
  for (uint8_t x = 0; x < sz; ++x) {
    field->blocks[y][x] = line[x];
  }

  /* Update the `col` field. */
  uint8_t nr_block = 0;
  for (uint8_t x = 0; x < sz; ++x) {
    uint8_t height = FIELD_HEIGHT - y;
    if (field->blocks[y][x]) {
      nr_block++;
      if (field->height_col[x] < height) {
        field->height_col[x] = height;
      }
    }
  }

  /* Update the `line` field. */
  field->block_line[y] = nr_block;
}

bool line_eq(struct field *f, uint8_t y, uint8_t *line, uint8_t sz)
{
  for (uint8_t x = 0; x < sz; x++) {
    /* XOR */
    if ((f->blocks[y][x] == 0) != (line[x] == 0)) {
      return false;
    }
  }
  return true;
}
