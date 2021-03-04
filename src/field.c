#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "field.h"

#define ALLOC(SZ)                               \
  ({                                            \
    void *ptr = calloc(1, SZ);                  \
    assert(ptr != NULL);                        \
    ptr;                                        \
  })

struct field* field_new(uint8_t height, uint8_t width)
{
  struct field *f = ALLOC(sizeof(*f));

  f->blocks = ALLOC(sizeof(uint8_t*) * height);
  for (uint8_t i = 0; i < height; ++i) {
    f->blocks[i] = ALLOC(sizeof(uint8_t) * width);
  }
  f->height_col = ALLOC(sizeof(uint8_t) * width);
  f->block_line = ALLOC(sizeof(uint8_t) * height);
  f->height = height;
  f->width = width;

  return f;
}

void field_destroy(struct field *f)
{
  free(f->block_line);
  free(f->height_col);
  for (uint8_t i = 0; i < f->height; ++i) {
    free(f->blocks[i]);
  }
  free(f->blocks);
  free(f);
}

struct field* field_duplicate(const struct field *dup)
{
  struct field *f = field_new(dup->height, dup->width);

  for (uint8_t y = 0; y < f->height; ++y) {
    for (uint8_t x = 0; x < f->width; ++x) {
      f->blocks[y][x] = dup->blocks[y][x];
    }
  }
  memcpy(f->height_col, dup->height_col, f->width * sizeof(uint8_t));
  memcpy(f->block_line, dup->block_line, f->height * sizeof(uint8_t));

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
  return f->height - y;
}

static inline bool field_update(struct field *f,uint8_t x, uint8_t y)
{
  /* Update the `height_col`. */
  if (f->height - y > f->height_col[x]) {
    f->height_col[x] = f->height - y;
  }

  /* Update the `block_line`. */
  ++f->block_line[y];
  /* Clear completed line */
  if (f->block_line[y] == f->width) {
    /* TODO */
    return true;
  }
  return false;
}

bool rotation_put(struct field *f, enum type type, uint8_t rotation, uint8_t x)
{
  uint8_t nr_completed_line = 0;
  uint8_t nr_completed_block = 0;
  const struct rotation *r = rotation_get(type, rotation);

  /* Out of bounds. */
    if (x + r->width > f->width) {
    return false;
  }

  uint8_t y = line_get(f, r, x);

  for (uint8_t i = 0; i < r->height; ++i) {
    uint8_t k = i + y - r->height;
    for (uint8_t j = 0; j < r->width; ++j) {
      if (r->blocks[i][j]) {
        f->blocks[k][j + x] = type;
        if (field_update(f, j + x, k)) {
          ++nr_completed_line;
          nr_completed_block += r->block_line[i];
        }
      }
    }
  }

  return true;
}
