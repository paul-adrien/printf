/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:17:51 by eviana            #+#    #+#             */
/*   Updated: 2019/02/19 17:33:52 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else
		return (nb * ft_power(nb, power - 1));
}

static char		*ft_nbr_analysis(char *str, int *pos_neg, int mode)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	if (!(str2 = (char*)malloc(sizeof(char) * 1000)))
		return (NULL);
	*pos_neg = (str[i] == '-' ? -1 : *pos_neg);
	((str[i] == '-' || str[i] == '+') ? i++ : i);
	while (str[i + j] != '\0')
	{
		str2[j] = str[i + j];
		j++;
	}
	i = 0;
	while (j > 0 && mode == 2)
	{
		str2[i] = str[j - 1];
		i++;
		j--;
	}
	str2[i + j] = '\0';
	return (str2);
}

static int		bcheck(char *base)
{
	int	i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

static int		ft_compute(char *nbr, char *base, long res)
{
	int i;
	int j;
	int k;
	int n;

	i = 0;
	n = 0;
	while (nbr[i] != '\0')
		i++;
	while (i > 0)
	{
		j = 0;
		k = 0;
		while (base[j] != '\0')
			j++;
		while (nbr[i - 1] != base[k] && base[k] != '\0')
			k++;
		if (k == j)
			return (-1);
		res = res + (k * ft_power(bcheck(base), n));
		n++;
		i--;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		pos_neg;
	long	res1;
	int		i;

	res1 = 0;
	pos_neg = 1;
	i = 0;
	nbr = ft_nbr_analysis(nbr, &pos_neg, 1);
	if (bcheck(base_from) == 0 || bcheck(base_to) == 0 || nbr[0] == '\0'
			|| ft_compute(nbr, base_from, 0) == -1)
		return (0);
	res1 = ft_compute(nbr, base_from, 0);
	if (!(nbr = (char*)malloc(sizeof(char) * (res1 / bcheck(base_to) + 1))))
		return (NULL);
	nbr[0] = (res1 == 0 ? base_to[0] : nbr[0]);
	while (res1 != 0)
	{
		nbr[i] = base_to[res1 % bcheck(base_to)];
		res1 = res1 / bcheck(base_to);
		i++;
	}
	nbr[i] = (pos_neg == -1 ? '-' : nbr[i]);
	nbr = ft_nbr_analysis(nbr, &pos_neg, 2);
	return (nbr);
}
