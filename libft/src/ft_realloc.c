/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 15:21:51 by apetit            #+#    #+#             */
/*   Updated: 2013/12/23 14:57:19 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

void	*ft_realloc(void *ptr, int size, int type_size)
{
	char	*new_ptr;

	new_ptr = malloc(size * type_size);
	if (new_ptr == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		ft_memcpy(new_ptr, ptr, (size - 1) * type_size);
		free (ptr);
	}
	return (new_ptr);
}
