/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:45:05 by cmoller           #+#    #+#             */
/*   Updated: 2018/07/31 13:31:26 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exit_error(char *s)
{
	ft_putstr("Error");
	ft_putstr(s);
	ft_putchar('\n');
	exit(0);
}
