/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:53:13 by eboulhou          #+#    #+#             */
/*   Updated: 2022/12/31 19:41:11 by eboulhou         ###   ########.fr       */
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
	if (mat[pos1 + 1][pos2] != '1' && mat[pos1 + 1][pos2] != 'P' )
		eat_till_exit(mat, pos1 + 1, pos2);
	if (mat[pos1][pos2 + 1] != '1' && mat[pos1][pos2 + 1] != 'P')
		eat_till_exit(mat, pos1, pos2 + 1);
	if (mat[pos1 - 1][pos2] != '1' && mat[pos1 - 1][pos2] != 'P' )
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

void	exit_prog(char *str)
{
	ft_printf("ERROR: %s\n",str);
	exit(0);
}

int	main(int ac, char **argv)
{
	int		fd;
	int		n_line;
	char	**matrix;
	int		pos[2];

	(void)ac;
	n_line = get_number_of_lines(argv[1]);
	fd = open(argv[1], O_RDONLY);
	matrix = (char **)malloc(sizeof (char *) * (n_line + 1));
	set_matrix(fd, matrix);
	ch_wal_ec(matrix, n_line, ftn_strlen(matrix[0]));
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
