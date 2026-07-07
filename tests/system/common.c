#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

#include <unity.h>
#include <string.h>
#include <stdlib.h>


void setUp(void)
{

}

void tearDown(void)
{

}

void test_common(void)
{
	char *client = "test";
	TEST_ASSERT_NOT_NULL(client);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_common);
	return UNITY_END();
}
