// eratosthenes.c
// Řešení IJC-DU1, příklad a), 17.3.2020
// Autor: Adam Ondrejka (xondre12), FIT
// Přeloženo: gcc 7.5.0

#include "bitset.h"
#include "eratosthenes.h"
#include <math.h>

void Eratosthenes(bitset_t jmeno_pole) {

  for(bitset_index_t i = 2; i < sqrt(bitset_size(jmeno_pole)); i++) { //zaciname od 2
    if(bitset_getbit(jmeno_pole, i) == 0) { //najmensi taky ze p[i] je 0
      for(bitset_index_t n = 2; n * i < bitset_size(jmeno_pole); n++) {
        bitset_setbit(jmeno_pole, n*i, 1); //vsetky nasobky na nastavime na 1
      }
    }
  }
}