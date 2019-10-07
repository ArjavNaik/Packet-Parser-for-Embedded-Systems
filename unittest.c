#include "../inc/main.h"
#include "CUnit/Basic.h"

/* initiating suite */
int init_suite1(void)
{
	return 0;
}

/* cleaning suite */
int clean_suite1(void)
{
	return 0;
}

/* serializer tests */
void test_serializer()
{
	packet.SRC_ADDR = 1; packet.DST_ADDR = 2; packet.KEY = 3; packet.VALUE = 4;
	CU_ASSERT_EQUAL(serialize(&packet), EXIT_SUCCESS);	//pass

	packet.SRC_ADDR = 4660; packet.DST_ADDR = 17185; packet.KEY = 55; packet.VALUE = -5439;
	CU_ASSERT_EQUAL(serialize(&packet), EXIT_SUCCESS);	//pass

	packet.SRC_ADDR = 374; packet.DST_ADDR = 596; packet.KEY = 265; packet.VALUE = 8401;
	CU_ASSERT_EQUAL(serialize(&packet), EXIT_SUCCESS);	//pass
}

/* deserializer tests */
void test_deserializer()
{
	uint8_t packet_buff_1[] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 4};
	CU_ASSERT_EQUAL(deserialize(packet_buff_1), EXIT_SUCCESS);	//pass

	uint8_t packet_buff_2[] = {0, 0, 0, 0, 0, 0, 18, 52, 0, 0, 0, 0, 0, 0, 67, 33, 0, 0, 0, 55, 255, 255, 234, 193};
	CU_ASSERT_EQUAL(deserialize(packet_buff_2), EXIT_SUCCESS);	//pass

	uint8_t packet_buff_3[] = {0, 0, 0, 0, 0, 0, 1, 118, 0, 0, 0, 0, 0, 0, 2, 84, 0, 0, 1, 9, 0, 0, 32, 209};
	CU_ASSERT_EQUAL(deserialize(packet_buff_3), EXIT_SUCCESS);	//pass
}

int main()
{
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* add a suite to the registry */
	pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* add the tests to the suite */
	if ((NULL == CU_add_test(pSuite, "test of serializer", test_serializer)))
  	{
		CU_cleanup_registry();
 		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite, "test of deserializer", test_deserializer)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
