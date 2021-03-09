#ifndef __EVAL__
#define __EVAL__

#include "field.h"

/**
 * Processing the number of transitions between
 * filled/empty and empty/filled block for each line.
 * The goal is to have an homogeneous field.
 *
 * @param f Field previously allocated with @c field_new.
 * @return the delta computed.
 */
int eval_delta_r(const struct field *f);

/**
 * It is the number of lines completed multiply by
 * the number of blocks completed with the last placed rotation.
 * The goal is to encourage to complete lines.
 *
 * @param f Field previously allocated with @c field_new.
 * @return the erosion
 */
int eval_erosion(const struct field *f);

#endif /* !__EVAL__ */
