/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linecount.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 23:30:16 by enja              #+#    #+#             */
/*   Updated: 2022/05/19 18:16:52 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINECOUNT_H
# define LINECOUNT_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 10

typedef struct dta{
	int		a;
	char	*ber;
	int		n;
}t_dta;

int		ft_strlenn(char *str);
char	*joinn(char *str, char *buff);
char	*linecount(int fd);
int		check_nn(char *last);
char	*check_befor_nn(char	*str);
char	*check_after_nn(char *str, int len);
char	*ft_strdupn(char	*str);
void	check_argument(char *av);

#endif