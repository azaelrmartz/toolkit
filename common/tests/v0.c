
#include <CUnit/Basic.h>
#include <stdio.h>


#include "driver.h"
//#include "../common.h"
#include "../version-reader/parser.tab.h"
#include "../versionInfo-c.h" 



/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_toolkit_common(void)
{
        return 0;
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_toolkit_common(void)
{
        return 0;
}

void versionreader()
{    
	struct Tray ty;
    parse_string(&ty,"1.0.55-alpha");
}


int main(int argc, char *argv[])
{
	CU_pSuite pSuite = NULL;
	
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	

	pSuite = CU_add_suite("Testing C component...\n", init_toolkit_common, clean_toolkit_common);
	if (NULL == pSuite) 
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
