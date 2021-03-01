#ifndef __TEST_H__
#define __TEST_H__

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * Declare a test.
 */
#define TEST_F(name) static bool test_ ## name(void)

/**
 * Add a test to the test suite.
 */
#define TEST(name) { #name, test_ ## name }

/**
 * Structure used to declare a test.
 * Use helper @c TEST.
 */
struct test {
  char *name;
  bool (*test_f)(void);
};

/**
 * Structure used to declare a test suite.
 * Use helper @c TEST_SUITE.
 */
struct test_suite {
  char *name;
  uint32_t nr_test;
  const struct test *tests;
};

/**
 * Run a specific test.
 */
bool run_test(const struct test *t);

/**
 * Find a specific test in a test suite from the name.
 * Return NULL if not found.
 */
const struct test* find_test(const struct test_suite *ts, const char *name);

/**
 * Run a test suite.
 */
bool run_test_suite(const struct test_suite *ts);

/**
 * Declare a test suite.
 */
#define TEST_SUITE(name)                                                \
  const static struct test_suite name ## _test_suite = {                \
    #name,                                                              \
    sizeof(name ## _tests) / sizeof(struct test),                       \
    name ## _tests,                                                     \
  };                                                                    \
                                                                        \
  int main(int argc, char **argv)                                       \
  {                                                                     \
    if (argc == 2) {                                                    \
      char *name = NULL;                                                \
      name = argv[1];                                                   \
      const struct test *t = find_test(&name ## _test_suite, name);     \
      if (t == NULL) {                                                  \
        fprintf(stderr, "Test `%s` not found...", name);                \
        return -1;                                                      \
      }                                                                 \
      return run_test(t) ? 0 : -1;                                      \
    }                                                                   \
    return run_test_suite(&name ## _test_suite) ? 0 : -1;               \
  }

/**
 * Following macro are helpers to be used in the tests.
 */

#define ERR                                                             \
  fprintf(stderr, "[test failed] file:%s, line:%i\n", __FILE__, __LINE__)

#define EXPECT_EQ(v1, v2)                       \
  if (v1 != v2)  { ERR; return false; }

#define EXPECT_NE(v1, v2)                       \
  if (v1 == v2) { ERR; return false; }

#define EXPECT_STREQ(str1, str2)                                \
  if (strlen(str1) != strlen(str2) ||                           \
      (strcmp((str1), (str2)) != 0)) { ERR; return false; }

#define EXPECT_TRUE(exp)                        \
  if ((exp) != true) { ERR; return false; }

#endif /* !TEST_H__ */
