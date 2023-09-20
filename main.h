#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* main.c */
int _printf(const char *format, ...);

/* _putchar.c */
int _putchar(char c);

int hnd_str(char *s);
int hnd_nbr(int num_ma);
int len_num(int num_ma);
#endif /* MAIN_H */
