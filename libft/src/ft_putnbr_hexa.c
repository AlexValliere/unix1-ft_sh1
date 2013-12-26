/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 15:37:46 by apetit            #+#    #+#             */
/*   Updated: 2013/12/23 15:02:36 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_hexa(unsigned int nb, char *base)
{
	unsigned int	start;
	unsigned int	end;

	end = nb % 16;
	start = (nb - end) / 16;
	if (start)
		ft_putnbr_hexa(start, base);
	ft_putchar(base[end]);
}
