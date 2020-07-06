// primes.c
// Řešení IJC-DU1, příklad a), 17.3.2020
// Autor: Adam Ondrejka (xondre12), FIT
// Přeloženo: gcc 7.5.0

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bitset.h"
#include "eratosthenes.h"

#define LIMIT 500000000 //velkost pola

int main() {
	
	clock_t start_t = clock(); //ulozime si pociatocny cas, budeme ho potreboat na riadku 38

	bitset_create(arr, LIMIT); 
	Eratosthenes(arr); //prvocisla budu 0
	
	bitset_index_t index = 0; 
	unsigned long result[10] = { 0 }; // naplnime nulami 

	for (bitset_index_t i = bitset_size(arr) - 1; i > 1; i--) { 
		
		if (bitset_getbit(arr, i) == 0) //je to prvocislo
			result[9 - index++] = i; //ideme od konca pola preto potrebujeme vypisat "naopak"

		if (index == 10) //aby sme nesahali tam kam nemame
			break;
	}

	for (bitset_index_t i = 0; i < 10; i++) {
		printf("%lu\n", result[i]); //vypiseme vysledky
	} 

	fprintf(stderr, "Time=%.3g\n", (double)(clock()-start_t)/CLOCKS_PER_SEC); //vypiseme cas
	return EXIT_SUCCESS;
}
