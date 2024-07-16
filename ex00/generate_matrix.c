/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:27:47 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/07/16 14:17:12 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// extern char	*g_arg;
// extern char	g_row_p[24][4];
// extern char	g_matrix[4][4];
// extern int	g_is_valid_matrix;
// int			g_column;

int		check_pov(int heights[4], int sighted);
void	check_arg(char *pov, char matrix[4][4], int *is_valid_matrix);

void	check_for_repeated_numbers(char matrix[4][4], int *is_valid_matrix)
{
	int	column;
	int	m;
	int	n;

	column = 0;
	while (column < 4)
	{
		m = 0;
		while (m < 4)
		{
			n = m + 1;
			while (n < 4)
			{
				if (matrix[m][column] == matrix[n][column])
					*is_valid_matrix = 0;
				n++;
			}
			m++;
		}
		column++;
	}
}

// void	checks(void)
// {
// 	check_for_repeated_numbers();
// 	check_arg();
// }

// void	update_matrix(int *array, char row_p[24][4], char matrix[4][4])
// {
// 	int	column;

// 	column = 0;
// 	while (column < 4)
// 		matrix[0][column] = row_p[array[0]][column++];
// 	column = 0;
// 	while (column < 4)
// 		matrix[1][column] = row_p[array[1]][column++];
// 	column = 0;
// 	while (column < 4)
// 		matrix[2][column] = row_p[array[2]][column++];
// 	column = 0;
// 	while (column < 4)
// 		matrix[3][column] = row_p[array[3]][column++];
// }

void	update_matrix(int *array, char row_p[24][4], char matrix[4][4])
{
	int	column;

	column = 0;
	while (column < 4)
	{
		matrix[0][column] = row_p[array[0]][column];
		matrix[1][column] = row_p[array[1]][column];
		matrix[2][column] = row_p[array[2]][column];
		matrix[3][column] = row_p[array[3]][column];
		column++;
	}
}

int	should_break(char *pov, char matrix[4][4], char row_p[24][4], int array[4])
{
	int	row;
	int	column;
	int is_valid_matrix;

	is_valid_matrix = 1;
	update_matrix(array, row_p, matrix);
	check_for_repeated_numbers(matrix, &is_valid_matrix);
	check_arg(pov, matrix, &is_valid_matrix);
	if (is_valid_matrix)
	{
		row = 0;
		while (row < 4)
		{
			column = 0;
			while (column < 4)
			{
				write(1, &matrix[row][column], 1);
				if (column != 3)
					write(1, " ", 1);
				column++;
			}
			write(1, "\n", 1);
			row++;
		}
		return (1);
	}
	return (0);
}

int	generate_matrix_2(char *pov, char matrix[4][4], char row_p[24][4], int array[4])
{
	while (array[0] < 24)
	{
		array[1] = 0;
		while (array[1] < 24)
		{
			array[2] = 0;
			while (array[2] < 24)
			{
				array[3] = 0;
				while (array[3] < 24)
				{
					if (should_break(pov, matrix, row_p, array))
						return (1);
					array[3]++;
				}
				array[2]++;
			}
			array[1]++;
		}
		array[0]++;
	}
	return (0);
}


int	generate_matrix(char *pov, char matrix[4][4], char row_p[24][4])
{
	int	array[4];

	array[0] = 0;
	if (generate_matrix_2(pov, matrix, row_p, array))
		return (1);
	return (0);
}

// extern char	*g_arg;
// extern char	g_row_p[24][4];
// extern char	g_matrix[4][4];
// extern int	g_is_valid_matrix;
// int			g_column;