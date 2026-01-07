#include "echanger.h"
void echangerEntiers(long int* a, long int* b) {
  long int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
