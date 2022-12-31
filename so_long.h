/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:53:57 by eboulhou          #+#    #+#             */
/*   Updated: 2022/12/31 19:52:01 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"
# include "./printf/ft_printf.h"

typedef struct s_im_info
{
	void	*w;
	void	*p;
	void	*c;
	void	*eo;
	void	*ec;
}t_im_info;

typedef struct s_xjz
{
	int	i;
	int	j;
	int	z;
	int	t;
}t_xjz;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**mat;
	int		width;
	int		height;
	int		i;
	int		j;
	int		pos[2];
}t_mlx;

//main
int		ftn_strlen(char *str);
int		get_pos(char **mat, char c, int *pos);
void	free_mat(char **mat, int glob_free);
void	exit_prog(char *str);

//graphics
void	show_wind(char **mat, int height, int width);
void	put_walls(t_mlx smlx);
void	put_bg(t_mlx smlx);

//events
int		key_hook(int key, t_mlx *smlx);
int		end_game(char **mat);

#endif