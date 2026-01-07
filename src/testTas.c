#include<stdio.h>
#include<CUnit/Basic.h>
#include<string.h>
#include<math.h>
#include"tas.h"


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


void test_estUnTasSurUnTas(void){
  long int t[10]={87,77,47,33,40,24,25,18,5,29};
  CU_ASSERT_TRUE(estUnTas(t,10,0));
}

void test_estUnTasSurUnTableauQuelconque(void){
  long int t[10]={87,77,47,90,40,24,25,18,5,29};
  

  CU_ASSERT_FALSE(estUnTas(t,10,0));
}

void test_faireDescendre(void){
  long int t1[10]={30,77,47,33,40,24,25,18,5,29};
  long int t2[10]={77,40,47,33,30,24,25,18,5,29};
  faireDescendre(t1,10,0);
  printf("%lu\n", t1[0]); 
  printf("%lu\n", t1[1]); 
  printf("%lu\n", t1[2]); 
  printf("%lu\n", t1[3]); 
  printf("%lu\n", t1[4]); 
  printf("%lu\n", t1[5]); 
  printf("%lu\n", t1[6]); 
  printf("%lu\n", t1[7]); 
  printf("%lu\n", t1[8]); 
  printf("%lu\n", t1[9]); 
  CU_ASSERT_TRUE(tableauxEgaux(t1,t2,10));
}

void test_tamiser(void){
  long int t1[10]={33,77,25,18,40,24,47,87,5,29};
  long int t2[10]={87,77,47,33,40,24,25,18,5,29};
  tamiser(t1,10);
  CU_ASSERT_TRUE(tableauxEgaux(t1,t2,10));
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests � la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "estUnTas avec un tas", test_estUnTasSurUnTas)) 
      || (NULL == CU_add_test(pSuite, "estUnTas avec un tableau quelconque", test_estUnTasSurUnTableauQuelconque))
      || (NULL == CU_add_test(pSuite, "faireDescendre", test_faireDescendre))
      || (NULL == CU_add_test(pSuite, "tamiser", test_tamiser))
      )
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
