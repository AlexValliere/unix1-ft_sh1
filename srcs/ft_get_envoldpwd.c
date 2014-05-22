/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envoldpwd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 01:18:54 by alex              #+#    #+#             */
/*   Updated: 2014/05/18 15:54:14 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../includes/ft_minishell.h"

char	*ft_get_envoldpwd(char **env)
{
	char	*get_oldpwd_line;
	int		i;

	get_oldpwd_line = NULL;
	i = 0;
	while (env[i] && get_oldpwd_line == NULL)
	{
		if (ft_strncmp("OLDPWD", env[i], 5) == 0)
		{
			get_oldpwd_line = ft_strsub(ft_strdup(env[i]),
										7,
										ft_strlen(env[i]) - 7);
		}
		++i;
	}
	return (get_oldpwd_line);
}
