
#include "toolkit.hpp"
#include "config.h" 

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


void testVersion()
{
	//for class Version
	toolkit::Version ver = toolkit::getVersionCommon();

	
	CU_ASSERT(ver.getMajor() > -1)
	CU_ASSERT(ver.getMinor() > -1)
	CU_ASSERT(ver.getPatch() > -1)
	
	CU_ASSERT(MAJOR == ver.getMajor())
	CU_ASSERT(MINOR == ver.getMinor())
	CU_ASSERT(PATCH == ver.getPatch())
	
	
}

void testMessages()
{	
	//para asegurar el correcto fucionamiento de Message::Code::operator int() const
	CU_ASSERT(sizeof(int) == sizeof(toolkit::Message::Succeeds))
	CU_ASSERT(sizeof(int) == sizeof(toolkit::Message::Fails))
	
	std::string strMessge = "testing..";
	
	toolkit::Confirmation confirmation(toolkit::Confirmation::SUCCEED,strMessge);	
	CU_ASSERT(confirmation.isPass());//todo instacia de Confirmation deve returnar true con isPass
	CU_ASSERT(!confirmation.isFail());//todo instacia de Confirmation deve returnar true con isFail
	
	toolkit::Exception exception(toolkit::Exception::FAIL,strMessge);
	CU_ASSERT(!exception.isPass());//todo instacia de Exception deve returnar false con isPass
	CU_ASSERT(exception.isFail());//todo instacia de Exception deve returnar true con isFail
	
	//interface complatible con std::exception
	CU_ASSERT(0 == strMessge.compare(exception.what()));
}


int main()
{
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	toolkit::Version ver = toolkit::getVersionCommon();
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
	if ((NULL == CU_add_test(pSuite, classMessage.c_str(), testMessages)))
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
