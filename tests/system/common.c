#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

#include <unity.h>
#include <string.h>
#include <stdlib.h>

#include <sample/common.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_common_basic(void)
{
	TEST_ASSERT_EQUAL_INT(5, sum(2, 3));
	TEST_ASSERT_NOT_EQUAL_INT(6, sum(2, 3));
}

void test_common_negative(void)
{
	TEST_ASSERT_EQUAL_INT(-1, sum(2, -3));
	TEST_ASSERT_EQUAL_INT(-5, sum(-2, -3));
}

void test_common_zero(void)
{
	TEST_ASSERT_EQUAL_INT(2, sum(2, 0));
	TEST_ASSERT_EQUAL_INT(0, sum(0, 0));
}

void test_common_large_values(void)
{
	// Behavior depends on int overflow, but we can still test expected wrap-around
	int a = 2000000000;
	int b = 1000000000;
	int result = sum(a, b);

	// Just check that the function returns *something* consistent with C integer overflow
	TEST_ASSERT_EQUAL_INT(a + b, result);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_common_basic);
	RUN_TEST(test_common_negative);
	RUN_TEST(test_common_zero);
	RUN_TEST(test_common_large_values);
	return UNITY_END();
}
