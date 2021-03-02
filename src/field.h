#ifndef __FIELD__
#define __FIELD__

#include <stdint.h>

#include "tetrimino.h"

struct field {
  uint8_t **blocks;
  uint8_t *col; /* height by column. */
  uint8_t *line; /* number of blocks filled by line. */
  uint8_t height;
  uint8_t width;
};

/**
 * Create and allocate a new field from dims.
 *
 * @param height Height of the field.
 * @param width Width of the field.
 *
 * @return the field allocated.
 */
struct field* field_new(uint8_t height, uint8_t width);

/**
 * Destroy and free a field previously allocated with @c field_new.
 *
 * @param f Field to be freed.
 */
void field_destroy(struct field *f);

/**
 * Duplicate a field.
 *
 * @param f Field to be duplicaed.
 * @return the field duplicated.
 */
struct field* field_duplicate(const struct field *f);

/**
 * Get the line where to put a tetrimino rotation.
 *
 * @param f Field previously allocated with @c field_new.
 * @param r Rotation of the tetrimino.
 * @param x Coordinate to put the rotation.
 * @return return the line number where to put the rotation.
 */
uint8_t get_line(const struct field *f, const struct rotation *r, uint8_t x);

#endif /* !__FIELD__ */
