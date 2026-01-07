#include<stdio.h>
#include<CUnit/Basic.h>
#include<string.h>
#include<math.h>
#include"triParTas.h"


#define TRUE 1
#define FALSE 0

int init_suite_success(void) { 
  return 0; 
}

int clean_suite_success(void) { 
  return 0; 
}

int tableauxEgaux(long int t1[], long int t2[], long int nbElements) {
  long int i=0;
  int OK=1;
  while (OK && (i<nbElements)) {
    if(t1[i]!=t2[i])
      OK=0;
    else
      i++;
  }
  return OK;
}


void test_trierParTas(void){
  long int t1[10]={87,77,47,33,40,24,25,18,5,29};
  long int t2[10]={5,18,24,25,29,33,40,47,77,87};
  trierEntiersParTas(t1,10);
  CU_ASSERT_TRUE(tableauxEgaux(t1,t2,10));
}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Test tri par tas (boite noire)", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "Trier pas tas", test_trierParTas)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Nettoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}
