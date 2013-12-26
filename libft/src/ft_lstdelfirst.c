/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 00:14:08 by alexandre         #+#    #+#             */
/*   Updated: 2013/12/26 16:39:11 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	ft_lstdelfirst(t_list **alst)
{
	t_list	*tmp_list;

	tmp_list = NULL;
	if (ft_lstsize(*alst) > 1)
	{
			tmp_list = (*alst)->next;
			ft_memdel(&((*alst)->content));
			(*alst)->next = NULL;
			*alst = tmp_list;
	}
	else
	{
		ft_memdel(&((*alst)->content));
		(*alst)->next = NULL;
		*alst = NULL;
	}
}
