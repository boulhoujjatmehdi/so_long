/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:29:57 by eboulhou          #+#    #+#             */
/*   Updated: 2023/02/03 11:01:18 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(void *mlx, void *win, void *imgp, t_xjz xx)
{
	if (imgp)
	{
		mlx_put_image_to_window(mlx, win, imgp, xx.j * 50, xx.i * 50);
		mlx_destroy_image(mlx, imgp);
	}
	imgp = NULL;
}

void	put_player(t_mlx s)
{
	void	*img;
	int		i;

	img = mlx_xpm_file_to_image(s.mlx, "./im/P.xpm", &i, &i);
	if (!img)
		free_game(s);
	mlx_put_image_to_window(s.mlx, s.win, img, s.pos[1] * 50, s.pos[0] * 50);
	mlx_destroy_image(s.mlx, img);
}

void	put_walls(t_mlx s)
{
	void			*imgp;
	struct s_xjz	xx;

	xx.i = -1;
	while (s.mat[++xx.i])
	{
		xx.j = -1;
		while (s.mat[xx.i][++(xx.j)])
		{
			imgp = NULL;
			xx.true = 1;
			if (s.mat[xx.i][xx.j] == '1' && xx.true++)
				imgp = mlx_xpm_file_to_image(s.mlx, "./im/B.xpm", &xx.z, &xx.z);
			else if (s.mat[xx.i][xx.j] == 'C' && xx.true++)
				imgp = mlx_xpm_file_to_image(s.mlx, "./im/C.xpm", &xx.z, &xx.z);
			else if (s.mat[xx.i][xx.j] == 'E' && xx.true++)
				imgp = mlx_xpm_file_to_image(s.mlx, "./im/D.xpm", &xx.z, &xx.z);
			else if (s.mat[xx.i][xx.j] == 'X' && xx.true++)
				imgp = mlx_xpm_file_to_image(s.mlx, "./im/O.xpm", &xx.z, &xx.z);
			if (xx.true != 1 && imgp == NULL)
				free_game(s);
			put_img(s.mlx, s.win, imgp, xx);
		}
	}
	put_player(s);
}

void	put_bg(t_mlx smlx)
{
	int	ii;
	int	jj;

	jj = 0;
	while (smlx.height * 50 > jj)
	{
		ii = 0;
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
	smlx.mlx = ft_mlx_init(mat);
	smlx.win = ft_new_window(smlx);
	smlx.img = ft_xpm_image(&smlx, "./im/S.xpm");
	put_bg(smlx);
	put_walls(smlx);
	mlx_hook(smlx.win, 2, 0, key_hook, &smlx);
	mlx_hook(smlx.win, 17, 0, exit_prog, NULL);
	mlx_loop(smlx.mlx);
}
