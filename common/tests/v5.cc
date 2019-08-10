
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
}
void testVersionGeneric()
{
	//for class Version
	octetos::toolkit::Version ver;
	
        //valores iniciales
	CU_ASSERT(ver.getMajor() == -1)
	CU_ASSERT(ver.getMinor() == -1)
	CU_ASSERT(ver.getPatch() == -1)	
        CU_ASSERT(ver.getStage() == octetos::toolkit::Version::unknown)
        CU_ASSERT(ver.getBuild() == 0);
        CU_ASSERT(ver.getName().size() == 0);
        
        octetos::toolkit::Version ver2;
        CU_ASSERT(ver2.fromFile("../tests/ver"));
        CU_ASSERT(ver2.getMajor() == 12);
        CU_ASSERT(ver2.getMinor() == 36);
        CU_ASSERT(ver2.getPatch() == 56);
        CU_ASSERT(ver2.getStage() == octetos::toolkit::Version::snapshot);
        CU_ASSERT(ver2.getBuild() == 12345678901233);
        CU_ASSERT(ver2.getName().compare("devtest") == 0);   
        octetos::toolkit::Version ver3;
        CU_ASSERT(ver3.fromString("1.3.65;"));//deve aceptar ;
        CU_ASSERT(ver3.fromString("11.3.65-snapshot;"));//deve aceptar ;
        CU_ASSERT(ver3.fromString("12.36.56-snapshot 12345678901233 devtest;"));//deve aceptar ;
        CU_ASSERT_FALSE(ver3.fromString("12.36.56-snapshot 123456;78901233 devtest;"));//error sintactico la sengun version esta incompleta
        CU_ASSERT_FALSE(ver3.fromString("12.36.56-snapshot 12345678901233 ;devtest;"));//error sintactico la sengun version esta incompleta
        CU_ASSERT_FALSE(ver3.fromString("12.36.56-snaps;hot 12345678901233 devtest"));//error sintactico la sengun version esta incompleta
        CU_ASSERT(ver3.fromString("12.36.56-snapshot 12345678901233 devtest;12.36.56-snapshot;"));
}

void testValidStatement()
{
        CU_ASSERT(octetos::toolkit::Version::valid("valid numbers = 1.3.65"));
        ///std::cout << "Err>>:" <<std::endl;
        CU_ASSERT_FALSE(octetos::toolkit::Version::valid("valid numbers = 1.44.55-rc"));//deve rechazar porque se esta incluyendo la etapa
        //std::cout << "Err<<" <<std::endl;
        CU_ASSERT(octetos::toolkit::Version::valid("valid stage = rc"));
        CU_ASSERT_FALSE(octetos::toolkit::Version::valid("valid stage = 1.2.3-rc"));
        CU_ASSERT(octetos::toolkit::Version::valid("valid name = snate43"));
        CU_ASSERT(octetos::toolkit::Version::valid("valid build = 12389678111233"));
}

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
	
	if ((NULL == CU_add_test(pSuite, "Pruebas de validadacion", testValidStatement)))
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
