/* 
** EPITECH PROJECT, 2018
** 
** File description:
**by mrnsapple 
*/

#include "list.h"
#include <stdio.h>
#include <unistd.h>

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
                if((str[i] < '0' || str[i] > '9') && (str[i] != '-'))
	        	exit (84);
		n = n + str[i] - '0';
                n = n * 10;
                i++;
                }
        n = n / 10;
	if(str[j - 1] == '-')
                return(-1 * n);
        else
                return(n);
}
