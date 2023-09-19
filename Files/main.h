#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flg, int width, int prcs, int sz);

/*************fnct***/

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flg, int width, int prcs, int sz);
int print_string(va_list types, char buffer[],
	int flg, int width, int prcs, int sz);
int print_percent(va_list types, char buffer[],
	int flg, int width, int prcs, int sz);

/* Functions to print numbers */
int pr_int(va_list types, char buffer[],
	int flg, int width, int prcs, int sz);
int pr_binary(va_list types, char buffer[],
	int flg, int width, int prcs, int sz);
int pr_uns(va_list types, char buffer[],
	int flg, int width, int prcs, int sz);
int pr_oct(va_list types, char buffer[],
	int flg, int width, int prcs, int sz);
int pr_hex(va_list types, char buffer[],
	int flg, int width, int prcs, int sz);
int pr_hex_upp(va_list types, char buffer[],
	int flg, int width, int prcs, int sz);

int pr_hexa(va_list types, char map_to[],
char buffer[], int flg, char flag_ch, int width, int prcs, int sz);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flg, int width, int prcs, int sz);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int x_flg(const char *format, int *i);
int get_wdt(const char *format, int *i, va_list list);
int x_prc(const char *format, int *i, va_list list);
int x_sz(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flg, int width, int prcs, int sz);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flg, int width, int prcs, int sz);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flg, int width, int prcs, int sz);
int write_number(int is_positive, int ind, char buffer[],
	int flg, int width, int prcs, int sz);
int write_num(int ind, char bff[], int flg, int width, int prcs,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flg, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flg, int width, int prcs, int sz);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
