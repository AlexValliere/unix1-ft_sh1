/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_environ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:17:12 by alex              #+#    #+#             */
/*   Updated: 2014/04/27 02:15:34 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>
#include "../includes/ft_minishell.h"

char	**ft_dup_environ(const char **environ)
{
	char	**copie;
	size_t	i;

	i = 0;
	while (environ[i])
		i++;
	copie = (char **)malloc((i + 1) * sizeof(char *));
	if (copie == NULL)
		return (NULL);
	i = 0;
	while (environ[i])
	{
		copie[i] = ft_strdup(environ[i]);
		++i;
	}
	copie[i] = 0;
	return (copie);
}
