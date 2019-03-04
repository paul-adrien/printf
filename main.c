/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:39:38 by eviana            #+#    #+#             */
/*   Updated: 2019/03/04 11:16:01 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <time.h>
#include <limits.h>

char *randstring(int length, char *string)
{
	static int mySeed = 25011984;
	size_t stringLen = ft_strlen(string);
	char *randomString = NULL;

	srand(time(NULL) * length + ++mySeed);

	if (length < 1) {
		length = 1;
	}

	randomString = malloc(sizeof(char) * (length +1));

	if (randomString) {
		short key = 0;

		for (int n = 0; n < length; n++) {
			key = rand() % stringLen;
			randomString[n] = string[key];
		}

		randomString[length] = '\0';

		return randomString;
	}
	else {
		printf("No memory");
		exit(1);
	}
}

int             main(int ac, char **av)
{
	char    *str1;
	char    *str2;
	char    *str3;
	char    *str4;
	char    *str5;
	char    str6[1] = "d";
	char    *str7;
	//double	i = 1.1234567890123456789;

	if (ac == 1)
	{
		str1 = randstring(4, "- +0");
		str1[0] = '%';
		str2 = randstring(2, "0123456789");
		str3 = randstring(2, "0123456789");
		str3[0] = '.';
		str4 = randstring(1, "hl");
		str5 = randstring((rand() % 7), "0123456789");
		if (!(rand() % 3))
			str5[0] = '-';

		str7 = ft_strjoin(str1, ft_strjoin(str2, ft_strjoin(str3, ft_strjoin(str4, str6))));
		str7[10] = '\0';

		ft_putstr("RESULTS FOR : ");
		ft_putstr(str7);
		ft_putstr(" && ");
		ft_putstr(str5);
		ft_putstr("\n");
		ft_putstr("R1 |");
		ft_printf(str7, atol(str5));
		ft_putstr("|\n");
		ft_putstr("R2 |");
		printf(str7, atol(str5));
	}
	else if (ac == 2)
	{
		ft_putstr("MANUAL MODE :\n");
		ft_putstr("R1 |");
		ft_printf("%lo, %lo", 0, ULONG_MAX);
		ft_putstr("|\nR2 |");	
		printf("%lo, %lo", (unsigned long)0, ULONG_MAX);
	}
	else if (ac == 3)
	{
		ft_putstr("MANUAL MODE :\n");
		ft_putstr("R1 |");
		ft_printf(av[1], atoi(av[2]));
		//ft_putstr("|\nR2 |");
		//printf(av[1], atoi(av[2]));
	}
	else if (ac == 4)
	{
		/*ft_printf("\n");
		ft_printf("%%\n");
		ft_printf("%d\n", 42);
		ft_printf("%d%d\n", 42, 41);*/
		ft_printf("%d%d%d\n", 42, 43, 44);
		/*ft_printf("%ld\n", 2147483647);
		ft_printf("%lld\n", 9223372036854775807);
		ft_printf("%x\n", 505);
		ft_printf("%X\n", 505);
		ft_printf("%p\n", &ft_printf);
		ft_printf("%20.15d\n", 54321);
		ft_printf("%-10d\n", 3);
		ft_printf("% d\n", 3);
		ft_printf("%+d\n", 3);
		ft_printf("%010d\n", 1);
		ft_printf("%hhd\n", 0);
		ft_printf("%jd\n", 9223372036854775807);
		ft_printf("%zd\n", 4294967295);
		ft_printf("%\n");
		ft_printf("%U\n", 4294967295);
		ft_printf("%u\n", 4294967295);
		ft_printf("%o\n", 40);
		ft_printf("%%#08x\n", 42);
		ft_printf("%x\n", 1000);
		ft_printf("%#X\n", 1000);
		ft_printf("%s\n", NULL);
		ft_printf("%S\n", L"ݗݜशব");
		ft_printf("%s%s\n", "test", "test");
		ft_printf("%s%s%s\n", "test", "test", "test");
		ft_printf("%C\n", 15000);*/
	}
	//else
	//	ft_putstr("wrong number of inputs");
	(void)ac;
	(void)av;
	return (0);
}
