/* 
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "list.h"
#include <stdio.h>
#include <unistd.h>

/*int get_t_num(int alpha, int *v, int *p, int r)
{
	int	t;

	t = - (2*v[0]*p[0] + 2*v[1]*p[1] + 2*v[2]*p[2]);
	}*/
int my_get_nbr(char *str)
{
        int i;
        int n;
        int j;

	j = 0;
	i = 0;
        n = 0;
        while(str[j] == '-' || str[j] == '+')
                j++;
        i = j;
        while(str[i] != '\0')
        {
                if((str[i] < '0' || str[i] > '9'))
		{
			printf("only numbers");
			exit (84);
		}
		//printf("ninside:%d\n",n);
                n = n + str[i] - '0';
                n = n * 10;
                i++;
                }
        n = n / 10;
	//printf("n:%d\n",n);
        if(str[j - 1] == '-')
                return(-1 * n);
        else
                return(n);
}/*
int main()
{
	int n;
        char *str = "--243";
	printf("%s\n", str);
        n = my_get_nbr(str);
	printf("final:%d\n",n);
        return(0);
	}*/

