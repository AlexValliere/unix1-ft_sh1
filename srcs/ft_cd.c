/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 01:49:34 by alex              #+#    #+#             */
/*   Updated: 2014/04/27 02:20:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/param.h>
#include <unistd.h>
#include <libft.h>
#include "../includes/ft_minishell.h"

static int	ft_update_envoldpwd(t_shell **shell)
{
	int		i;

	i = 0;
	while ((*shell)->env[i])
	{
		if (ft_strncmp("OLDPWD", (*shell)->env[i], 5) == 0)
		{
			(*shell)->env[i] = ft_strdup((*shell)->pwd);
			(*shell)->env[i] = ft_strjoin("OLDPWD=", (*shell)->env[i]);
			return (0);
		}
		++i;
	}
	return (-1);
}

static int	ft_update_envpwd(t_shell **shell)
{
	int		i;

	ft_update_envoldpwd(&(*shell));
	(*shell)->oldpwd = ft_get_envoldpwd((*shell)->env);
	i = 0;
	while ((*shell)->env[i])
	{
		if (ft_strncmp("PWD", (*shell)->env[i], 2) == 0)
		{
			(*shell)->env[i] = ft_strjoin("PWD=", ft_get_pwd());
			(*shell)->pwd = ft_get_envpwd((*shell)->env);
			return (0);
		}
		++i;
	}
	return (-1);
}

static int	ft_update_envcdpath(t_shell **shell)
{
	int		i;

	i = 0;
	while ((*shell)->env[i])
	{
		if (ft_strncmp("CDPATH", (*shell)->env[i], 5) == 0)
		{
			(*shell)->env[i] = ft_strjoin("CDPATH=", ft_get_pwd());
			return (0);
		}
		++i;
	}
	(*shell)->env = ft_chartab2inc((*shell)->env);
	(*shell)->env[i] = ft_strjoin("CDPATH=", ft_get_pwd());
	return (0);
}

static char	*ft_set_relpwd(char *path)
{
	char	*pwd;

	pwd = NULL;
	pwd = ft_get_pwd();
	if (pwd != NULL)
	{
		pwd = ft_strjoin(pwd, "/");
		pwd = ft_strjoin(pwd, path);
	}
	return (pwd);
}

int			ft_cd(t_shell **shell)
{
	char	*path;

	if ((*shell)->argv[1])
	{
		path = ((*shell)->argv[1][0] && (*shell)->argv[1][0] != '/') ?
			ft_set_relpwd((*shell)->argv[1]) : ft_strdup((*shell)->argv[1]);
		if ((*shell)->argv[1][0] == '-' && !(*shell)->argv[1][1])
		{
			if ((*shell)->oldpwd != NULL)
				path = (*shell)->oldpwd;
			else
				ft_printf("bash: cd: << OLDPWD >> undefined\n");
		}
		if (access(path, F_OK) == 0)
		{
			chdir(path);
			ft_update_envpwd(shell);
			ft_update_envcdpath(shell);
			return (0);
		}
		else
			ft_printf("bash: cd: %s: Cannot acces file or directory.\n",
					(*shell)->argv[1]);
	}
	return (-1);
}
