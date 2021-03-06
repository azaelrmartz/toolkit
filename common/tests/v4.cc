
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

void testComparators()
{
        octetos::toolkit::Version ver1;
        octetos::toolkit::Version ver2;
        
        ver1.setNumbers(1,2,3);
        ver2.setNumbers(1,2,5);
        //std::cout << "test 1" << std::endl;
        if(ver1 >= ver2)
        {
                CU_ASSERT(false);
        }
        else
        {
                CU_ASSERT(true);
        }
        //std::cout << "test 2" << std::endl;
        if(ver2 >= ver1)
        {
                CU_ASSERT(true);
        }
        else
        {
                CU_ASSERT(false);
        }
                
        ver1.setNumbers(1,2,3);
        ver2.setNumbers(1,2,3);
        //std::cout << "test 3" << std::endl;
        if(ver1 >= ver2)
        {
                CU_ASSERT(true);
        }
        else
        {
                CU_ASSERT(false);
        }
        //std::cout << "test 4" << std::endl;
        if(ver2 >= ver1)
        {
                CU_ASSERT(true);
        }
        else
        {
                CU_ASSERT(false);
        }
        
        //La nueva politca dicta que build no tiene significado en la presendiencia de las version pero sera removido hasta v5 paramantener compatibilidad 
        ver1.setNumbers(1,2,3);
        ver2.setNumbers(1,0,3);
        //std::cout << "test 3" << std::endl;
        if(ver1 >= ver2)
        {
                CU_ASSERT(true);
        }
        else
        {
                CU_ASSERT(false);
        }
        //std::cout << "test 4" << std::endl;
        if(ver2 >= ver1)
        {
                CU_ASSERT(false);
        }
        else
        {
                CU_ASSERT(true);
        }
        
        //ver1.setNumbers(-1,-1,-1);
        //ver2.setNumbers(-1,-1,-1);
        ver1.setBuild(12345678901234);
        ver2.setBuild(12345678901236);
        //std::cout << "test 5" << std::endl;
        if(ver1 >= ver2)
        {
                CU_ASSERT(true);
        }
        //std::cout << "test 6" << std::endl;
        if(ver2 >= ver1)
        {
                CU_ASSERT(true);
        }
        else
        {
                CU_ASSERT(false);
        }
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
        CU_ASSERT(ver2.fromFile("../tests/ver"));
        std::cout << "Parsed : " << ver2.toString() << std::endl;
        //std::cout << "Read version for testing .." << ver2.toString() << std::endl;
        //CU_ASSERT(drv.parseFile( rootDir + "/tests/ver") == 0);
        CU_ASSERT(ver2.getMajor() == 12);
        CU_ASSERT(ver2.getMinor() == 36);
        CU_ASSERT(ver2.getPatch() == 56);
        CU_ASSERT(ver2.getStage() == octetos::toolkit::Version::snapshot);
        CU_ASSERT(ver2.getBuild() == 12345678901233);
        CU_ASSERT(ver2.getName().compare("devtest") == 0);
        
        /*std::cout <<  "NOTADDRESSED " << octetos::toolkit::Error::Codes::NOTADDRESSED << std::endl;
        std::cout <<  "FAILONCONTRUCTOR " << octetos::toolkit::Error::Codes::FAILONCONTRUCTOR << std::endl;
        std::cout <<  "ROOFCODE " << octetos::toolkit::Error::Codes::ROOFCODE << std::endl;*/
}

/*void testRQ0001001()
{	
	toolkit::Version ver = toolkit::getVersion();
	std::string strMessge = "Valid RQ 0001-001..";
	CU_ASSERT(ver.getMajor() > -1)
}*/


int main(int argc, char *argv[])
{
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
	
	if ((NULL == CU_add_test(pSuite, "Pruebas de comparacion", testComparators)))
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
