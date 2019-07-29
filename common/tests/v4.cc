
#include <CUnit/Basic.h>
#include <iostream>
#include <cstdlib>


#include "../common.hpp"
#include "../versionInfo-c++.h" 


static std::string  rootDir;

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
	octetos::toolkit::Version ver;
	
        //valores iniciales
        //std::cout << "Valores inicilaes .." << std::endl;
	CU_ASSERT(ver.getMajor() == -1)
	CU_ASSERT(ver.getMinor() == -1)
	CU_ASSERT(ver.getPatch() == -1)	
        CU_ASSERT(ver.getStage() == octetos::toolkit::Version::unknown)
        CU_ASSERT(ver.getBuild() == 0);
        CU_ASSERT(ver.getName().size() == 0);
        
        
        //reading file
        //std::cout << "Probando el parser .." << std::endl;
        octetos::toolkit::Version ver2;
        ver2.fromFile("../tests/ver");
        std::cout << "Read version for testing .." << ver2.toString() << std::endl;
        //CU_ASSERT(drv.parseFile( rootDir + "/tests/ver") == 0);
        CU_ASSERT(ver2.getMajor() == 12);
        CU_ASSERT(ver2.getMinor() == 36);
        CU_ASSERT(ver2.getPatch() == 56);
        CU_ASSERT(ver2.getStage() == octetos::toolkit::Version::snapshot);
        CU_ASSERT(ver2.getBuild() == 1234567890123);
        CU_ASSERT(ver2.getName().compare("devtest") == 0);
}

/*void testRQ0001001()
{	
	toolkit::Version ver = toolkit::getVersion();
	std::string strMessge = "Valid RQ 0001-001..";
	CU_ASSERT(ver.getMajor() > -1)
}*/


int main(int argc, char *argv[])
{
        if(argc > 1)
        {
                rootDir = argv[1];
        }
        else
        {
                std::cerr << "Indique el directorio root.";
                return EXIT_FAILURE;
        }
	CU_pSuite pSuite = NULL;
	
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	octetos::toolkit::Version ver = octetos::toolkit::getPakageVersion();
        std::string pkName = octetos::toolkit::getPakageName();
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
