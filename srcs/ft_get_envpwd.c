/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envpwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 01:18:54 by alex              #+#    #+#             */
/*   Updated: 2014/05/18 15:54:35 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../includes/ft_minishell.h"

char	*ft_get_envpwd(char **env)
{
	char	*get_pwd_line;
	int		i;

	get_pwd_line = NULL;
	i = 0;
	while (env[i] && get_pwd_line == NULL)
	{
		if (ft_strncmp("PWD", env[i], 2) == 0)
		{
			get_pwd_line = ft_strsub(ft_strdup(env[i]),
										4,
										ft_strlen(env[i]) - 4);
		}
		++i;
	}
	return (get_pwd_line);
}
