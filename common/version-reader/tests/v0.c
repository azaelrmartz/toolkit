
#include <CUnit/Basic.h>
#include <stdio.h>


#include "../driver.h"





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

void testPositiveSintax()
{
    struct Tray ty1;
    ty1.dysplay_erro = 1;
    CU_ASSERT_TRUE(parse_string(&ty1,"1.3.65") == 0);//deve aceptar ;
    CU_ASSERT_TRUE(parse_string(&ty1,"11.3.65-SNAPSHOT") == 0);//deve aceptar ;
    CU_ASSERT_TRUE(parse_string(&ty1,"12.36.56-DEVELOPING+12345678901233") == 0);//deve aceptar ;
    //printf("Ultima prueba\n");
    CU_ASSERT_TRUE(parse_string(&ty1,"12.36.56-snapshot+alpha.23") == 0);
}

void testNegativeSintax()
{
    struct Tray ty1;
    /*CU_ASSERT_FALSE(parse_string(&ty1,"12.36.56-GA+123456;78901233") == 0);//error sintactico la sengun version esta incompleta
    CU_ASSERT_FALSE(parse_string(&ty1,"12.36.56-RTM+12345678901233;devtest;") == 0);//error sintactico la sengun version esta incompleta
    CU_ASSERT_FALSE(parse_string(&ty1,"12.36.56-snaps;hot+12345678901233") == 0);//error sintactico la sengun version esta incompleta
    CU_ASSERT_FALSE(parse_string(&ty1,"12.36.56-snapshot+12345678901233;") == 0);    */
}

int main(int argc, char *argv[])
{
	CU_pSuite pSuite = NULL;
	
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	

	pSuite = CU_add_suite("Lector C.\n", init_toolkit_common, clean_toolkit_common);
	if (NULL == pSuite) 
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	
	if ((NULL == CU_add_test(pSuite, "Sitaxis posivita.", testPositiveSintax)))
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
