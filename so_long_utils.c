/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:53:13 by eboulhou          #+#    #+#             */
/*   Updated: 2023/02/03 12:08:25 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ftn_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] && str[count] != '\n')
		count++;
	return (count);
}

int	ch_non_compo(char **mat)
{
	int		i;
	int		j;
	int		found_e;
	char	c;

	found_e = 0;
	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			c = mat[i][j];
			if (c == 'E' && found_e++)
				exit_prog("You must have one E on your map");
			if (c != '1' && c != '0' && c != 'P' && c != '\n')
				if (c != 'E' && c != 'C')
					return (0);
			j++;
		}
	i++;
	}
	return (1);
}

int	get_number_of_lines(char *arg)
{
	int		counter;
	char	*str;
	int		fd;
	t_xjz	x;
	char	*ber;

	ber = ".ber";
	x.i = ft_strlen(arg) - 4;
	x.j = 0;
	while (arg[x.i])
		if (arg[x.i++] != ber[x.j++])
			exit_prog("File name must end with \".ber\". ");
	fd = open(arg, O_RDONLY);
	str = get_next_line(fd);
	counter = 0;
	while (str)
	{
		counter++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

void	set_matrix(int fd, char **matrix)
{
	*matrix = get_next_line(fd);
	while (*matrix)
	{
		matrix++;
		*matrix = get_next_line(fd);
	}
	close(fd);
}
