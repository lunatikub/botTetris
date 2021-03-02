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
  f->col = ALLOC(sizeof(uint8_t) * width);
  f->line = ALLOC(sizeof(uint8_t) * height);
  f->height = height;
  f->width = width;

  return f;
}

void field_destroy(struct field *f)
{
  free(f->line);
  free(f->col);
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
  memcpy(f->col, dup->col, f->width * sizeof(uint8_t));
  memcpy(f->line, dup->line, f->height * sizeof(uint8_t));

  return f;
}

uint8_t get_line(const struct field *f, const struct rotation *r, uint8_t x)
{
  uint8_t y = 0;
  for (uint8_t i = 0; i < r->width; ++i) {
    int8_t l = f->col[x + i] - r->holes[i];
    if (l > y && l > 0) {
      y = l;
    }
  }
  return f->height - y;
}
