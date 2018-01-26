/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_H_
#define LIST_H_
typedef struct sentence_t
{
	int     **array;
	int	lines;
	int	lenght;
}text;

typedef struct key_t
{
	int	**key;
	int	size;
	int	lenght;
}key;
	
typedef struct check_struct
{
        char arg;
	int (*fptr)(char *);
}check_struct;

int my_get_nbr(char *str);
int get_t_num(int alpha, int *v, int *p, int r);
int are_numbers (char *av);
void number(int ac, char **av);


int key_lengh(char *av);
int **get_key(char *av, int rows,int lines, int key_lenght);
int matrix_size(char *av);
void print_key(int **key, int len, int lines, int columns);
void print_array(int **key, int len, int lines, int columns);
int **malloca(int lines, int columns);
int **feed_array(int **key, char *str, int lines,\
                  int columns, int key_lenght);
void multiply(char **av);
void matrix2(text *a, key *b);
text *sentence(char *av, char *av2);
key *keya(char *av);
void my_putchar(char c);
int my_putstr(char  *str);
int my_put_nbr(int nb);
unsigned long my_put_ulong(unsigned long nb);
long my_put_long(long nb);
long long my_put_llong(long long nb);
long my_put_octal(long nb);

#endif
