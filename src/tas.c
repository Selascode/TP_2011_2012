#include"tas.h"
#include "echanger.h"
long int max(long int a, long int b ){
  if (a > b) {
    return a ; 
  } else {
    return b ; 
  }
}


int estUnTas(long int tab[], long int nbElements, long int rang) {
  if ((2 * rang) > nbElements){
    return 1;
  } else {
    if ((2*rang +1) > nbElements){
      return tab[rang] >= tab[rang * 2]; 
    } else {
      if (tab[rang] >= max(tab[2*rang],tab[2*rang +1])) {
        return estUnTas(tab, 2*rang, nbElements) && estUnTas(tab,2*rang+1, nbElements); 
      } else {
        return 0; 
      }
    }
  }
}

long int indiceMax(long int t[], long int n , long int i , long int j){
  if (j < n){
    if (t[i] > t[j]){
      return i;
    } else {
      return j ; 
    }
  } else {
    return i; 
  }
}

void faireDescendre(long int tab[], long int nbElements, long int rang) {
  unsigned int posMax ; 
  
  if ((2 * rang) <= nbElements){
    posMax = indiceMax(tab, nbElements, 2*rang,( 2*rang+1));
    if (tab[rang] < tab[posMax]) {
      echangerEntiers(&tab[rang], &tab[posMax]);
      if (2 * posMax <= nbElements) {
        faireDescendre(tab,posMax,nbElements); 
      }
    }
  }
}

void tamiser(long int tab[], long int nbElements) {
  long int i; 
  for (i =  (nbElements / 2) ; i > 0; i--){
    faireDescendre(tab,i,nbElements); 
  } 
}
