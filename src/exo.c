/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:22:23 by aazri             #+#    #+#             */
/*   Updated: 2017/05/05 17:49:58 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>
#include <stdio.h>

void echange(int tab[], int i, int j)
{
	int temp;
    if (i != j)
	{
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
}

void tri_selection(int tab[], int taille)
{
    int i, j, i_min;

	while (i < taille - 1)
	{
		i_min = i;
		j = i + 1;
		while (j < taille)
		{
			if (tab[j] < tab[i_min])
				i_min = j;
			j++;
		}
		echange(tab, i, i_min);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	int tab[] = {8, 9, 6, 7, 4, 5, 2, 3, 1, 0};
	tri_selection(tab, 10);
	int i = 0;
	while (i < 10)
		ft_printf("%d ", tab[i++]);
	return 0;
}
