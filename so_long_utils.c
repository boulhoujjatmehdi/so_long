/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:53:13 by eboulhou          #+#    #+#             */
/*   Updated: 2023/01/01 12:14:31 by eboulhou         ###   ########.fr       */
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
			if (c == 'E')
				found_e++;
			if (c != '1' && c != '0' && c != 'P' && c != '\n')
				if ((c != 'E' && c != 'C') || found_e > 1)
					return (0);
			j++;
		}
	i++;
	}
	return (1);
}

int	ch_wal_ec(char **matrix, int n_line, int l_line)
{
	int	i;
	int	len;
	int	pos[2];

	i = 0;
	while (matrix[i])
	{
		len = ftn_strlen(matrix[i]);
		if (len != l_line)
			exit_prog("Your map is not Rectangular.");
		if (matrix[i][len - 1] != '1' || matrix[i++][0] != '1')
			exit_prog("Check your sides walls.");
	}
	i = 0;
	while (matrix[0][i] && matrix[n_line - 1][i])
		if (matrix[0][i] != '1' || matrix[n_line - 1][i++] != '1')
			exit_prog("check your (top || bottom) wall.");
	if ((!get_pos(matrix, 'E', pos)) || !(get_pos(matrix, 'C', pos)))
		exit_prog("Check your components :\n -One 'E'\n -At least one 'C'.\n");
	if (!ch_non_compo(matrix))
		exit_prog("Check your map it contains unknown components.");
	return (1);
}

int	get_number_of_lines(char *arg)
{
	int		counter;
	char	*str;
	int		fd;

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
