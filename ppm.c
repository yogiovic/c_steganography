// ppm.c
// Řešení IJC-DU1, příklad b), 17.3.2020
// Autor: Adam Ondrejka (xondre12), FIT
// Přeloženo: gcc 7.5.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "ppm.h"

/*    "P6" <ws>+
      <xsizetxt> <ws>+ <ysizetxt> <ws>+
      "255" <ws>
      <binární data, 3*xsize*ysize bajtů RGB>
      <EOF>
*/

void ppm_free(struct ppm * p) {
  free(p);
}

struct ppm * ppm_read(const char *filename) {
  FILE *f;

  if(!(f = fopen(filename, "r"))) {
    warning_msg("Subor [%s] sa nepodarilo otvorit\n", filename);
    return NULL;
  }

  unsigned xsize, ysize;
	unsigned char color;
	char file_type[3];

  if (fscanf(f, "%2s %u %u %hhu ", file_type, &xsize, &ysize, &color) < 4) { //nacitame hlavicku suboru
    warning_msg("Hlavicka suboru %s je v nespravnom formate!\n", filename);
    fclose(f);
    return NULL;
  }
  
  if (strcmp(file_type, "P6") != 0) { //musi byt P6
    warning_msg("Subor [%s] je nespravneho typu!\n", filename);
    fclose(f);
    return NULL;
  }

  size_t ppm_size = xsize * ysize * 3; //viz zadanie

  if (ppm_size > PPM_LIMIT) { 
    warning_msg("Obrazok je prilis velky\n");
    fclose(f);
    return NULL;
  }
  
  struct ppm *ppm_ptr = malloc(sizeof(struct ppm) + ppm_size); //alokujeme
  
  if (!ppm_ptr) { //mallocu neverime
    warning_msg("Nepodarilo sa alokovat miesto!\n");
    fclose(f);
    return NULL;
  }

  if (fread(ppm_ptr->data, sizeof(char), ppm_size, f) != ppm_size) { //nacitame data
    warning_msg("Nepodarilo sa nacitat data\n");
    fclose(f);
    free(ppm_ptr);
    return NULL;
  }

  ppm_ptr->xsize = xsize; ppm_ptr->ysize = ysize; //ulozime sizes

  fclose(f); //upraceme
  return ppm_ptr; //vratime

}