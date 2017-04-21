
/*
 cc     essaicunit.c   -o essaicunit -I /usr/local/Cellar/cunit/2.1-3/include/ -lCUnit -L /usr/local/Cellar/cunit/2.1-3/lib/
 */

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
int maxi(int i1, int i2)
    {
      return (i1 > i2) ? i1 : i2;
    }

void test_maxi(void)
    {
      CU_ASSERT(maxi(0,2) == 2);
      CU_ASSERT(maxi(0,-2) == 0);
      CU_ASSERT(maxi(2,2) == 2);
    }

int main() {
	CU_pSuite pSuite = NULL;
	
	if (CU_initialize_registry() != CUE_SUCCESS) {
		return CU_get_error();
	}

	pSuite = CU_add_suite("Suite",NULL,NULL);

	if (pSuite==NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

    if (CU_add_test (pSuite, "test of maxi()",test_maxi)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    //CU_cleanup_registry();
    
	return 0;
}
