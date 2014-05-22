/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 17:50:29 by alex              #+#    #+#             */
/*   Updated: 2014/04/24 16:58:35 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "../includes/ft_minishell.h"

static int	ft_unset_var_from_env(t_shell **shell)
{
	int		line_to_remove;
	int		i;

	i = 0;
	line_to_remove = -1;
	while ((*shell)->env[i] && line_to_remove == -1)
	{
		if (ft_strncmp(ft_strjoin(ft_strtoupper((*shell)->argv[1]), "="),
			(*shell)->env[i], ft_strlen((*shell)->argv[1])) == 0)
			line_to_remove = i;
		++i;
	}
	ft_printf("Line to remove : %s\n", (*shell)->env[line_to_remove]);
	i = 0;
	while ((*shell)->env[i])
		++i;
	(*shell)->env[line_to_remove] = ft_strdup((*shell)->env[i - 1]);
	(*shell)->env[i - 1] = 0;
	return (0);
}

static int	ft_valid_unsetenv_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 0)
			return (0);
		++i;
	}
	return (1);
}

int			ft_unsetenv(t_shell **shell)
{
	if ((*shell)->argc == 2)
	{
		if (ft_valid_unsetenv_arg((*shell)->argv[1]) == 1)
			ft_unset_var_from_env(&(*shell));
	}
	return (0);
}
