#include "common.h"

void set_line(struct field *field, uint8_t y, uint8_t *line, uint8_t sz)
{
  /* Copy the line. */
  for (uint8_t x = 0; x < sz; ++x) {
    field->blocks[y][x] = line[x];
  }

  /* Update the `col` field. */
  uint8_t nr_block = 0;
  for (uint8_t x = 0; x < sz; ++x) {
    uint8_t height = field->height - y;
    if (field->blocks[y][x]) {
      nr_block++;
      if (field->col[x] < height) {
        field->col[x] = height;
      }
    }
  }

  /* Update the `line` field. */
  field->line[y] = nr_block;
}
