/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 15:32:36 by apetit            #+#    #+#             */
/*   Updated: 2014/05/18 15:48:35 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../includes/ft_minishell.h"

void	ft_display_prompt(t_shell **shell)
{
	ft_printf("\033[34m%s\033[36m)>\033[0m ", ft_get_pwd());
	if (get_next_line(0, &(*shell)->input) > 0)
	{
		(*shell)->path = ft_get_envpath((*shell)->env);
		ft_parse_input(&(*shell));
	}
	else
		ft_exit(&(*shell));
}
