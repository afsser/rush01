/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:42:49 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/07/16 14:29:34 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// extern char	*g_arg;
// extern char	g_row_p[24][4];
// extern char	g_matrix[4][4];

void	generate_rows(char row_p[24][4]);
int		generate_matrix(char *pov, char matrix[4][4], char row_p[24][4]);
int		input_check(int argc, char *pov);

int	main(int argc, char **argv)
{
	char	row_p[24][4];
	char	matrix[4][4];
	
	generate_rows(row_p);
	if (input_check(argc, argv[1]) == 1)
	{
		write(1, "Input Check Error\n", 18);
	}
	else if (generate_matrix(argv[1], matrix, row_p) != 1)
	{
		write(1, "Generate Matrix Error\n", 22);
	}
	return (0);
}

