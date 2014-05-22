/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 13:43:22 by apetit            #+#    #+#             */
/*   Updated: 2014/05/18 15:52:49 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (size > 0)
	{
		str = malloc(size * sizeof(char));
		if (str)
		{
			while (i < size)
			{
				str[i] = '\0';
				++i;
			}
			str[i] = '\0';
		}
	}
	else
		str = NULL;
	return (str);
}
