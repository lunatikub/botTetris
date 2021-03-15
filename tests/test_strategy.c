#include "strategy.h"
#include "common.h"
#include "test.h"

TEST_F(dellacherie)
{
  struct field *f1 = field_new();
  struct field *f2 = field_new();

  /**
   * XX XXX XXX
   * XXX X XX X
   */
  SET(f1, 18, LINE({1, 1, 0, 1, 1, 1, 0, 1, 1, 1 }));
  SET(f1, 17, LINE({1, 1, 1, 0, 1, 0, 1, 1, 0, 1 }));

  /**
   * XX XXX XXX
   * XXXXXX XXX
   */
  SET(f2, 18, LINE({1, 1, 0, 1, 1, 1, 0, 1, 1, 1 }));
  SET(f2, 17, LINE({1, 1, 1, 1, 1, 1, 0, 1, 1, 1 }));

  EXPECT_INT_GT(score_get(f2, DELLACHERIE),
                score_get(f1, DELLACHERIE));

  free(f1);
  free(f2);
  return true;
}

const static struct test strategy_tests[] = {
  TEST(dellacherie),
};

TEST_SUITE(strategy);
