/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_count1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:58:41 by enja              #+#    #+#             */
/*   Updated: 2022/05/19 17:50:11 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linecount.h"

int	check_nn(char *last)
{
	int	a;

	a = 0;
	if (!last)
		return (-1);
	while (last[a])
	{
		if (last[a] == '\n')
			return (a);
		a++;
	}
	return (-1);
}

char	*check_befor_nn(char	*str)
{
	int		n;
	char	*exclude_n;

	n = 0;
	exclude_n = malloc(ft_strlenn(str) + 1);
	while (str[n] && str[n] != '\n')
	{
			exclude_n[n] = str[n];
			n++;
	}
	exclude_n[n] = str[n];
	n++;
	exclude_n[n] = '\0';
	return (exclude_n);
}

char	*ft_strdupn(char	*str)
{
	char	*dest;
	int		a;
	int		len;

	a = 0;
	len = ft_strlenn(str);
	dest = malloc(len + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	while (str[a])
	{
		dest[a] = str[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	*check_after_nn(char *str, int len)
{
	char	*ret;

	ret = ft_strdupn(str + len);
	free(str);
	return (ret);
}

void	check_argument(char *av)
{
	t_dta	m;

	m.ber = ".ber";
	m.a = 0;
	while (av[m.a])
		m.a++;
	m.a--;
	m.n = 3;
	while (m.n >= 0)
	{
		if (av[m.a] == m.ber[m.n])
		{
			m.a--;
			m.n--;
		}
		else
		{
			write(1, "Error\nThe file is not a '.ber' file", 35);
			exit(1);
		}
	}
}
