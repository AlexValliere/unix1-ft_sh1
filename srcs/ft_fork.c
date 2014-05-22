/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:28:39 by apetit            #+#    #+#             */
/*   Updated: 2014/05/18 15:53:46 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <libft.h>
#include "../includes/ft_minishell.h"

int	ft_fork(t_shell **shell)
{
	if (((*shell)->pid = fork()) < 0)
	{
		ft_printf("Error on fork function.\n");
		return (-1);
	}
	if ((*shell)->pid)
	{
		if (waitpid((*shell)->pid, 0, 0) < 0)
		{
			ft_printf("Error on waitpid function\n");
			return (-1);
		}
		return (0);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		return (0);
	}
	return (-1);
}
