/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:45:05 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/09 13:22:01 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float rando(void)
{
	return ((float)rand()/(float)(RAND_MAX));
}

long		get_micro_time(void)
{
	struct timeval		currenttime;

	gettimeofday(&currenttime, NULL);
	return (currenttime.tv_sec * (int)1e6 + currenttime.tv_usec);
}
