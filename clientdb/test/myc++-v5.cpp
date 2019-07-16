
#include "../clientdb-mysql.hpp"
#include "CUnit/Basic.h"



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


void testConection()
{
        octetos::toolkit::clientdb::mysql::Datconnect mysqlSource("192.168.0.101",3306,"sysapp.alpha","develop","123456");         
        octetos::toolkit::clientdb::mysql::Connector connector;
        bool flag = connector.connect(&mysqlSource);
        CU_ASSERT(flag)    
}


int main()
{
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	//toolkit::Version ver = toolkit::clientdb::getPakageVersion();
	std::string classVersionString = "Testing Componete ";
	classVersionString += octetos::toolkit::clientdb::mysql::getPakageName();
	classVersionString += " v";
	classVersionString = classVersionString + octetos::toolkit::clientdb::mysql::getPakageVersion().toString();
	pSuite = CU_add_suite(classVersionString.c_str(), init_toolkit_common, clean_toolkit_common);
	if (NULL == pSuite) 
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	

	std::string classMessage = "Conector class.";
	if ((NULL == CU_add_test(pSuite, classMessage.c_str(), testConection)))
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
