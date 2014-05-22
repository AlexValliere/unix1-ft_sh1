/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/01 22:50:52 by apetit            #+#    #+#             */
/*   Updated: 2014/05/18 15:51:15 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef	void	(*t_flag)(va_list);

char			*ft_printf_flags_tab(char *flags_tab);
t_flag			*ft_printf_flags_tab_fct(t_flag *flags_tab_fct);
int				ft_printf_match_fct(const char *format, char *flags_tab,
									t_flag *flags_tab_fct, va_list args);
void			ft_printf_d(va_list list);
void			ft_printf_i(va_list list);
void			ft_printf_c(va_list list);
void			ft_printf_s(va_list list);
void			ft_printf_p(va_list list);
void			ft_printf_o(va_list list);
void			ft_printf_x(va_list list);
void			ft_printf_upperx(va_list list);
void			ft_printf_u(va_list list);

#endif
