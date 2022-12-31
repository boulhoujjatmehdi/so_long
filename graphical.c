/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:29:57 by eboulhou          #+#    #+#             */
/*   Updated: 2022/12/31 20:24:36 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(void *mlx, void *win, void *imgp, t_xjz xx)
{
	if (imgp)
	{
		mlx_put_image_to_window(mlx, win, imgp, xx.j *50, xx.i *50);
		mlx_destroy_image(mlx, imgp);
	}
		imgp = NULL;
}
void put_player(t_mlx smlx)
{
	void *img;
	int i;
	img= mlx_xpm_file_to_image(smlx.mlx, "./im/P.xpm",&i, &i);
	mlx_put_image_to_window(smlx.mlx, smlx.win, img, smlx.pos[1] * 50, smlx.pos[0] * 50);
}

void	put_walls(t_mlx s)
{
	void			*imgp;
	struct s_xjz	xx;

	xx.i = 0;
	while (s.mat[xx.i])
	{
		xx.j = -1;
		while (s.mat[xx.i][++(xx.j)])
		{
			imgp = NULL;
			if (s.mat[xx.i][xx.j] == '1')
				imgp = mlx_xpm_file_to_image(s.mlx, "./im/N.xpm", &xx.z, &xx.z);
			else if (s.mat[xx.i][xx.j] == 'C')
				imgp = mlx_xpm_file_to_image(s.mlx, "./im/C.xpm", &xx.z, &xx.z);
			else if (s.mat[xx.i][xx.j] == 'E')
				imgp = mlx_xpm_file_to_image(s.mlx, "./im/D.xpm", &xx.z, &xx.z);
			else if (s.mat[xx.i][xx.j] == 'X')
				imgp = mlx_xpm_file_to_image(s.mlx, "./im/O.xpm", &xx.z, &xx.z);
			put_img(s.mlx, s.win, imgp, xx);
		}
		xx.i++;
	}
	put_player(s);
}

void	put_bg(t_mlx smlx)
{
	int	ii;
	int	jj;

	ii = 0;
	jj = 0;
	while (smlx.height * 50 > jj)
	{
		while (smlx.width * 50 > ii)
		{
			mlx_put_image_to_window(smlx.mlx, smlx.win, smlx.img, ii, jj);
			ii += smlx.i;
		}
		jj += smlx.j;
	}
}

void	show_wind(char **mat, int height, int width)
{
	t_mlx	smlx;

	smlx.height = height;
	smlx.width = width;
	smlx.mat = mat;
	get_pos(smlx.mat, 'P', smlx.pos);
	smlx.mlx = mlx_init();
	smlx.win = mlx_new_window(smlx.mlx, width * 50, height * 50, "Star_wars");
	smlx.img = mlx_xpm_file_to_image(smlx.mlx, "./im/S.xpm", &smlx.i, &smlx.j);
	put_bg(smlx);
	put_walls(smlx);
	mlx_hook(smlx.win, 2, 0, key_hook, &smlx);
	mlx_hook(smlx.win, 17, 0, end_game, smlx.mat);
	mlx_loop(smlx.mlx);
}
