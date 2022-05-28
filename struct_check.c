/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:28:10 by enja              #+#    #+#             */
/*   Updated: 2022/05/18 23:32:34 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	envaroment_player_check(void)
{
	t_inf	r;

	r.map_rule = "10CPE";
	r.idx = 0;
	r.sin = 0;
	while (r.idx < g_lin)
	{
		r.ndx = 0;
		while (g_map[r.idx][r.ndx])
		{
			r.a = 0;
			while (r.map_rule[r.a] && r.sin != 1)
			{
				if (r.map_rule[r.a] == g_map[r.idx][r.ndx])
					r.sin = 1;
				r.a++;
			}
			r.ndx++;
			if (r.sin != 1)
				msg_error();
			r.sin = 0;
		}
		r.idx++;
	}
}

void	map_set(char checker, int i, int n)
{
	if (checker == '1')
		mlx_put_image_to_window(g_mlx, g_mlx_win, g_wall,
			n * 64, i * 64);
	if (checker == 'P')
		mlx_put_image_to_window(g_mlx, g_mlx_win,
			g_pacmanonyou, n * 64, i * 64);
	if (checker == 'C')
		mlx_put_image_to_window(g_mlx, g_mlx_win,
			g_collectible, n * 64, i * 64);
	if (checker == '0')
		mlx_put_image_to_window(g_mlx, g_mlx_win,
			g_backround, n * 64, i * 64);
	if (checker == 'E')
		mlx_put_image_to_window(g_mlx, g_mlx_win,
			g_closeddoor, n * 64, i * 64);
}

int	key_hook(int keycode, void *vars)
{
	(void)vars;
	if (keycode == 53)
		map_free();
	if (keycode == 13)
		ft_move_up();
	else if (keycode == 0)
		ft_move_left();
	else if (keycode == 2)
		ft_move_right();
	else if (keycode == 1)
		ft_move_down();
	return (0);
}

void	check_for_new_line(char *av)
{
	int		sd;
	char	**hold;
	int		a;
	int		b;

	a = 0;
	sd = open(av, O_RDONLY);
	hold = malloc(g_lin * sizeof(char *));
	while (a < g_lin)
		hold[a++] = get_next_line(sd);
	b = ft_strlen(hold[g_lin - 1]);
	if (hold[g_lin - 1][b - 1] == '\n')
	{
		write(1, "Error\nThe Mapp Does not follow the Rules", 42);
		while (a < g_lin)
			free(hold[a++]);
		free(hold);
		exit(1);
	}
	a = 0;
	while (a < g_lin)
		free(hold[a++]);
	free(hold);
	return ;
}

void	msg_error(void)
{
	int	a;

	a = 0;
	write(1, "Error!\nThe Mapp Does not follow the Rules", 42);
	while (a < g_lin)
		free(g_map[a++]);
	free(g_map);
	exit(1);
}
