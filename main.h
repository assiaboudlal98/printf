#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
/* main.c */
int _printf(const char *format, ...);
/* _putchar.c */
int _putchar(char c);
/* printf_functions.c */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
#endif /* MAIN_H */
