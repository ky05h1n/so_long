/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:06:14 by enja              #+#    #+#             */
/*   Updated: 2022/05/19 00:23:45 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(void)
{
	int	n;
	int	i;

	i = 0;
	while (i < g_lin)
	{
		n = 0;
		while (g_map[i][n])
		{
			if (g_map[i][n] == 'P' && g_map[i - 1][n] != '1')
			{
				if (g_map[i - 1][n] != 'E')
					render_img_up(i, n);
				if (g_map[i - 1][n] == 'E' && g_collectcounter == g_coin)
				{
					g_playermove++;
					printf("%d\n", g_playermove);
					map_free();
				}
				return ;
			}
			n++;
		}
		i++;
	}
}

void	ft_move_down(void)
{
	int	n;
	int	i;

	i = 0;
	while (i < g_lin)
	{
		n = 0;
		while (g_map[i][n])
		{
			if (g_map[i][n] == 'P' && g_map[i + 1][n] != '1')
			{
				if (g_map[i + 1][n] != 'E')
					render_img_down(i, n);
				if (g_map[i + 1][n] == 'E' && g_collectcounter == g_coin)
				{
					g_playermove++;
					printf("%d\n", g_playermove);
					map_free();
				}
				return ;
			}
			n++;
		}
		i++;
	}
}

void	ft_move_left(void)
{
	int	n;
	int	i;

	i = 0;
	while (i < g_lin)
	{
		n = 0;
		while (g_map[i][n])
		{
			if (g_map[i][n] == 'P' && g_map[i][n - 1] != '1')
			{
				if (g_map[i][n - 1] != 'E')
					render_img_left(i, n);
				if (g_map[i][n - 1] == 'E' && g_collectcounter == g_coin)
				{
					g_playermove++;
					printf("%d\n", g_playermove);
					map_free();
				}
				return ;
			}
			n++;
		}
		i++;
	}
}

void	ft_move_right(void)
{
	int	n;
	int	i;

	i = 0;
	while (i < g_lin)
	{
		n = 0;
		while (g_map[i][n])
		{
			if (g_map[i][n] == 'P' && g_map[i][n + 1] != '1' )
			{
				if (g_map[i][n + 1] != 'E')
					render_img_right(i, n);
				if (g_map[i][n + 1] == 'E' && g_collectcounter == g_coin)
				{
					g_playermove++;
					printf("%d\n", g_playermove);
					map_free();
				}
				return ;
			}
			n++;
		}
		i++;
	}
}

void	map_free(void)
{
	int	a;

	a = 0;
	while (a < g_lin)
		free(g_map[a++]);
	free(g_map);
	exit(1);
}
