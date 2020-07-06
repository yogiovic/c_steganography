// ppm.h
// Řešení IJC-DU1, příklad b), 17.3.2020
// Autor: Adam Ondrejka (xondre12), FIT
// Přeloženo: gcc 7.5.0

#include <stdlib.h>

#ifndef PPM_H
#define PPM_H

#define PPM_LIMIT 8000*8000*3 
// Můžete omezit max. velikost obrazových dat vhodným implementačním 8000


struct ppm {
  unsigned xsize;
  unsigned ysize;
  char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char *filename);

void ppm_free(struct ppm *p);

#endif