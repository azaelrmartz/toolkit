
#include "common.hpp"
#include "config.h" 

#include <CUnit/Basic.h>



/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_toolkit_common(void)
{
   if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
      return -1;
   }
   else {
      return 0;
   }
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_toolkit_common(void)
{
   if (0 != fclose(temp_file)) {
      return -1;
   }
   else {
      temp_file = NULL;
      return 0;
   }
}


void testVersion()
{
	//for class Version
	toolkit::Version ver = toolkit::getVersion();
	
	CU_ASSERT(ver.major > -1)
	CU_ASSERT(ver.minor > -1)
	CU_ASSERT(ver.patch > -1)
	
	CU_ASSERT(MAJOR == ver.major)
	CU_ASSERT(MINOR == ver.major)
	CU_ASSERT(PATCH == ver.major)
	
	
}

void testRQ0001001()
{	
	toolkit::Version ver = toolkit::getVersion();
	std::string strMessge = "Valid RQ 0001-001..";
	CU_ASSERT(ver.major > -1)
}


int main()
{
	CU_pSuite pSuite = NULL;
	
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	toolkit::Version ver = toolkit::getVersion();
	std::string classVersionString = "Testing Componete toolkit-common v";
	classVersionString = classVersionString + ver.toString();
	pSuite = CU_add_suite(classVersionString.c_str(), init_toolkit_common, clean_toolkit_common);
	if (NULL == pSuite) 
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	

	if ((NULL == CU_add_test(pSuite, "Version class.", testVersion)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	std::string classMessage = "Messages class.";
	if ((NULL == CU_add_test(pSuite, classMessage.c_str(), testRQ0001001)))
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
