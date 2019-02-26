/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:04:18 by eviana            #+#    #+#             */
/*   Updated: 2019/02/26 15:06:14 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putull(unsigned long long n)
{
	if (n >= 10)
		ft_putull(n / 10);
	ft_putchar((n % 10) + '0');
}