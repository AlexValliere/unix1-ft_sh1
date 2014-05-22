/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 15:08:36 by apetit            #+#    #+#             */
/*   Updated: 2014/05/18 16:02:34 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <libft.h>
#include "../includes/ft_minishell.h"

int			ft_set_binpath(t_shell **shell)
{
	int		i;

	i = 0;
	if ((*shell)->path != NULL)
	{
		(*shell)->binpath = (*shell)->argv[0];
		if (access((*shell)->binpath, F_OK) == 0)
			return (0);
		while ((*shell)->path[i] && (*shell)->argv[0])
		{
			(*shell)->binpath = ft_strjoin((*shell)->path[i], "/");
			(*shell)->binpath = ft_strjoin((*shell)->binpath,
											(*shell)->argv[0]);
			if (access((*shell)->binpath, F_OK) == 0)
				return (0);
			++i;
		}
		if ((*shell)->binpath)
			free((*shell)->binpath);
		(*shell)->binpath = NULL;
		ft_printf("%s : command not found\n", (*shell)->argv[0]);
	}
	else
		ft_printf("bash: %s: Undefined environment PATH\n", (*shell)->argv[0]);
	return (-1);
}

int			ft_exec_bin(t_shell **shell)
{
	pid_t	cpid;

	if (ft_set_binpath(&(*shell)) == 0)
	{
		cpid = fork();
		if (cpid != -1)
		{
			if (cpid == 0)
				execve((*shell)->binpath, (*shell)->argv, (*shell)->env);
			else
				waitpid(cpid, 0, 0);
		}
	}
	return (0);
}
