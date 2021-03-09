#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <stdlib.h>

#include "field.h"

#define LINE(...) __VA_ARGS__

/**
 * Set a line of a field.
 *
 * @param field allocated from @c field_new.
 * @param y the number of the line to be set.
 * @param line values to set.
 * @param sz number of element in the line.
 */
void line_set(struct field *field, uint8_t y, uint8_t *line, uint8_t sz);

/**
 * Helper to set a line.
 */
#define SET(FIELD, Y, LINE)                             \
  ({                                                    \
    uint8_t L[] = LINE;                                 \
    line_set(FIELD, Y, L, sizeof(L) / sizeof(uint8_t)); \
  })

/**
 * Check if two lines are equals.
 *
 * @param field allocated from @c field_new.
 * @param y the number of the line to be check.
 * @param line values to check.
 * @param sz number of element in the line.
 * @return true if the lines are equals, otherwise return false.
 */
bool line_eq(struct field *f, uint8_t y, uint8_t *line, uint8_t sz);

/**
 * Helper to check equality of two lines.
 */
#define EQ(FIELD, Y, LINE)                              \
  ({                                                    \
    uint8_t L[] = LINE;                                 \
    line_eq(FIELD, Y, L, sizeof(L) / sizeof(uint8_t));  \
  })

#endif /* !COMMON_H__ */
