// error.c
// Řešení IJC-DU1, příklad b), 17.3.2020
// Autor: Adam Ondrejka (xondre12), FIT
// Přeloženo: gcc 7.5.0

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "error.h"

void warning_msg(const char *fmt, ...) {
  va_list arguments;
  va_start(arguments, fmt);
  fprintf(stderr, "CHYBA: ");
  vfprintf(stderr, fmt, arguments);
  va_end(arguments);
}

void error_exit(const char *fmt, ...) {
  va_list arguments;
  va_start(arguments, fmt);
  fprintf(stderr, "CHYBA: ");
  vfprintf(stderr, fmt, arguments);
  va_end(arguments);
  exit(1);
}
