/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                       :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:01:12 by simzam            #+#    #+#             */
/*   Updated: 2016/05/17 21:47:01 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*nstr;

	i = -1;
	if (s && f)
	{
		j = ft_strlen((char*)s);
		nstr = (char*)malloc(j * sizeof(char));
		while (*(s + ++i) != '\0')
			nstr[i] = f(*(s + i));
		return (nstr);
	}
	return (NULL);
}
