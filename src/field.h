#ifndef __FIELD__
#define __FIELD__

#include <stdint.h>

struct field {
  uint8_t **blocks;
  uint8_t *col; /* height by column. */
  uint8_t *line; /* number of blocks filled by line. */
  uint8_t height;
  uint8_t width;
};

/**
 * Create and allocate a new field from dims.
 */
struct field* field_new(uint8_t height, uint8_t width);

/**
 * Destroy and free a field previously allocated with @c field_new.
 */
void field_destroy(struct field *field);

/**
 * Duplicate a field.
 */
struct field* field_duplicate(const struct field *field);

#endif /* !__FIELD__ */
