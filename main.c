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
#include <math.h>

void error(int ac)
{
	if (ac != 9)
		exit(84);
}

void sphere (char **av)
{
	printf("sphere of radius ");
	printf("%c\n", av[1][0]);
}

void cilinder(char **av)
{
	printf("cylinder of radius ");
	printf("%c\n", av[1][0]);
}

void line (int *v, int *p)
{
	printf("straight line going through the (%d,%d,%d) ",\
	       p[0],p[1],p[2]);
	printf("points and of direction vector (%d,%d,%d)\n",\
	       v[0],v[1],v[2]);	
}

void intersection(int *v, int *p, int r)
{
	float	a = (v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
	float	b = 2 * v[0]*p[0] + 2*v[1]*p[1] + 2*v[2]*p[2]; 
	float	c = (- r*r + p[0]*p[0] + p[1]*p[1] + p[2]*p[2]);
	float	g;
	float	m;
	float	alpha = b * b -4 * a *c;

	if (alpha < 0)
		printf("No intersection point.\n");
	if (alpha == 0)
	{
		g = -(b/(2 * a));
		//printf("%f\n", g);
		printf("1 intersection point :\n");
		printf("(%.3f, %.3f, %.3f)", p[0]+ g * v[0],	\
		       p[1]+ g * v[1], p[2]+ g * v[2]);
	}
	if (alpha > 0)
	{
		printf("2 intersection point:\n");
		g = (-b - sqrt(alpha)) / (2 * a);
		m = (-b + sqrt(alpha)) / (2 * a);
		printf("(%.3f, %.3f, %.3f)", p[0]+ g * v[0], 	\
		       p[1]+ g * v[1], p[2]+ g * v[2]);
		printf("(%.3f, %.3f, %.3f)", p[0]+ m * v[0],	\
		       p[1]+ m * v[1], p[2]+ m * v[2]);
	}
	//printf("aplha:%f\n", alpha);
}
void cylinder(int *v, int *p, int r)
{
	float	a = (v[0]*v[0] + v[1]*v[1]);
	float	b = 2 * v[0]*p[0] + 2*v[1]*p[1]; 
	float	c = (- r*r + p[0]*p[0] + p[1]*p[1]);
	float	g;
	float	m;
	float	alpha = b * b -4 * a *c;

	if (alpha < 0)
		printf("No intersection point.\n");
	if (alpha == 0)
	{
		g = -(b/(2 * a));
		//printf("%f\n", g);
		printf("1 intersection point :\n");
		printf("(%.3f, %.3f, %.3f)", p[0]+ g * v[0],	\
		       p[1]+ g * v[1], p[2]+ g * v[2]);
	}
	if (alpha > 0)
	{
		printf("2 intersection point:\n");
		g = (-b - sqrt(alpha)) / (2 * a);
		m = (-b + sqrt(alpha)) / (2 * a);
		printf("(%.3f, %.3f, %.3f)\n", p[0]+ g * v[0],	\
		       p[1]+ g * v[1], p[2]+ g * v[2]);
		printf("(%.3f, %.3f, %.3f)\n", p[0]+ m * v[0],	\
		       p[1]+ m * v[1], p[2]+ m * v[2]);
	}
	//printf("aplha:%f\n", alpha);
}
void create_alpha (char **av)
{
	int	v[3] = {my_get_nbr(av[5]),my_get_nbr(av[6]),	\
			my_get_nbr(av[7])};
	int	p[3] = {my_get_nbr(av[2]),my_get_nbr(av[3]),\
			my_get_nbr(av[4])};
	int	r = my_get_nbr(av[8]);
	
	line(v,p);	
	//printf("v:%d,%d,%d\n", v[0],v[1]*v[1],v[2]);
	//printf("p:%d,%d,%d\n", p[0],p[1],p[2]);
	if (av[1][0] == '1')
		intersection(v,p,r);
	else if (av[1][0] == '2')
		cylinder(v,p,r);
	//get_t_num((float)alpha,v,p,r);
}

int main(int ac, char **av)
{
	
	error(ac);
	if (av[1][0] == '1')
		sphere(av);
	if (av[1][0] == '2')
		cilinder(av);
	if (av[1][0] == '1' || av[1][0] == '2')
		create_alpha(av);
	
}
