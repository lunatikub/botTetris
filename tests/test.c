#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "test.h"

static inline uint64_t get_ns(void)
{
  struct timespec ts;
  if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
    abort();
  }
  return ts.tv_sec * UINT64_C(1000000000) + ts.tv_nsec;
}

const struct test* find_test(const struct test_suite *ts, const char *name)
{
  for (uint32_t i = 0; i < ts->nr_test; i++) {
    if (strcmp(ts->tests[i].name, name) == 0) {
      return &ts->tests[i];
    }
  }
  return NULL;
}

bool run_test(const struct test *t)
{
  const uint64_t start = get_ns();
  printf("- %s: ", t->name);
  if (t->test_f() != true) {
    printf("KO (%lums)\n", (get_ns() - start) / 1000);
    return false;
  }
  printf("OK (%lums)\n", (get_ns() - start) / 1000);
  return true;
}

bool run_test_suite(const struct test_suite *ts)
{
  const struct test *t;
  printf("[[[%s]]]\n", ts->name);
  for (t = &ts->tests[0]; t != &ts->tests[ts->nr_test]; ++t) {
    if (run_test(t) == false) {
      return false;
    }
  }
  return true;
}
