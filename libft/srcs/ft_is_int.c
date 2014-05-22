/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 02:19:24 by apetit            #+#    #+#             */
/*   Updated: 2014/03/07 23:56:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"

int	ft_is_int(char const *str)
{
	int		nbr;
	char	*tmp;
	int		is_int;
	int		if_plus_or_minus;

	is_int = 0;
	if (str)
	{
		if_plus_or_minus = (str[0] == '+' || str[0] == '-') ? 1 : 0;
		nbr = ft_atoi(str);
		tmp = ft_itoa(nbr);
		if (ft_strcmp(tmp, str + if_plus_or_minus) == 0)
			is_int = 1;
	}
	return (is_int);
}
