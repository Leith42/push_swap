/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec.c                                          :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:01:12 by simzam            #+#    #+#             */
/*   Updated: 2016/05/17 21:47:01 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	veclength(t_vec3 *vec)
{
	return (sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

void	vecnorm(t_vec3 *vec)
{
	double	n;

	n = 1.0 / sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	vec->x *= n;
	vec->y *= n;
	vec->z *= n;
}

double	vecdot(t_vec3 *a, t_vec3 *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}

t_vec3	veccross(t_vec3 *a, t_vec3 *b)
{
	t_vec3 v;

	v.x = a->y * b->z - a->z * b->y;
	v.y = a->z * b->x - a->x * b->z;
	v.z = a->x * b->y - a->y * b->x;
	return (v);
}

t_vec3	vecsub(t_vec3 *a, t_vec3 *b)
{
	t_vec3	v;

	v.x = a->x - b->x;
	v.y = a->y - b->y;
	v.z = a->z - b->z;
	return (v);
}
