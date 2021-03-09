#ifndef __FIELD__
#define __FIELD__

#include <stdint.h>

#include "tetrimino.h"

#define FIELD_HEIGHT 20
#define FIELD_WIDTH  10

struct field {
  uint8_t blocks[FIELD_HEIGHT][FIELD_WIDTH];
  uint8_t height_col[FIELD_WIDTH]; /* Height of each column. */
  uint8_t block_line[FIELD_HEIGHT]; /* Number of blocks filled by line. */
  int erosion;
  int hlt; /* Height of the last tetrimino placed. */
};

/**
 * Create and allocate a new field.
 *
 * @return the field allocated.
 * @warning has to be freed.
 */
struct field* field_new(void);

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
uint8_t line_get(const struct field *f, const struct rotation *r, uint8_t x);

/**
 * Put a tetrimino rotation on a field.
 *
 * @param f Field previously allocated with @c field_new.
 * @param type Tetrimino type.
 * @param rotation Rotation of the tetrimino.
 * @param x Coordinate to put the rotation.
 * @return false if the put is out of bounds, otherwise return true.
 */
bool rotation_put(struct field *f, enum type type, uint8_t rotation, uint8_t x);

#endif /* !__FIELD__ */
