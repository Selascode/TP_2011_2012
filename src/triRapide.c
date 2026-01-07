#include "triRapide.h"
#include "echanger.h"


long int partitionner(long int tab[], long int debut, long int fin) {
  long int pivot=tab[debut];
  long int i=debut+1,j=fin;
  while(i<=j)
    if (tab[i]<=pivot) {
      i++;
    } else {
      if (tab[j]>pivot) {
	j--;
      } else {
	echangerEntiers(&tab[i],&tab[j]);
      }
    }
  echangerEntiers(&tab[debut],&tab[i-1]);
  return j;
}

void trierEntiersRapideRecursif(long int tab[], long int debut,long int fin) {
  long int indicePartition;
  if (debut<fin) {
    indicePartition=partitionner(tab,debut,fin);
    trierEntiersRapideRecursif(tab,debut,indicePartition-1);
    trierEntiersRapideRecursif(tab,indicePartition+1,fin);
  }
}

void trierEntiersRapide(long int tab[], long int nbElements) {
  trierEntiersRapideRecursif(tab,0,nbElements-1);
}
