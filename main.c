/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void error(int ac)
{
	if (ac != 9)
		exit(84);
}

void sphere (char **av)
{
	my_putstr("sphere of radius ");
	my_putchar(av[1][0]);
	my_putchar('\n');
}

void line (int *v, int *p)
{
	printf("straight line going through the (%d,%d,%d) ",\
	       p[0],p[1],p[2]);
	printf("points and of direction vector (%d,%d,%d)\n",\
	       v[0],v[1],v[2]);	
}
int create_alpha (char **av)
{
	int	alpha;
	int	v[3] = {my_get_nbr(av[5]),my_get_nbr(av[6]),\
			my_get_nbr(av[7])};
	int	p[3] = {my_get_nbr(av[2]),my_get_nbr(av[3]),\
			my_get_nbr(av[4])};
	int	r = my_get_nbr(av[8]);
	printf("v:%d,%d,%d\n", v[0],v[1]*v[1],v[2]);
	printf("p:%d,%d,%d\n", p[0],p[1],p[2]);
        line(v,p);
	alpha = 2 * v[0]*p[0] + 2*v[1]*p[1] + 2*v[2]*p[2];
	printf("%d\n",alpha);
	alpha = alpha * alpha;
	printf("%d\n",alpha);
	alpha = alpha -4*(v[0]*v[0] + v[1]*v[1] + v[2]*v[2])*\
		(- r*r + p[0]*p[0] + p[1]*p[1] + p[2]*p[2]);
	printf("final:%d\n",alpha);
	return (alpha);
}

int main(int ac, char **av)
{
	int alpha;
	
	error(ac);
	if (av[1][0] == '1')
		sphere(av);
        alpha = create_alpha(av);
	//get_t_num(alpha);
}
