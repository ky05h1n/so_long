/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:56:17 by enja              #+#    #+#             */
/*   Updated: 2022/05/19 18:17:24 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*n_remover(char *string)
{
	char	*str;
	int		a;
	int		b;

	b = ft_strlen(string);
	str = malloc(b + 1 * sizeof(char));
	a = 0;
	while (string[a] && string[a] != '\n')
	{
		str[a] = string[a];
		a++;
	}
	free(string);
	str[a] = '\0';
	return (str);
}

int	lines(int nd)
{
	char	*str;
	int		a;
	int		b;

	b = 0;
	str = linecount(nd);
	if (str == NULL || str[b] != '1')
		msg_error();
	a = 1;
	while (str)
	{
		if (str != NULL)
			free(str);
		str = linecount(nd);
		a++;
	}
	a--;
	return (a);
}

int	map_tchecker(char *str, int a)
{
	if (ft_strlen(str) != a--)
	{
		write(1, "Error\nThe Mapp Does not follow the Rules", 42);
		exit(1);
	}
	if (str[0] != str[a])
	{
		write(1, "Error\nThe Mapp Does not follow the Rules", 42);
		exit(1);
	}
	return (1);
}

void	map_load(char **map)
{
	t_data	src;

	src.i = 0;
	map_struct(map);
	while (src.i < g_lin)
	{
		src.n = 0;
		while (map[src.i][src.n])
		{
			if (map[src.i][src.n] == '1')
				map_set('1', src.i, src.n);
			if (map[src.i][src.n] == 'P')
				map_set('P', src.i, src.n);
			if (map[src.i][src.n] == 'C')
				map_set('C', src.i, src.n);
			if (map[src.i][src.n] == '0')
				map_set('0', src.i, src.n);
			if (map[src.i][src.n] == 'E')
				map_set('E', src.i, src.n);
			src.n++;
		}
		src.i++;
	}
}

int	main(int ac, char **av)
{
	int		fd;
	int		nd;

	if (ac == 2)
		check_argument(av[1]);
	if (ac == 2)
	{
		nd = open(av[1], O_RDONLY);
		g_lin = lines(nd);
		check_for_new_line(av[1]);
		fd = open(av[1], O_RDONLY);
		g_map = map_reader(fd, g_lin);
		second_checker(g_map);
		map_load(g_map);
		mlx_key_hook(g_mlx_win, key_hook, NULL);
		mlx_hook(g_mlx_win, 17, 0, win_destroy, NULL);
		mlx_loop(g_mlx);
	}
	else if (ac < 2)
		write(1, "Error\nNo map detected !", 24);
	else
		write(1, "Error\nMany argument detected !\n", 32);
	return (0);
}
