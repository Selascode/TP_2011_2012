#include "triParMinSuccessif.h"
#include "echanger.h"

long int obtenirIndiceDuMin(long int tab[], long int borneInf, long int borneSup) {
  long int resultat=borneInf;
  long int i;
  for (i=borneInf+1;i<=borneSup;i++)
    if (tab[i]<tab[resultat])
      resultat=i;
  return resultat;
}

void trierEntiersParMinSuccessif(long int tab[], long int nbElements) {
  long int i, indiceDuMin;
  for (i=0;i<nbElements;i++) {
    indiceDuMin=obtenirIndiceDuMin(tab,i,nbElements-1);
    echangerEntiers(&tab[i],&tab[indiceDuMin]);
  } 
}
