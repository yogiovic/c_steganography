// bitset.h
// Řešení IJC-DU1, příklad a), 17.3.2020
// Autor: Adam Ondrejka (xondre12), FIT
// Přeloženo: gcc 7.5.0
// Hlavickovy subor pre pracu s bitovym polom

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "error.h"

#ifndef BITSET_H
#define BITSET_H

typedef unsigned long * bitset_t;
typedef unsigned long bitset_index_t;

#define UL_SIZE (sizeof(unsigned long) * CHAR_BIT)

#define bitset_create(jmeno_pole, velikost) \
        static_assert((velikost > 0), "Velkost pola musi byt vacsia ako 0!\n");\
        unsigned long jmeno_pole[(velikost / UL_SIZE) + ((velikost %  UL_SIZE) > 0 ? 1 : 0) + 1] = {velikost, 0};

#define bitset_alloc(jmeno_pole, velikost) \
        assert(velikost > 0); \
        unsigned long *jmeno_pole = calloc(((velikost / UL_SIZE) + ((velikost % UL_SIZE) > 0 ? 1 : 0) + 1) , sizeof(unsigned long)); \
        if(!jmeno_pole) { fprintf(stderr, "bitset_alloc: Chyba pri alokovani pamete!\n"); return 1; } \
        (jmeno_pole)[0] = velikost; //0ty index je size

#define bitset_free(jmeno_pole) free(jmeno_pole);         
    
#ifdef USE_INLINE

    inline unsigned long bitset_size(bitset_t jmeno_pole) {
        return jmeno_pole[0];
    }

    inline unsigned long bitset_getbit(bitset_t jmeno_pole, bitset_index_t index) {
        if((index >= bitset_size(jmeno_pole))) 
          error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (bitset_index_t)index, (bitset_index_t)(jmeno_pole[0]-1));
        return ((jmeno_pole[((index)/UL_SIZE) + 1] & (1UL << ((index)%UL_SIZE))) != 0);
    }

    inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz){
        if((index >= bitset_size(jmeno_pole))) error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (bitset_index_t)index, (bitset_index_t)(jmeno_pole[0]-1));
        
        (vyraz != 0) ? (jmeno_pole[(index)/UL_SIZE + 1] |=  (1UL << ((index)%UL_SIZE))) : (jmeno_pole[(index)/UL_SIZE + 1] &= (0UL << ((index)%UL_SIZE)));
        return;
    }

#else

    #define bitset_size(jmeno_pole) jmeno_pole[0]

    #define bitset_getbit(jmeno_pole, index) \
        ((bitset_index_t)index >= bitset_size(jmeno_pole) || index < 1) ? \
        (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (bitset_index_t)index, (bitset_index_t)(jmeno_pole[0]-1)), -1) : \
        ((jmeno_pole[(((bitset_index_t)index)/UL_SIZE) + 1] & (1UL << (((bitset_index_t)index)%UL_SIZE))) != 0)
    
    #define bitset_setbit(jmeno_pole, index, vyraz) \
        if((bitset_index_t)index >= bitset_size(jmeno_pole) || index < 1) \
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (bitset_index_t)index, (bitset_index_t)(jmeno_pole[0]-1)); \
        (vyraz != 0) ? (jmeno_pole[((bitset_index_t)index)/UL_SIZE + 1] |=  (1UL << (((bitset_index_t)index)%UL_SIZE))) : \
                     (jmeno_pole[((bitset_index_t)index)/UL_SIZE + 1] &= (0UL << (((bitset_index_t)index)%UL_SIZE)))
 

#endif //INLINE

#endif //BITSET