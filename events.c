/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:18:58 by eboulhou          #+#    #+#             */
/*   Updated: 2023/01/02 09:23:22 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_mlx *smlx)
{
	int	check;

	if (key == 53)
	{
		exit(0);
	}
	check = move_to(smlx, key);
	if (check == 69)
	{
		exit(0);
	}
	return (check);
}
