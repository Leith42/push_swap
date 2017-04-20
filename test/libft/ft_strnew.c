/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                       :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:01:12 by simzam            #+#    #+#             */
/*   Updated: 2016/05/17 21:47:01 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = -1;
	new = malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	while (++i < size)
		*(new + i) = '\0';
	return (new);
}
