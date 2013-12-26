/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 22:49:29 by alexandre         #+#    #+#             */
/*   Updated: 2013/12/25 22:49:44 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_uint(unsigned int n)
{
	unsigned int	divide;

	if ((int)n == -1)
		ft_putstr("4294967295");
	else
	{
		divide = 1;
		while ((divide * 10) < n)
			divide *= 10;
		while (divide)
		{
			ft_putchar((char)((int)'0' + (int)(n / divide)));
			n -= ((n / divide) * divide);
			divide /= 10;
		}
	}
}
