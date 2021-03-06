/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/07 17:03:48 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float	vec3dot(t_vec3 *u, t_vec3 *v)
{
	return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

float	vec3angle(t_vec3 *u, t_vec3 *v)
{
	return (acos(vec3dot(u, v) / (vec3len(u) * vec3len(v))));
}

t_vec3	vec3add(t_vec3 *f, t_vec3 *s)
{
	t_vec3 ret;

	ret.x = f->x + s->x;
	ret.y = f->y + s->y;
	ret.z = f->z + s->z;
	return (ret);
}

t_vec3	vec3sub(t_vec3 *f, t_vec3 *s)
{
	t_vec3 ret;

	ret.x = f->x - s->x;
	ret.y = f->y - s->y;
	ret.z = f->z - s->z;
	return (ret);
}

float	vec3len(t_vec3 *p)
{
	return (sqrt((p->x * p->x) + (p->y * p->y) + (p->z * p->z)));
}
