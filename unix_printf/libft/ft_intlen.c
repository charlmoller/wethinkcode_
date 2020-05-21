/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:50:02 by cmoller           #+#    #+#             */
/*   Updated: 2018/05/21 13:31:00 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int *table)
{
	int	len;

	len = 0;
	while (table[len] != 0)
	{
		len++;
	}
	return (len);
}