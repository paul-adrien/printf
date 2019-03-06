/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:07:13 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/06 16:30:51 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*st_width_preci(t_asset asset, char *str, int i, int j)
{
	char	*str2;
	int		k;

	k = -1;
	if (i < j && i != 0)
		i = j;
	if (!(str2 = ft_strnew(i + 1)))
		return (NULL);
	if (ft_strchr(asset.flags, '-') || i == j)
	{
		while (++k < j)
			str2[k] = str[k];
		while (k < i)
			str2[k++] = ' ';
	}
	else
	{
		while (--j >= 0)
			str2[--i] = str[j];
		while (i > 0 && ft_strchr(asset.flags, '0'))
			str2[--i] = '0';
		while (i > 0 && !ft_strchr(asset.flags, '0'))
			str2[--i] = ' ';
	}
	return (str2);
}

char		*ft_conv_s(t_asset asset, va_list ap)
{
	char	*str;
	int		k;
	int		j;

	k = 0;
	j = asset.precision;
	if (!(str = va_arg(ap, char*)))
	{
		if (!(str = ft_strnew(6)))
			return (NULL);
		str = sp_strnjoin(str, "(null)", 6, 0);
	}
	if (asset.width > ft_strlen(str) || (asset.precision < (int)ft_strlen(str)
				&& asset.precision < (int)asset.width
				&& asset.width > ft_strlen(str)))
		k = asset.width;
	if (asset.precision >= (int)asset.width && j < (int)ft_strlen(str))
		k = asset.precision;
	if ((int)asset.width > asset.precision && ft_strlen(str) > asset.width)
		k = asset.width;
	if (k == 0 && asset.precision != 0)
		k = ft_strlen(str);
	if (j == -1 || j >= (int)ft_strlen(str))
		j = ft_strlen(str);
	return (st_width_preci(asset, str, k, j));
}
