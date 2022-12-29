/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:29:57 by eboulhou          #+#    #+#             */
/*   Updated: 2022/12/29 21:09:46 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

struct	s_im_info
{
	void	*w;
	void	*p;
	void	*c;
	void	*eo;
	void	*ec;
};

struct	s_xjz
{
	int	i;
	int	j;
	int	z;
	int	t;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		i;
	int		j;
};

void	put_walls(char **mat, void *mlx, void *win)
{
	struct s_im_info	info;
	struct s_xjz		xx;

	xx.i = 0;
	while (mat[xx.i])
	{
		xx.j = -1;
		while (mat[xx.i][++(xx.j)])
		{
			info.w = NULL;
			if (mat[xx.i][xx.j] == '1')
				info.w = mlx_xpm_file_to_image(mlx, "./im/N.xpm", &xx.z, &xx.z);
			else if (mat[xx.i][xx.j] == 'P')
				info.w = mlx_xpm_file_to_image(mlx, "./im/P.xpm", &xx.z, &xx.z);
			else if (mat[xx.i][xx.j] == 'C')
				info.w = mlx_xpm_file_to_image(mlx, "./im/C.xpm", &xx.z, &xx.z);
			else if (mat[xx.i][xx.j] == 'E')
				info.w = mlx_xpm_file_to_image(mlx, "./im/D.xpm", &xx.z, &xx.z);
			else if (mat[xx.i][xx.j] == 'X')
				info.w = mlx_xpm_file_to_image(mlx, "./im/D.xpm", &xx.z, &xx.z);
			if (info.w)
				mlx_put_image_to_window(mlx, win, info.w, xx.j * 50, xx.i * 50);
		}
		xx.i++;
	}
}

void	put_bg(int hei, int wid, struct s_mlx smlx)
{
	int	ii;
	int	jj;

	ii = 0;
	jj = 0;
	while (hei * 50 > jj)
	{
		while (wid * 50 > ii)
		{
			mlx_put_image_to_window(smlx.mlx, smlx.win, smlx.img, ii, jj);
			ii += smlx.i;
		}
		jj += smlx.j;
	}
}

void	show_wind(char **mat, int height, int width)
{
	struct s_mlx	smlx;

	smlx.mlx = mlx_init();
	smlx.win = mlx_new_window(smlx.mlx, width * 50, height * 50, "so_long");
	smlx.img = mlx_xpm_file_to_image(smlx.mlx, "./im/S.xpm", &smlx.i, &smlx.j);
	put_bg(height, width, smlx);
	put_walls(mat, smlx.mlx, smlx.win);
	mlx_loop(smlx.mlx);
}
