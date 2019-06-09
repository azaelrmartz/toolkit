
#include <CUnit/Basic.h>
#include <iostream>


#include "../common.hpp"
#include "../versionInfo.h" 
#include "../parserVersion-C++/driver.hh"

/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;

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


void testVersionGeneric()
{
	//for class Version
	toolkit::Version ver;
	
        //valores iniciales
        //std::cout << "Valores inicilaes .." << std::endl;
	CU_ASSERT(ver.getMajor() == -1)
	CU_ASSERT(ver.getMinor() == -1)
	CU_ASSERT(ver.getPatch() == -1)
	
	CU_ASSERT(ver.getStage() == toolkit::Version::unknown)
        
        
        //reading file
        //std::cout << "Probando el parser .." << std::endl;
        driver drv(ver);
        CU_ASSERT(drv.parse ("../tests/ver") == 0);	
}

/*void testRQ0001001()
{	
	toolkit::Version ver = toolkit::getVersion();
	std::string strMessge = "Valid RQ 0001-001..";
	CU_ASSERT(ver.getMajor() > -1)
}*/


int main()
{
	CU_pSuite pSuite = NULL;
	
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	toolkit::Version ver = toolkit::getPakageVersion();
        std::string pkName = toolkit::getPakageName();
	std::string classVersionString = std::string("Probando ") + pkName + " " + ver.toString();
	pSuite = CU_add_suite(classVersionString.c_str(), init_toolkit_common, clean_toolkit_common);
	if (NULL == pSuite) 
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	if ((NULL == CU_add_test(pSuite, "Pruebas Genericas.", testVersionGeneric)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	/*std::string classMessage = "Messages class.";
	if ((NULL == CU_add_test(pSuite, classMessage.c_str(), testRQ0001001)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}*/
	
	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();	
}
