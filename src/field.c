#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "field.h"

struct field* field_new(void)
{
  struct field *f = calloc(1, sizeof(*f));
  assert(f != NULL);
  return f;
}

/* void field_reset(struct field *f) */
/* { */
/*   for (uint8_t y = 0; y < FIELD_HEIGHT; ++y) { */
/*     for (uint8_t x = 0; x < FIELD_WIDTH; ++x) { */
/*       f->blocks[y][x] = 0; */
/*     } */
/*   } */
/*   for (uint8_t y = 0; y < FIELD_HEIGHT; ++y) { */
/*     f->block_line[y] = 0; */
/*   } */
/*   for (uint8_t x = 0; x < FIELD_WIDTH; ++x) { */
/*     f->height_col[x] = 0; */
/*   } */
/* } */

struct field* field_duplicate(const struct field *dup)
{
  struct field *f = calloc(1, sizeof(*f));
  assert(f != NULL);

  for (uint8_t y = 0; y < FIELD_HEIGHT; ++y) {
    for (uint8_t x = 0; x < FIELD_WIDTH; ++x) {
      f->blocks[y][x] = dup->blocks[y][x];
    }
  }
  memcpy(f->height_col, dup->height_col, FIELD_WIDTH * sizeof(uint8_t));
  memcpy(f->block_line, dup->block_line, FIELD_HEIGHT * sizeof(uint8_t));

  return f;
}

uint8_t line_get(const struct field *f, const struct rotation *r, uint8_t x)
{
  uint8_t y = 0;
  for (uint8_t i = 0; i < r->width; ++i) {
    int8_t l = f->height_col[x + i] - r->holes[i];
    if (l > y && l > 0) {
      y = l;
    }
  }
  return FIELD_HEIGHT - y;
}

static inline void line_clear(struct field *f, uint8_t y)
{
  const static uint8_t empty_line[FIELD_WIDTH] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0
  };

  for (uint8_t i = y; i > 0; --i) {
    memcpy(f->blocks[i], f->blocks[i - 1], FIELD_WIDTH * sizeof(uint8_t));
    f->block_line[i] = f->block_line[i - 1];
  }
  memcpy(f->blocks[0], empty_line, FIELD_WIDTH * sizeof(uint8_t));

  for (uint8_t i = 0; i < FIELD_WIDTH; ++i) {
    uint8_t j = 0;
    while (j != FIELD_HEIGHT && f->blocks[j][i] == 0) {
      ++j;
    }
    f->height_col[i] = FIELD_HEIGHT - j;
  }
}

static inline bool field_update(struct field *f,uint8_t x, uint8_t y)
{
  /* Update the `height_col`. */
  if (FIELD_HEIGHT - y > f->height_col[x]) {
    f->height_col[x] = FIELD_HEIGHT - y;
  }

  /* Update the `block_line`. */
  ++f->block_line[y];
  /* Clear completed line */
  if (f->block_line[y] == FIELD_WIDTH) {
    line_clear(f, y);
    return true;
  }
  return false;
}

bool rotation_put(struct field *f, tetrimino_t t, uint8_t rotation, uint8_t x)
{
  uint8_t nr_completed_line = 0;
  uint8_t nr_completed_block = 0;
  const struct rotation *r = rotation_get(t, rotation);

  /* Out of bounds. */
  if (x + r->width > FIELD_WIDTH) {
    return false;
  }

  uint8_t y = line_get(f, r, x);

  for (uint8_t i = 0; i < r->height; ++i) {
    uint8_t k = i + y - r->height;
    for (uint8_t j = 0; j < r->width; ++j) {
      if (r->blocks[i][j]) {
        f->blocks[k][j + x] = t;
        if (field_update(f, j + x, k)) {
          ++nr_completed_line;
          nr_completed_block += r->block_line[i];
        }
      }
    }
  }

  f->erosion = nr_completed_line * nr_completed_block;
  f->hlt = FIELD_HEIGHT - y + 1;

  return true;
}
