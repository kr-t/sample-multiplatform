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

void test_common(void)
{
	TEST_ASSERT_EQUAL_INT(5, sum(2, 3));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_common);
	return UNITY_END();
}
