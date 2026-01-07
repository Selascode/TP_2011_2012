#include <stdlib.h>
#include "triFusion.h"
#include "echanger.h"

void fusionner(long int tab[], long int debut,long int milieu, long int fin) {
  long int* temp;
  long int i=debut,j=milieu+1,k=0;
  temp=(long int*)malloc((fin-debut+1)*sizeof(long int));
  while (k<fin-debut+1) {
    if (i>milieu) {
      temp[k]=tab[j];
      j++;
    } else {
       if (j>fin) {
	 temp[k]=tab[i];
	 i++;      
       } else {
	 if (tab[i]<=tab[j]) {
	   temp[k]=tab[i];
	   i++;
	 } else {
	   temp[k]=tab[j];
	   j++;
	 }
       }
    }
    k++;
  }
  for (i=0;i<k;i++) 
    tab[debut+i]=temp[i];
  free(temp);
}

void trierEntiersParFusionRecursif(long int tab[], long int debut,long int fin) {
  long int milieu;
  if (debut<fin) {
    milieu=(debut+fin)/2;
    trierEntiersParFusionRecursif(tab,debut,milieu);
    trierEntiersParFusionRecursif(tab,milieu+1,fin);
    fusionner(tab,debut,milieu,fin);
  }
}

void trierEntiersParFusion(long int tab[], long int nbElements) {
  trierEntiersParFusionRecursif(tab,0,nbElements-1);
}
