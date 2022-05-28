/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:38:04 by enja              #+#    #+#             */
/*   Updated: 2022/05/18 22:20:02 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_destroy(void)
{
	exit(0);
}

char	**map_reader(int fd, int lin)
{	
	t_read	rd;

	rd.a = 0;
	rd.n = 0;
	rd.str = get_next_line(fd);
	rd.str = n_remover(rd.str);
	while (rd.str[rd.a])
		rd.a++;
	g_map = malloc(lin * sizeof(char *));
	while (rd.str)
	{
		map_tchecker(rd.str, rd.a);
		g_map[rd.n] = rd.str;
		rd.n++;
		rd.str = get_next_line(fd);
		if (rd.str != NULL)
			rd.str = n_remover(rd.str);
	}
	return (g_map);
}

void	envaroment_player(char **map)
{
	t_env	idx;

	idx.ndex = 0;
	idx.p = 0;
	g_coin = 0;
	while (idx.ndex < g_lin)
	{
		idx.n = 0;
		while (map[idx.ndex][idx.n])
		{
			if (map[idx.ndex][idx.n] == 'C')
				g_coin++;
			if (map[idx.ndex][idx.n] == 'P')
				idx.p++;
			if (map[idx.ndex][idx.n] == 'E')
				idx.e = 1;
			if (map[idx.ndex][idx.n] == '0')
				idx.sp = 1;
			idx.n++;
		}
		idx.ndex++;
	}
	if (g_coin < 1 || idx.p != 1 || idx.e != 1 || idx.sp != 1)
		msg_error();
	envaroment_player_check();
}

void	second_checker(char **map)
{
	t_check	idx;

	idx.a = 0;
	idx.c = 0;
	while (map[0][idx.c])
	{
		if (map[0][idx.c] != '1')
			msg_error();
		if (map[g_lin - 1][idx.c] != '1')
			msg_error();
		idx.c++;
	}
	envaroment_player(map);
}

void	map_struct(char **map)
{
	int	x;
	int	y;

	g_collectcounter = 0;
	g_playermove = 0;
	g_mlx = mlx_init();
	g_mlx_win = mlx_new_window(g_mlx,
			ft_strlen(map[0]) * 64, g_lin * 64, "so_long");
	g_wall = mlx_xpm_file_to_image(g_mlx, "mario.xpm", &x, &y);
	g_playerleft = mlx_xpm_file_to_image(g_mlx, "pacmanleft.xpm", &x, &y);
	g_playerright = mlx_xpm_file_to_image(g_mlx, "pacmanright.xpm", &x, &y);
	g_playerdown = mlx_xpm_file_to_image(g_mlx, "pacmandown.xpm", &x, &y);
	g_playerup = mlx_xpm_file_to_image(g_mlx, "pacmanup.xpm", &x, &y);
	g_backround = mlx_xpm_file_to_image(g_mlx, "backround.xpm", &x, &y);
	g_pacmanonyou = mlx_xpm_file_to_image(g_mlx, "pacmanonyou.xpm", &x, &y);
	g_collectible = mlx_xpm_file_to_image(g_mlx, "collectible.xpm", &x, &y);
	g_closeddoor = mlx_xpm_file_to_image(g_mlx, "closeddoor.xpm", &x, &y);
	g_opendoor = mlx_xpm_file_to_image(g_mlx, "opendoor.xpm", &x, &y);
}
