/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:29:57 by eboulhou          #+#    #+#             */
/*   Updated: 2022/12/28 14:37:46 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void show_wind(char **mat, int height, int width)
{
    void *mlx;
    void *win;
    
    mlx = mlx_init();
    win = mlx_new_window(mlx,height,width,"so_long");
    mlx_loop(mlx);
}