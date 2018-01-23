/*
** EPITECH PROJECT, 2017
** my_put_everything
** File description:
** By Luis Angel Macias de la Cruz
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "list.h"
void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char *str)
{
	
	int	i = 0;
	
	while(str[i] != '\0')
	{
		my_putchar(str[i]);
		i = i + 1;
	}
	return(0);	
}

int	nb_divide(int nb)
{
	int	div;

	if (nb == 0)
		return (1);
	div = 1;
	while (nb >= div)
	{
		div = div * 10;
	}
	return (div / 10);
}

int	my_put_nbr(int nb)
{
	int	div;

	if(nb < 0)
	{
		my_putchar('-');
		nb = nb * -1;
	}
	div = nb_divide(nb);
	while (div != 0)
	{
		my_putchar(nb / div + '0');
		nb = nb % div;
		div = div / 10;		
	}
	return (0);
}
	      
