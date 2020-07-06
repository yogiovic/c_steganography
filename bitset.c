// bitset.c
// Řešení IJC-DU1, příklad a), 17.3.2020
// Autor: Adam Ondrejka (xondre12), FIT
// Přeloženo: gcc 7.5.0
// Modul pre O0

#include "bitset.h"

#ifdef USE_INLINE

extern inline unsigned long bitset_size(bitset_t jmeno_pole);
extern inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz);
extern inline unsigned long bitset_getbit(bitset_t jmeno_pole, bitset_index_t index);

#endif