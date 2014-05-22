/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:51:41 by apetit            #+#    #+#             */
/*   Updated: 2014/05/18 15:55:13 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "../includes/ft_minishell.h"

static int	ft_add_var_to_env(t_shell **shell, int len, char *var_env)
{
	int		i;
	char	**env;

	env = malloc((len + 2) * sizeof(char *));
	if (env != NULL)
	{
		i = 0;
		while ((*shell)->env[i])
		{
			env[i] = ft_strdup((*shell)->env[i]);
			free((*shell)->env[i]);
			++i;
		}
		env[i] = ft_strdup(var_env);
		++i;
		env[i] = 0;
		(*shell)->env = env;
		return (0);
	}
	return (-1);
}

static int	ft_set_var_to_env(t_shell **shell)
{
	int		i;
	char	*var_env;

	i = 0;
	var_env = ft_strdup(ft_strtoupper((*shell)->argv[1]));
	var_env = ft_strjoin(var_env, "=");
	var_env = ft_strjoin(var_env, (*shell)->argv[2]);
	while ((*shell)->env[i])
	{
		if (ft_strncmp(ft_strjoin(ft_strtoupper((*shell)->argv[1]), "="),
			(*shell)->env[i], ft_strlen((*shell)->argv[1])) == 0)
		{
			(*shell)->env[i] = ft_strdup(var_env);
			return (0);
		}
		++i;
	}
	if (ft_add_var_to_env(shell, i, var_env) == 0)
		return (0);
	return (-1);
}

static int	ft_isvalid_setenv(char **argv)
{
	int		i;

	i = 0;
	while (argv[1][i] != 0)
	{
		if (ft_isalpha(argv[1][i]) == 0)
		{
			ft_printf("usage: setenv VAR value\n");
			ft_printf("\tVAR can only have [a-z][A-Z] characters\n");
			return (0);
		}
		++i;
	}
	i = 0;
	while (argv[2][i] != 0)
	{
		if (ft_isspace(argv[2][i]) == 1)
		{
			ft_printf("usage: setenv VAR value\n");
			ft_printf("\tvalue cannot have space characters\n");
			return (0);
		}
		++i;
	}
	return (1);
}

int			ft_setenv(t_shell **shell)
{
	if ((*shell)->argc == 3)
	{
		if (ft_isvalid_setenv((*shell)->argv) == 1)
			ft_set_var_to_env(shell);
	}
	else
		ft_printf("usage: setenv VAR value\n");
	return (0);
}
