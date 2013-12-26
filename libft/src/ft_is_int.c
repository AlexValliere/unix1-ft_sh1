/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 02:19:24 by alexandre         #+#    #+#             */
/*   Updated: 2013/12/26 17:01:35 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_is_int(char const *str)
{
	int		nbr;
	char	*tmp;
	int		is_int;

	nbr = ft_atoi(str);
	tmp = ft_itoa(nbr);
	if (ft_strcmp(tmp, str) == 0)
		is_int = 1;
	else
		is_int = 0;
	return (is_int);
}
