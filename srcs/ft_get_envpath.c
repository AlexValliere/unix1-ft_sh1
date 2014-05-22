/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 14:54:40 by apetit            #+#    #+#             */
/*   Updated: 2014/02/05 15:07:35 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../includes/ft_minishell.h"

char	**ft_get_envpath(char **env)
{
	char	*get_path_line;
	char	**path;
	int		i;

	get_path_line = NULL;
	path = NULL;
	i = 0;
	while (env[i] && get_path_line == NULL)
	{
		if (ft_strncmp("PATH", env[i], 3) == 0)
			get_path_line = ft_strsub(ft_strdup(env[i]),
										5,
										ft_strlen(env[i]) - 5);
		++i;
	}
	if (get_path_line != NULL)
		path = ft_strsplit(get_path_line, ':');
	return (path);
}
