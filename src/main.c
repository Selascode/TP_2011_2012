#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "triParMinSuccessif.h"
#include "triParInsertion.h"
#include "triRapide.h"
#include "triFusion.h"
#include "triParTas.h"

#define MAX 2147483647

void remplirAuHasard(long int tab[], long int nbElements) {
  long int i;
  for (i=0;i<nbElements;i++) 
    tab[i]=random()%nbElements;
  /*Remplacer la ligne precedente par la ligne suivante pour montrer que 
    dans le pire des cas le tri rapide est en n^2 lorsque 
    la valeur pivot est le 1er element du tableau */
  /*tab[i]=i;*/
}

long int saisieNbEntiers(long int max) {
  long int resultat;
  do {
    printf("NB d'entiers à trier (compris entre 1 et %ld) : ",max);
    scanf("%ld",&resultat);
  } while ((resultat<=0) || (resultat>max));
  return resultat;
}


void afficher(long int tab[], long int nbElements) {
  long int i;
  for (i=0;i<nbElements;i++) 
    printf("%ld ",tab[i]);
  printf("\n"); 
}

void rienFaire(long int tab[], long int nbElements) {
}


double benchmarkerUnTri(long int tab[],  long int nbElements, void (*trier)(long int*,long int), void(*actionApresTri)(long int*,long int)){
  long int* t;
  clock_t t1, t2; 
  t=(long int*)malloc(nbElements*sizeof(long int));
  memcpy(t,tab,nbElements*sizeof(long int));
  t1=clock();
  trier(t,nbElements);
  actionApresTri(t,nbElements);
  t2=clock();
  free(t);
  return (double)(t2-t1)/CLOCKS_PER_SEC; 
}

void testTris() {
  long int nbEntiers=10;
  long int *entiers;
  entiers=(long int*)malloc(nbEntiers*sizeof(long int));
  remplirAuHasard(entiers,nbEntiers);
  printf("Test des tris :\n");
  printf("  Tableau a trier : ");
  afficher(entiers,nbEntiers);
  printf("  Tri Par Minimum Successif : ");
  benchmarkerUnTri(entiers,nbEntiers,trierEntiersParMinSuccessif,afficher);
  printf("  Tri Par Insertion : ");
  benchmarkerUnTri(entiers,nbEntiers,trierEntiersParInsertion,afficher);
  printf("  Tri Rapide : ");
  benchmarkerUnTri(entiers,nbEntiers,trierEntiersRapide,afficher);
  printf("  Tri Par Fusion : ");
  benchmarkerUnTri(entiers,nbEntiers,trierEntiersParFusion,afficher);
  printf("  Tri Par Tas : ");
  benchmarkerUnTri(entiers,nbEntiers,trierEntiersParTas,afficher);
  free(entiers);
}


void benchmark() {
  long int nbEntiers;
  long int *entiers;
  nbEntiers=saisieNbEntiers(MAX);
  entiers=(long int*)malloc(nbEntiers*sizeof(long int));
  remplirAuHasard(entiers,nbEntiers);
  printf("Test des tris sur %ld entiers :\n",nbEntiers);
  printf("  Tri Par Minimum Successif : %fs (temps CPU)\n",benchmarkerUnTri(entiers,nbEntiers,trierEntiersParMinSuccessif,rienFaire));
  printf("  Tri Par Insertion : %fs (temps CPU)\n",benchmarkerUnTri(entiers,nbEntiers,trierEntiersParInsertion,rienFaire));
  printf("  Tri Rapide : %fs (temps CPU)\n",benchmarkerUnTri(entiers,nbEntiers,trierEntiersRapide,rienFaire));
  printf("  Tri Par Fusion : %fs (temps CPU)\n",benchmarkerUnTri(entiers,nbEntiers,trierEntiersParFusion,rienFaire));
  printf("  Tri Par Tas : %fs (temps CPU)\n",benchmarkerUnTri(entiers,nbEntiers,trierEntiersParTas,rienFaire));
  free(entiers);
}

int main(int nbparams,char** params) {
  testTris();
  benchmark();
  return EXIT_SUCCESS;
}
