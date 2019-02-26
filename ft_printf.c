/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:11 by eviana            #+#    #+#             */
/*   Updated: 2019/02/26 13:42:56 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	char	**tab;
	char	*print;
	int		printlength;

	va_start(ap, format);
	tab = ft_formattotab(format);
	//if (!(ft_check_arg_nb(tab, ap)))
	//{
	//	va_end(ap);
	//	return (-1);
	//}
	if (!(print = ft_dispatcher(tab, ap)))
	{
		va_end(ap);
		return (-1);
	}
	ft_putstr(print);
	printlength = ft_strlen(print);
	va_end(ap);
	return (printlength);
}
