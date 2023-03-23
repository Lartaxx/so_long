/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:36:06 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/23 09:36:07 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_items(t_vars *vars, char item)
{
	int		i;
	int		j;
	int		count_items;

	i = 0;
	j = 0;
	count_items = 0;
	while (i < vars->height)
	{
		while (j < vars->width)
		{
			if (vars->map[i][j] == item)
			{
				count_items++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (count_items);
}
