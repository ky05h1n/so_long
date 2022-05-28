/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:25:36 by enja              #+#    #+#             */
/*   Updated: 2022/05/19 00:50:25 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_img_up(int i, int n)
{
	mlx_put_image_to_window(g_mlx, g_mlx_win, g_playerup, n * 64, --i * 64);
	if (g_map[i][n] == 'C')
		g_collectcounter++;
	if (g_collectcounter == g_coin)
		to_finish();
	g_map[i][n] = 'P';
	g_map[++i][n] = '0';
	mlx_put_image_to_window(g_mlx, g_mlx_win, g_backround, n * 64, i * 64);
	g_playermove++;
	ft_printf("%d\n", g_playermove);
}

void	render_img_down(int i, int n)
{
	mlx_put_image_to_window(g_mlx, g_mlx_win, g_playerdown, n * 64, ++i * 64);
	if (g_map[i][n] == 'C')
		g_collectcounter++;
	if (g_collectcounter == g_coin)
		to_finish();
	g_map[i][n] = 'P';
	g_map[--i][n] = '0';
	mlx_put_image_to_window(g_mlx, g_mlx_win, g_backround, n * 64, i * 64);
	g_playermove++;
	ft_printf("%d\n", g_playermove);
}

void	render_img_left(int i, int n)
{
	mlx_put_image_to_window(g_mlx, g_mlx_win, g_playerleft, --n * 64, i * 64);
	if (g_map[i][n] == 'C')
		g_collectcounter++;
	if (g_collectcounter == g_coin)
		to_finish();
	g_map[i][n] = 'P';
	g_map[i][++n] = '0';
	mlx_put_image_to_window(g_mlx, g_mlx_win, g_backround, n * 64, i * 64);
	g_playermove++;
	ft_printf("%d\n", g_playermove);
}

void	render_img_right(int i, int n)
{
	mlx_put_image_to_window(g_mlx, g_mlx_win, g_playerright, ++n * 64, i * 64);
	if (g_map[i][n] == 'C')
		g_collectcounter++;
	if (g_collectcounter == g_coin)
		to_finish();
	g_map[i][n] = 'P';
	g_map[i][--n] = '0';
	mlx_put_image_to_window(g_mlx, g_mlx_win, g_backround, n * 64, i * 64);
	g_playermove++;
	ft_printf("%d\n", g_playermove);
}

void	to_finish(void)
{
	int	i;
	int	n;

	i = 0;
	while (i < g_lin)
	{
		n = 0;
		while (g_map[i][n])
		{
			if (g_map[i][n] == 'E')
				mlx_put_image_to_window(g_mlx, g_mlx_win,
					g_opendoor, n * 64, i * 64);
			n++;
		}
		i++;
	}
}
