#include "triParMinSuccessif.h"
#include "echanger.h"

/* int obtenirIndiceDnsertion(int tab[], int indiceEntier) { */
/*   int i; */
/*   i=0; */
/*   while(tab[i]<=tab[indiceEntier] && i<indiceEntier) */
/*     i++;     */
/*   return i; */
/* } */

long int obtenirIndiceDInsertion(long int tab[], long int indiceEntier) {
  long int g,d,c;
  g=0;
  d=indiceEntier;
  while(g<d) {
    c=(g+d)/2;
    if(tab[c]>tab[indiceEntier])
      d=c;
    else
      g=c+1;
  }    
  return g;
}


void decaler(long int tab[],long int debut, long int fin){
  long int i;
  i=fin;
  while(i>debut) {
    tab[i]=tab[i-1];
    i--;
  }
}

void trierEntiersParInsertion(long int tab[], long int nbElements) {
  long int i,  indiceDInsertion;
  long int temp;
  for (i=0;i<nbElements;i++) {
    indiceDInsertion=obtenirIndiceDInsertion(tab,i);
    temp=tab[i];
    decaler(tab,indiceDInsertion,i);
    tab[indiceDInsertion]=temp;
  } 
}
