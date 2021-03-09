#ifndef __EVAL__
#define __EVAL__

#include "field.h"

/**
 * It is the number of lines completed multiply by
 * the number of blocks completed with the last placed rotation.
 * The goal is to encourage to complete lines.
 *
 * @param f Field previously allocated with @c field_new.
 * @return the erosion
 */
int eval_erosion(const struct field *f);

/**
 * It is the height of the last tetrimino has been placed on
 * the field. The goal is to prevent the field from being too high.
 *
 * @param f Field previously allocated with @c field_new.
 * @return the height of the last tetrimino placed.
 */
int eval_hlt(const struct field *f);

/**
 * Compute the number of transitions between filled/empty
 * and empty/filled block for each line.
 * The goal is to have an homogeneous field.
 *
 * @param f Field previously allocated with @c field_new.
 * @return the delta computed.
 */
int eval_delta_l(const struct field *f);

/**
 * Compute the number of transitions between filled/empty
 * and empty/filled block for each column.
 * The goal is to have an homogeneous field.
 *
 * @param f Field previously allocated with @c field_new.
 * @return the delta computed.
 */
int eval_delta_c(const struct field *f);

/**
 * Compute the number of empty blocks covered by
 * at least one filled block.
 * The goal is to prevent making holes.
 *
 * @param f Field previously allocated with @c field_new.
 * @return the number of holes
 */
int eval_holes(const struct field *f);

#endif /* !__EVAL__ */
