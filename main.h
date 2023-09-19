#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLG */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SZ */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct jtn - Struct op
 *
 * @jtn: The format.
 * @fn: The function associated.
 */
struct jtn
{
	char jtn;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct jtn jtn_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct jtn jtn_t;

int _printf(const char *format, ...);
int handle_print(const char *jtn, int *i,
va_list list, char buffer[], int flg, int wdt, int prcs, int sz);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);
int print_string(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);
int print_percent(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);
int print_binary(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);
int print_unsigned(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);
int print_octal(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);
int print_hexadecimal(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);
int print_hexa_upper(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);

int print_hexa(va_list types, char map_to[],
char buffer[], int flg, char flg_p, int wdt, int prcs, int sz);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);

/* Funciotns to handle other specifiers */
int get_flg(const char *format, int *i);
int get_wdt(const char *format, int *i, va_list list);
int get_prcs(const char *format, int *i, va_list list);
int get_sz(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flg, int wdt, int prcs, int sz);
int write_number(int is_positive, int ind, char buffer[],
	int flg, int wdt, int prcs, int sz);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int wdt, int flg, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flg, int wdt, int prcs, int sz);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int sz);
long int convert_size_unsgnd(unsigned long int num, int sz);

#endif /* MAIN_H */

