// steg-decode.c
// Řešení IJC-DU1, příklad b), 17.3.2020
// Autor: Adam Ondrejka (xondre12), FIT
// Přeloženo: gcc 7.5.0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bitset.h"
#include "ppm.h"
#include "eratosthenes.h"
#include "error.h"

#define put_set(put_val, set_val) \
        putchar(put_val); \
        msg_char = set_val; \
        offset = 0;
        
int main(int argc, char *argv[]){
	
  if (argc != 2)
		error_exit("Zly pocet argumentov, spustite v tvare ./steg-decode [nazov_suboru]\n");
  
  const char *nazov = argv[1];

  struct ppm *ppm_ptr = ppm_read(nazov);
  char msg_char = '\0';
  unsigned offset = 0;
	
  if (!ppm_ptr)
    error_exit("Subor [%s] sa nepodarilo nacitat!\n", nazov);

  unsigned ppm_size = 3 * (ppm_ptr->xsize * ppm_ptr->ysize);

  bitset_alloc(ppm_arr,ppm_size); // viz. zadanie: velikost bitového pole musí odpovídat velikosti obrazových dat.
  Eratosthenes(ppm_arr); //...

  for (unsigned i = 23; i < ppm_size; i++) {
    
    if (bitset_getbit(ppm_arr,i) != 0) //zaujmaju nas iba prvociselne indexy
      continue;
    
    else {
      msg_char = msg_char | (ppm_ptr->data[i] & 1) << offset++; //posunieme na potrebne miesto v chare a ulozime

    	if (offset == 8) { //char ma 8bitov

        if (!msg_char) { //koniec
          put_set(10, -1); //vypiseme newline a nastavime EOF
         	break; //skoncime
				}
        else
          put_set(msg_char, '\0') //vypiseme a ideme odznova
      }
    }
  }
	
  if (msg_char != EOF) //subor je nespravne ukonceny
		error_exit("Subor [%s] nieje spravne ukonceny!\n", nazov);

  ppm_free(ppm_ptr);
  bitset_free(ppm_arr); //upraceme

return EXIT_SUCCESS; //:-) 

}
