/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:13:06 by eboulhou          #+#    #+#             */
/*   Updated: 2023/02/03 11:22:56 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_pos(char **mat, char c, int *pos)
{
	int	i;
	int	j;

	i = 0;
	pos[0] = -1;
	pos[1] = -1;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (mat[i][j] == c)
			{
				if (pos[0] != -1 && c == 'P')
					return (0);
				pos[0] = i;
				pos[1] = j;
			}
			j++;
		}
		i++;
	}
	if (pos[0] != -1)
		return (1);
	return (0);
}

void	eat_till_exit(char **mat, int pos1, int pos2)
{
	mat[pos1][pos2] = 'P';
	if (mat[pos1 + 1][pos2] != '1' && mat[pos1 + 1][pos2] != 'P')
		eat_till_exit(mat, pos1 + 1, pos2);
	if (mat[pos1][pos2 + 1] != '1' && mat[pos1][pos2 + 1] != 'P')
		eat_till_exit(mat, pos1, pos2 + 1);
	if (mat[pos1 - 1][pos2] != '1' && mat[pos1 - 1][pos2] != 'P')
		eat_till_exit(mat, pos1 - 1, pos2);
	if (mat[pos1][pos2 - 1] != '1' && mat[pos1][pos2 - 1] != 'P')
		eat_till_exit(mat, pos1, pos2 - 1);
}

void	free_mat(char **mat, int glob_free)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mat[i])
	{
		free (mat[i]);
		mat[i] = NULL;
		i++;
	}
	if (glob_free)
	{
		free (mat);
		mat = NULL;
	}
}

int	exit_prog(char *str)
{
	if (str)
		ft_printf("ERROR: %s\n", str);
	exit(0);
}

int	main(int ac, char **argv)
{
	int		fd;
	int		n_line;
	char	**matrix;
	int		pos[2];

	if (ac != 2)
		exit_prog("Name of program + Map name\n\"./so_long MapName.ber\"");
	n_line = get_number_of_lines(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_prog("Map name problem.");
	matrix = (char **)malloc(sizeof (char *) * (n_line + 1));
	set_matrix(fd, matrix);
	ch_wal_ecp(matrix, n_line, ftn_strlen(matrix[0]));
	if (!get_pos(matrix, 'P', pos))
		exit_prog("Check the P int this map.");
	eat_till_exit(matrix, pos[0], pos[1]);
	if (get_pos(matrix, 'E', pos) || get_pos(matrix, 'C', pos))
		exit_prog("No valid path.");
	fd = open(argv[1], O_RDONLY);
	free_mat(matrix, 0);
	set_matrix(fd, matrix);
	show_wind(matrix, n_line, ft_strlen(matrix[1]) - 1);
}
