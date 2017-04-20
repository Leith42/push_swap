/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconc.c                                      :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:01:12 by simzam            #+#    #+#             */
/*   Updated: 2016/05/17 21:47:01 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strconc(char *str, char start, char end)
{
	int		i;
	int		s;
	char	*res;

	s = 0;
	i = 0;
	if (!str || !start || !end || start == end)
		return (NULL);
	while (str[s] && str[s] != start)
		s++;
	if (!str[s])
		return (NULL);
	while (str[s + i] && str[s + i] != end)
		i++;
	if (!str[s + i])
		return (NULL);
	res = ft_strsub(str, s + 1, i - 1);
	return (res);
}
