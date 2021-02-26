#ifndef __TEST_H__
#define __TEST_H__

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * Declare a test.
 */
#define TEST(name) static bool test_ ## name(void)

/**
 * Add a test to the test suite.
 */
#define ADD_TEST(name) { #name, test_ ## name }

#define ERR fprintf(stderr, "[test failed] file:%s, line:%i\n", __FILE__, __LINE__)

#define EXPECT_EQ(v1, v2) \
  if (v1 != v2)  { ERR; return false; }

#define EXPECT_NE(v1, v2) \
  if (v1 == v2) { ERR; return false; }

#define EXPECT_STREQ(str1, str2)                                \
  if (strlen(str1) != strlen(str2) ||                           \
      (strcmp((str1), (str2)) != 0)) { ERR; return false; }

#define EXPECT_TRUE(exp) \
  if ((exp) != true) { ERR; return false; }

struct test {
  char *name;
  bool (*test_f)(void);
};

 #define RUN_ALL_TESTS(N, T)                     \
  run_all_tests(N, T,                           \
                sizeof(T) /                     \
                sizeof(struct test));           \

bool run_all_tests(const char *name, const struct test *tests, size_t nr_test);

#endif /* !TEST_H__ */
