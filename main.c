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

int error(int ac)
{
	if (ac != 9)
		return (0);
	return (1);
}

void sphere (char **av)
{
	printf("sphere of radius ");
	printf("%d\n", atoi(av[8]));
}

void cilinder(char **av)
{
	printf("cylinder of radius ");
	printf("%d\n", atoi(av[8]));
}

void line (int *v, int *p)
{
	printf("straight line going through the (%d,%d,%d) ",\
	       p[0],p[1],p[2]);
	printf("point and of direction vector (%d,%d,%d)\n",\
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
		printf("1 intersection point :\n");
		printf("(%.3f, %.3f, %.3f)\n", p[0]+ g * v[0],	\
		       p[1]+ g * v[1], p[2]+ g * v[2]);
	}
	if (alpha > 0)
	{
		printf("2 intersection points :\n");
		g = (-b - sqrt(alpha)) / (2 * a);
		m = (-b + sqrt(alpha)) / (2 * a);
		printf("(%.3f, %.3f, %.3f)\n", p[0]+ m * v[0],	\
		       p[1]+ m * v[1], p[2]+ m * v[2]);
		printf("(%.3f, %.3f, %.3f)\n", p[0]+ g * v[0], 	\
		       p[1]+ g * v[1], p[2]+ g * v[2]);
	}
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
		if (g >= 0 || g < 0)
		{
			printf("1 intersection point :\n");
			printf("(%.3f, %.3f, %.3f)\n", p[0]+ g * v[0],	\
			       p[1]+ g * v[1], p[2]+ g * v[2]);
		}
		else
			printf("There is an infinite number of intersection points.\n");
	}
	if (alpha > 0)
	{
		printf("2 intersection points :\n");
		g = (-b - sqrt(alpha)) / (2 * a);
		m = (-b + sqrt(alpha)) / (2 * a);
		printf("(%.3f, %.3f, %.3f)\n", p[0]+ m * v[0],	\
		       p[1]+ m * v[1], p[2]+ m * v[2]);
		printf("(%.3f, %.3f, %.3f)\n", p[0]+ g * v[0],	\
		       p[1]+ g * v[1], p[2]+ g * v[2]);
	}
}

void create_alpha (char **av)
{
	int	v[3] = {atoi(av[5]),atoi(av[6]),	\
			atoi(av[7])};
	int	p[3] = {atoi(av[2]), atoi(av[3]),\
			atoi(av[4])};
	int	r = atoi(av[8]);
	
	line(v,p);	
	if (av[1][0] == '1')
		intersection(v,p,r);
	if (av[1][0] == '2')
		cylinder(v,p,r);
}

int main(int ac, char **av)
{
	if(error(ac) == 0)
		return (84);
	number(ac, av);
	
	if (av[1][0] == '1')
		sphere(av);
	if (av[1][0] == '2')
		cilinder(av);
	if (av[1][0] == '1' || av[1][0] == '2')
		create_alpha(av);
	if (av[1][0] == '3')
	{
		if (atoi(av[8]) < 0 || atoi(av[8]) > 360)
			exit (84);
		return (0);
	}
	return (0);
}
