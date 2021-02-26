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

bool run_all_tests(const char *name, const struct test *tests, size_t nr_test)
{
  const struct test *t;
  printf("[[[%s]]]\n", name);
  for (t = &tests[0]; t != &tests[nr_test]; ++t) {
    const uint64_t start = get_ns();
    printf("- %s: ", t->name);
    if (t->test_f() != true) {
      printf("KO (%lums)\n", (get_ns() - start) / 1000);
      return -1;
    }
    printf("OK (%lums)\n", (get_ns() - start) / 1000);
  }
  return 0;
}
