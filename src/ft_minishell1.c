/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:30:17 by alexandre         #+#    #+#             */
/*   Updated: 2013/12/28 00:42:16 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include "../includes/ft_minishell1.h"

void		ft_freecharptr(char **ptr)
{
	if (*ptr)
		free(*ptr);
}

char		ft_getchar(void)
{
	char	c;

	return ((read(0, &c, 1) ==1 ) ? c : 0);
}

int			ft_get(char **input)
{
	int		i;

	i = 0;
	ft_freecharptr(&(*input));
	while (*((*input) + i) != '\n')
	{
		ft_putstr("test\n");
		ft_realloc(*input, i + 1, sizeof(char));
		*((*input) + i) = ft_getchar();
		ft_putstr("input : ");
		ft_putstr(*input);
		ft_putchar('\n');
	}
	ft_realloc(*input, i + 1, sizeof(char));
	*((*input) + i) = 0;
	return (0);
}

int			main(int argc, char const *argv[])
{
	char	*input;

	input = malloc(sizeof(char));
	input[0] = 0;
	while (ft_strcmp(input, "exit") != 0)
	{
		ft_get(&input);
		ft_putstr("Input : ");
		ft_putstr(input);
		ft_putchar('\n');
	}
	return (0);
}
