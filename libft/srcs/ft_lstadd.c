/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 16:06:24 by apetit            #+#    #+#             */
/*   Updated: 2014/04/20 01:41:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*tmp_list;

	if (*alst)
	{
		tmp_list = *alst;
		*alst = new;
		(*alst)->next = tmp_list;
	}
}
