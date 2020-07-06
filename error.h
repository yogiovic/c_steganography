// error.h
// Řešení IJC-DU1, příklad b), 17.3.2020
// Autor: Adam Ondrejka (xondre12), FIT
// Přeloženo: gcc 7.5.0

#include <stdarg.h>

#ifndef ERROR_H
#define ERROR_H

void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif