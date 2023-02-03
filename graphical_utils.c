/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:14:11 by eboulhou          #+#    #+#             */
/*   Updated: 2023/02/03 11:00:57 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_mlx mlx)
{
	free_mat (mlx.mat, 1);
	mlx_destroy_image (mlx.mlx, mlx.img);
	mlx_destroy_window (mlx.mlx, mlx.win);
	exit_prog("Check on your images files.");
}
