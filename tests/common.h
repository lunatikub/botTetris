#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>

#include "field.h"

/**
 * Set a line of a field.
 *
 * @param field allocated from @c field_new.
 * @param y the number of the line to be set.
 * @param line values to set.
 * @param sz number of element in the line.
 */
void set_line(struct field *field, uint8_t y, uint8_t *line, uint8_t sz);

/**
 * Helper to set a line.
 */
#define LINE(...) __VA_ARGS__
#define SET(FIELD, Y, LINE)                             \
  ({                                                    \
    uint8_t L[] = LINE;                                 \
    set_line(FIELD, Y, L, sizeof(L) / sizeof(uint8_t)); \
  })

#endif /* !COMMON_H__ */
