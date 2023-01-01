/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:18:58 by eboulhou          #+#    #+#             */
/*   Updated: 2023/01/01 12:07:35 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nb(char **mat, char c)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (mat[i][j] == c)
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

int	check_next(char **mat, char c)
{
	int	pos[2];

	if (c == '1')
		return (0);
	if (c == 'C' && get_nb(mat, 'C') == 1)
	{
		get_pos(mat, 'E', pos);
		mat[pos[0]][pos[1]] = 'X';
	}
	if (c == 'E' && get_nb(mat, 'C'))
	{
		return (55);
	}
	if (c == 'X')
	{
		return (69);
	}
	return (1);
}

int	put_components(int i, int j, t_mlx *smx)
{
	int			check;
	static int	g_counter = 1;

	check = check_next(smx->mat, smx->mat[smx->pos[0] + j][smx->pos[1] + i]);
	if (check)
	{
		ft_printf("move : %d\n", g_counter++);
		if (check != 55)
			smx->mat[smx->pos[0] + j][smx->pos[1] + i] = '0';
		smx->pos[0] += j;
		smx->pos[1] += i;
		put_bg(*smx);
		put_walls(*smx);
	}
	return (check);
}

int	move_to(t_mlx *smlx, int k)
{
	int			i;
	int			j;
	int			check;

	i = 0;
	j = 0;
	check = 0;
	if ((!k && i--) || (k == 2 && i++) || (k == 1 && j++) || (k == 13 && j--))
		(void)i;
	if (i || j)
	{
		check = put_components(i, j, smlx);
	}
	return (check);
}

int	end_game(char **mat)
{
	free_mat(mat, 1);
	exit(1);
}
