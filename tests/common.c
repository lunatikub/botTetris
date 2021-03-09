#include "common.h"

void line_set(struct field *f, uint8_t y, uint8_t *line, uint8_t sz)
{
  /* Copy the line. */
  for (uint8_t x = 0; x < sz; ++x) {
    f->blocks[y][x] = line[x];
  }

  /* Update the `height_col` field. */
  for (uint8_t i = 0; i < FIELD_WIDTH; ++i) {
    uint8_t j = 0;
    while (j != FIELD_HEIGHT && f->blocks[j][i] == 0) {
      ++j;
    }
    f->height_col[i] = FIELD_HEIGHT - j;
  }

  /* Update the `block_line` field. */
  for (uint8_t i = 0; i < FIELD_HEIGHT; ++i) {
    uint8_t nr_block = 0;
    for (uint8_t j = 0; j < FIELD_WIDTH; ++j) {
      nr_block += (f->blocks[i][j] != 0);
    }
    f->block_line[i] = nr_block;
  }
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

void dump(struct field *field)
{
  printf("|-------------------------------------|\n");
  for (uint8_t y = 0; y < FIELD_HEIGHT; y++) {
    printf("(%2u) ", y);
    for (uint8_t x = 0; x < FIELD_WIDTH; x++) {
      printf("%2u ", field->blocks[y][x]);
    }
    printf(" [%u]\n", field->block_line[y]);
  }
  printf("\n     ");
  for (uint8_t x = 0; x < FIELD_WIDTH; x++) {
    printf("%2u ", field->height_col[x]);
  }
  printf(" (col_height)\n");
  printf("|-------------------------------------|\n\n");
}
