/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_rows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:22:44 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/07/16 12:31:16 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// extern char	g_row_p[24][4];
// int			g_is_valid;
// int			g_row_p_number;
// char		g_arr[4];

void	check_equals(char arr[4], int is_valid)
{
	int	m;
	int	n;

	m = 0;
	while (m < 4)
	{
		n = m + 1;
		while (n < 4)
		{
			if (arr[m] == arr[n])
			{
				is_valid = 0;
				break ;
			}
			n++;
		}
		if (!is_valid)
			break ;
		m++;
	}
}

void	check_possibilities(char row_p[24][4], int row_p_number, char arr[4])
{
	int	k;
	int is_valid;

	is_valid = 1;
	check_equals(arr, is_valid);
	if (is_valid)
	{
		k = 0;
		while (k < 4)
		{
			row_p[row_p_number][k] = arr[k];
			k++;
		}
		row_p_number++;
	}
}

void	generate_rows_2(char row_p[24][4], int row_p_number, char arr[4])
{
	while (arr[0] <= '4')
	{
		arr[1] = '1';
		while (arr[1] <= '4')
		{
			arr[2] = '1';
			while (arr[2] <= '4')
			{
				arr[3] = '1';
				while (arr[3] <= '4')
				{
					check_possibilities(row_p, row_p_number, arr);
					arr[3]++;
				}
				arr[2]++;
			}
			arr[1]++;
		}
		arr[0]++;
	}
}

void	generate_rows(char row_p[24][4])
{
	int		row_p_number;
	char	arr[4];

	row_p_number = 0;
	arr[0] = '1';
	generate_rows_2(row_p, row_p_number, arr);
}

// extern char	g_row_p[24][4];
// int			g_is_valid;
// int			g_row_p_number;
// char		g_arr[4];