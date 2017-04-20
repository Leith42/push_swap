/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                      :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:01:12 by simzam            #+#    #+#             */
/*   Updated: 2016/05/17 21:47:01 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	fin;
	size_t	debut;
	size_t	cpt;
	char	*news;

	fin = 0;
	debut = 0;
	cpt = -1;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (*(s + (--len)) == ' ' || *(s + len) == '\n' || *(s + len) == '\t')
		fin++;
	len = -1;
	while (*(s + (++len)) == ' ' || *(s + len) == '\n' || *(s + len) == '\t')
		debut++;
	len = ft_strlen(s) - (debut + fin);
	news = malloc(sizeof(char) * (len + 1));
	if (news == NULL)
		return (NULL);
	while (++cpt < len)
		*(news + cpt) = *(s + (cpt + debut));
	*(news + cpt) = '\0';
	return (news);
}
