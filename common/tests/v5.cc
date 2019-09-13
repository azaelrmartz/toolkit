
#include <CUnit/Basic.h>
#include <iostream>
#include <cstdlib>


#include "../common.hpp"
#include "../packInfo.hpp"


static std::string  rootDir;
static int majorNumber;

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
        
    //x simepre es amjor que x.y
    octetos::toolkit::Version ver3;
    octetos::toolkit::Version ver4;
    ver3.setNumbers(1);
    ver4.setNumbers(1,50);
    if(ver3 >= ver4) 
    {
        CU_ASSERT(true);
    }
    else 
    {
        CU_ASSERT(false);
    }
    if(ver3 > ver4) 
    {
        CU_ASSERT(true);
    }
    else 
    {
        CU_ASSERT(false);
    }
    if(ver3 < ver4) 
    {
        CU_ASSERT(false);
    }
    else 
    {
        CU_ASSERT(true);
    }    
    
    //x simepre es amjor que x.y
    octetos::toolkit::Version ver5;
    octetos::toolkit::Version ver6;
    ver5.setNumbers(1,50);
    ver6.setNumbers(1,50,100);
    if(ver5 >= ver6) 
    {
        CU_ASSERT(true);
    }
    else 
    {
        CU_ASSERT(false);
    }
    if(ver5 > ver6) 
    {
        CU_ASSERT(true);
    }
    else 
    {
        CU_ASSERT(false);
    }
    if(ver5 < ver6) 
    {
        CU_ASSERT(false);
    }
    else 
    {
        CU_ASSERT(true);
    }
    
    
    if(ver5 == ver6)
    {
        CU_ASSERT(true);
    }
    else
    {
        CU_ASSERT(false);
    }
    if(ver5 != ver6)
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
	CU_ASSERT(ver.getMajor() == -1)
	CU_ASSERT(ver.getMinor() == -1)
	CU_ASSERT(ver.getPatch() == -1)	
        CU_ASSERT(ver.getStage() == octetos::toolkit::Version::unknown)
        CU_ASSERT(ver.getBuild() == 0);
        CU_ASSERT(ver.getName().size() == 0);
        
        std::string fileNameVersion = "ver";
        fileNameVersion += std::to_string(majorNumber);
        
        octetos::toolkit::Version ver2;
        CU_ASSERT(ver2.fromFile(fileNameVersion));
        CU_ASSERT(ver2.getMajor() == 12);
        CU_ASSERT(ver2.getMinor() == 36);
        CU_ASSERT(ver2.getPatch() == 56);
        CU_ASSERT(ver2.getStage() == octetos::toolkit::Version::snapshot);
        CU_ASSERT(ver2.getBuild() == 12345678901233);
        CU_ASSERT(ver2.getName().compare("devtest") == 0);   
        octetos::toolkit::Version ver3;
        CU_ASSERT(ver3.fromString("1.3.65;"));//deve aceptar ;
        CU_ASSERT(ver3.fromString("11.3.65-SNAPSHOT;"));//deve aceptar ;
        CU_ASSERT(ver3.fromString("12.36.56-DEVELOPING 12345678901233 devtest;"));//deve aceptar ;
        CU_ASSERT_FALSE(ver3.fromString("12.36.56-GA 123456;78901233 devtest;"));//error sintactico la sengun version esta incompleta
        CU_ASSERT_FALSE(ver3.fromString("12.36.56-RTM 12345678901233 ;devtest;"));//error sintactico la sengun version esta incompleta
        CU_ASSERT_FALSE(ver3.fromString("12.36.56-snaps;hot 12345678901233 devtest"));//error sintactico la sengun version esta incompleta
        CU_ASSERT(ver3.fromString("12.36.56-snapshot 12345678901233 devtest;12.36.56-RTM;"));
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

void testBuildExtension()
{
    octetos::toolkit::Version ver1;
    ver1.setBuild(12345678901233);
    CU_ASSERT(ver1.getBuild() == 12345678901233);
    octetos::toolkit::Version ver2;
    ver2.setNumbers(2,36,98);
    ver2.setStage(octetos::toolkit::Version::alpha);
    octetos::toolkit::Version ver3;
    ver3.setNumbers(1);
    ver3.setStage(octetos::toolkit::Version::release);
    ver2.setBuild(ver3);
    std::cout << std::endl << "Build complejo " << ver2.toString() << std::endl; 
}
int main(int argc, char *argv[])
{

	octetos::toolkit::Package packinfo = octetos::toolkit::getPackageInfo();
	octetos::toolkit::Version& ver = packinfo.version;
    
	CU_pSuite pSuite = NULL;
	majorNumber = ver.getMajor();
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	std::string& pkName = packinfo.name;
	std::string classVersionString = std::string("Probando ") + pkName + " " + ver.toString() + "\n" + packinfo.licence.getBrief() + "\n" + packinfo.brief + "\n";
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
	
	if ((NULL == CU_add_test(pSuite, "Criterios de comparación", testComparators)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	if ((NULL == CU_add_test(pSuite, "Pruebas de validadacion", testValidStatement)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	
	if ((NULL == CU_add_test(pSuite, "Extención de Campo Build.", testBuildExtension)))
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
