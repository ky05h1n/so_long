/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:57:35 by enja              #+#    #+#             */
/*   Updated: 2022/05/14 22:11:42 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linecount.h"
#include <stdio.h>

int	ft_strlenn(char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char	*joinn(char *str, char *buff)
{
	char	*final;
	int		len;
	int		n;
	int		i;

	if (!str)
		return (ft_strdupn(buff));
	i = 0;
	n = 0;
	len = ft_strlenn(str) + ft_strlenn(buff);
	final = malloc(len + 1);
	while (str[i])
	{
		final[i] = str[i];
		i++;
	}
	while (buff[n])
	{
		final[i++] = buff[n++];
	}
	final[i] = '\0';
	free(str);
	return (final);
}

char	*buff_readn(char *temp, int fd)
{
	char		*buff;
	int			n;

	n = 1;
	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	while (check_nn(temp) == -1 && n != 0)
	{	
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			free(temp);
			free(buff);
			temp = NULL;
			return (temp);
		}
		buff[n] = '\0';
		temp = joinn(temp, buff);
	}
	if (ft_strlenn(temp) == 0 && n == 0)
	{
		free(temp);
		temp = NULL;
	}
	free(buff);
	return (temp);
}

char	*linecount(int fd)
{
	static char	*temp = NULL;
	char		*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (check_nn(temp) == -1)
		temp = buff_readn(temp, fd);
	if (!temp)
		return (NULL);
	if (check_nn(temp) != -1)
	{
		string = check_befor_nn(temp);
		temp = check_after_nn(temp, check_nn(temp) + 1);
		return (string);
	}
	string = temp;
	temp = NULL;
	return (string);
}
