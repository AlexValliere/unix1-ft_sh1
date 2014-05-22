/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 14:23:14 by apetit            #+#    #+#             */
/*   Updated: 2014/02/06 14:44:51 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/param.h>
#include <unistd.h>
#include <libft.h>
#include "../includes/ft_minishell.h"

char	*ft_get_pwd(void)
{
	char	*pwd;

	pwd = NULL;
	pwd = (char *)malloc((MAXPATHLEN + 1) * sizeof(char));
	if (pwd != NULL)
	{
		ft_bzero(pwd, 0);
		pwd = getcwd(pwd, MAXPATHLEN);
	}
	return (pwd);
}
