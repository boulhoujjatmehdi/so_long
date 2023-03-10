/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:53:57 by eboulhou          #+#    #+#             */
/*   Updated: 2023/02/03 11:22:56 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
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
	int	true;
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
int		ch_non_compo(char **mat);
int		ch_wal_ecp(char **matrix, int n_line, int l_line);
int		get_number_of_lines(char *arg);
void	free_mat(char **mat, int glob_free);
int		exit_prog(char *str);
void	set_matrix(int fd, char **matrix);

//graphics
void	show_wind(char **mat, int height, int width);
void	put_walls(t_mlx smlx);
void	put_bg(t_mlx smlx);
void	free_game(t_mlx mlx);

//events
int		key_hook(int key, t_mlx *smlx);
int		key_hook(int key, t_mlx *smlx);
int		move_to(t_mlx *smlx, int k);

//protect.c
void	*ft_mlx_init(char **mat);
void	*ft_new_window(t_mlx s);
void	*ft_xpm_image(t_mlx *smlx, char *path);
#endif