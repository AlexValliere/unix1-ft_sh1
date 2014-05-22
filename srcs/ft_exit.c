/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 18:18:20 by alex              #+#    #+#             */
/*   Updated: 2014/05/18 15:17:06 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <libft.h>
#include "../includes/ft_minishell.h"

void	ft_exit(t_shell **shell)
{
	int	i;

	i = 0;
	while ((*shell)->env[i])
		free((*shell)->env[i++]);
	if ((*shell)->env)
		free((*shell)->env);
	if ((*shell)->input)
		free((*shell)->input);
	i = 0;
	while ((*shell)->argv[i])
		free((*shell)->argv[i++]);
	if ((*shell)->argv)
		free((*shell)->argv);
	(*shell)->pid = 0;
}
