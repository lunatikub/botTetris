#ifndef __STRATEGY__
#define __STRATEGY__

#include "eval.h"

/* https://hal.inria.fr/inria-00418922/document */
typedef enum {
  DELLACHERIE,
} strategy_t;

/**
 * Get the score of a field depending on a strategy.
 *
 * @param f Field to evaluate.
 * @param s Strategy to use.
 * @return the commputed score.
 */
int score_get(const struct field *f, strategy_t s);

#endif /* !__STRATEGY__ */
