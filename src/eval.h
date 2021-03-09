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

#endif /* !__EVAL__ */
