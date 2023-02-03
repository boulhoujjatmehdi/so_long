/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:31:49 by eboulhou          #+#    #+#             */
/*   Updated: 2023/02/02 20:22:03 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_mlx_init(char **mat)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
	{
		free_mat(mat, 1);
		exit_prog("Something went wrong.");
	}
	return (mlx);
}

void	*ft_new_window(t_mlx s)
{
	void	*win;

	win = mlx_new_window(s.mlx, s.width * 50, s.height * 50, "Star_wars");
	if (!win)
	{
		free_mat(s.mat, 1);
		free(s.mlx);
		exit_prog("Something went wrong.");
	}
	return (win);
}

void	*ft_xpm_image(t_mlx *smlx, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(smlx->mlx, path, &smlx->i, &smlx->j);
	if (!img)
	{
		free_mat(smlx->mat, 1);
		mlx_destroy_window(smlx->mlx, smlx->win);
		exit_prog("Something went wrong.");
	}
	return (img);
}
