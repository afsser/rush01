/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:51:17 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/07/16 14:17:32 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// extern char	*pov;
// extern char	matrix[4][4];
// extern int	is_valid_matrix;
// int			heights[4];

int	check_pov(int heights[4], int sighted);

void	check_for_column_up(char *pov, char matrix[4][4], int *is_valid_matrix, int heights[4])
{
	int	counter;
	int	iterator;
	int	row;
	int	current_arg;

	counter = 0;
	while (counter < 4)
	{
		current_arg = pov[counter * 2] - '0';
		row = 0;
		iterator = 0;
		while (row < 4)
		{
			heights[iterator] = matrix[row][counter % 4];
			row++;
			iterator++;
		}
		if (!check_pov(heights, current_arg))
			*is_valid_matrix = 0;
		counter++;
	}
}

void	check_for_column_down(char *pov, char matrix[4][4], int *is_valid_matrix, int heights[4])
{
	int	counter;
	int	current_arg;
	int	row;
	int	iterator;

	counter = 4;
	while (counter < 8)
	{
		current_arg = pov[counter * 2] - '0';
		row = 3;
		iterator = 0;
		while (row >= 0)
		{
			heights[iterator] = matrix[row][counter % 4];
			row--;
			iterator++;
		}
		if (!check_pov(heights, current_arg))
			*is_valid_matrix = 0;
		counter++;
	}
}

void	check_for_row_left(char *pov, char matrix[4][4], int *is_valid_matrix, int heights[4])
{
	int	counter;
	int	current_arg;
	int	column;
	int	iterator;

	counter = 8;
	while (counter < 12)
	{
		current_arg = pov[counter * 2] - '0';
		column = 0;
		iterator = 0;
		while (column < 4)
		{
			heights[iterator] = matrix[counter % 4][column];
			column++;
			iterator++;
		}
		if (!check_pov(heights, current_arg))
			*is_valid_matrix = 0;
		counter++;
	}
}

void	check_for_row_right(char *pov, char matrix[4][4], int *is_valid_matrix, int heights[4])
{
	int	counter;
	int	current_arg;
	int	column;
	int	iterator;

	counter = 12;
	while (counter < 16)
	{
		current_arg = pov[counter * 2] - '0';
		column = 3;
		iterator = 0;
		while (column >= 0)
		{
			heights[iterator] = matrix[counter % 4][column];
			column--;
			iterator++;
		}
		if (!check_pov(heights, current_arg))
			*is_valid_matrix = 0;
		counter++;
	}
}

void	check_arg(char *pov, char matrix[4][4], int *is_valid_matrix)
{
	int	heights[4];
	check_for_column_up(pov, matrix, is_valid_matrix, heights);
	check_for_column_down(pov, matrix, is_valid_matrix, heights);
	check_for_row_left(pov, matrix, is_valid_matrix, heights);
	check_for_row_right(pov, matrix, is_valid_matrix, heights);
}

// extern char	*pov;
// extern char	matrix[4][4];
// extern int	is_valid_matrix;
// int			heights[4];