/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:05:06 by eboulhou          #+#    #+#             */
/*   Updated: 2023/01/02 10:14:39 by eboulhou         ###   ########.fr       */
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

int	check_next(char **mat, char c, int counter)
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
		ft_printf("move : %d\nThe End.\n", counter);
		exit(69);
	}
	return (1);
}

int	put_components(int i, int j, t_mlx *smx)
{
	int			check;
	static int	c = 1;

	check = check_next(smx->mat, smx->mat[smx->pos[0] + j][smx->pos[1] + i], c);
	if (check)
	{
		ft_printf("move : %d\n", c++);
		smx->pos[0] += j;
		smx->pos[1] += i;
		if (check != 55)
			smx->mat[smx->pos[0]][smx->pos[1]] = '0';
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
