/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_environ.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:27:39 by apetit            #+#    #+#             */
/*   Updated: 2014/05/18 15:54:56 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../includes/ft_minishell.h"

void	ft_print_environ(t_shell *shell)
{
	int	i;

	if (shell->env)
	{
		i = 0;
		while (shell->env[i])
		{
			ft_printf("%s\n", shell->env[i]);
			++i;
		}
	}
}
