/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:11:02 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/22 09:11:05 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		get_player_position(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(i < vars->height)
	{
		while(j < vars->width)
		{
			if(vars->map[i][j] == 'P')
			{
				vars->x = i;
				vars->y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}


void move_player(t_vars *vars)
{
	if (vars->map[vars->next_x][vars->next_y] == '0')
	{
		vars->map[vars->next_x][vars->next_y] = 'P';
		vars->map[vars->x][vars->y] = '0';
		vars->x = vars->next_x;
		vars->y = vars->next_y;
		vars->moves++;
	}
	else
	{
		vars->next_x = vars->x;
		vars->next_y = vars->y;
	}
}

void	player_move(t_vars *vars, int direction)
{
	direction = (int)direction;
	get_player_position(vars);
	vars->next_x = vars->x;
	vars->next_y = vars->y;

	if (direction == 1)
		vars->next_x--;
	else if (direction == 2)
		vars->next_x++;
	else if (direction == 3)
		vars->next_y--;
	else if (direction == 4)
		vars->next_y++;
	move_player(vars);
	ft_printf("\n x = %d y = %d", vars->x, vars->y);
	ft_printf("\n nextx = %d nexty = %d", vars->next_x, vars->next_y);
	ft_printf("\n Total moves : %d", vars->moves);
}