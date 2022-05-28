/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:21:45 by enja              #+#    #+#             */
/*   Updated: 2022/05/19 18:17:12 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include "linecount.h"
# include "ptf/ft_printf.h"
# include "get_next_line.h"

typedef struct data{
	int		i;
	int		n;
}t_data;

typedef struct check{
	int	a;
	int	c;
}t_check;

typedef struct env{
	int	p;
	int	e;
	int	sp;
	int	ndex;
	int	n;
}t_env;

typedef struct read{
	char	*str;
	int		a;
	int		n;
}t_read;

typedef struct inf{
	int		idx;
	int		ndx;
	char	*map_rule;
	int		a;
	int		sin;
}t_inf;

void	msg_error(void);
char	**map_reader(int fd, int lin);
char	*n_remover(char *string);
int		map_tchecker(char *str, int a);
int		lines(int nd);
void	map_load(char **map);
void	envaroment_player(char **map);
void	second_checker(char **map);
void	map_constrict(void);
void	map_struct(char **map);
void	envaroment_player_check(void);
void	map_set(char checker, int n, int i);
void	ft_move_up(void);
int		key_hook(int keycode, void *vars);
void	ft_move_left(void);
void	ft_move_right(void);
void	ft_move_down(void);
void	render_img_up(int i, int n);
void	render_img_down(int i, int n);
void	render_img_left(int i, int n);
void	render_img_right(int i, int n);
void	to_finish(void);
void	check_for_new_line(char *av);
void	map_free(void);
int		win_destroy(void);

int		g_playermove;
int		g_collectcounter;
int		g_coin;
char	**g_map;
int		g_lin;
void	*g_mlx;
void	*g_mlx_win;
void	*g_wall;
void	*g_backround;
void	*g_playertolife;
void	*g_pacmanonyou;
void	*g_playerup;
void	*g_playerdown;
void	*g_playerleft;
void	*g_playerright;
void	*g_collectible;
void	*g_exitt;
void	*g_closeddoor;
void	*g_opendoor;

#endif