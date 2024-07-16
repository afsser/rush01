/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:06:01 by fcaldas-          #+#    #+#             */
/*   Updated: 2023/06/04 15:41:09 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_pov(int heights[4], int sighted)
{
	int	max;
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	max = 0;
	while (i < 4)
	{
		if (heights[i] > max)
		{
			max = heights[i];
			counter++;
		}
		i++;
	}
	if (counter == sighted)
		return (1);
	return (0);
}
