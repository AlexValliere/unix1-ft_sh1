/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 13:21:40 by apetit            #+#    #+#             */
/*   Updated: 2013/12/23 14:45:18 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*p_ret;
	size_t	i;

	if (!s)
		return (NULL);
	i = start;
	if (len > (ft_strlen(s) - start))
		ret = 0;
	else
	{
		ret = malloc(len * sizeof(char) + 1);
		ft_bzero(ret, ft_strlen(ret));
		p_ret = ret;
		while (i < (start + len))
		{
			*p_ret = *(s + i);
			++p_ret;
			++i;
		}
		p_ret[i] = '\0';
	}
	return (ret);
}
