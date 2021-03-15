#include <assert.h>

#include "strategy.h"

struct eval {
  eval_f func;
  int weight;
};

struct strategy {
  uint32_t nr_eval;
  struct eval evals[];
};

const static struct strategy dellacherie = {
  6,
  {
    { eval_hlt, -1 },
    { eval_erosion, 1 },
    { eval_delta_l, -1 },
    { eval_delta_c, -1 },
    { eval_holes, -4 },
    { eval_wells, -1 },
  }
};

static inline const struct strategy* strategy_get(strategy_t s)
{
  switch (s) {
    case DELLACHERIE:
      return &dellacherie;
  };
  assert(!"strategy unknown...");
}

int score_get(const struct field *f, strategy_t strategy)
{
  const struct strategy *s = strategy_get(strategy);
  int score = 0;

  for (uint8_t i = 0; i < s->nr_eval; ++i) {
    const struct eval *e = &s->evals[i];
    score += e->func(f) * e->weight;
  }
  return score;
}
