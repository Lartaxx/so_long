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

void	get_player_position(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < vars->height)
	{
		while (j < vars->width)
		{
			if (vars->map[i][j] == 'P')
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

void	player_move(t_vars *vars, int direction)
{
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
	ft_printf("\nNombre de mouvements : %d", vars->moves);
}

static void	update_player(t_vars *vars)
{
	if (vars->map[vars->next_x][vars->next_y] == '0')
	{
		vars->map[vars->next_x][vars->next_y] = 'P';
		vars->map[vars->x][vars->y] = '0';
		vars->x = vars->next_x;
		vars->y = vars->next_y;
		vars->moves++;
	}
	else if (vars->map[vars->next_x][vars->next_y] == 'C')
	{
		vars->map[vars->next_x][vars->next_y] = 'P';
		vars->map[vars->x][vars->y] = '0';
		vars->x = vars->next_x;
		vars->y = vars->next_y;
		vars->moves++;
		vars->collect++;
	}
	else if (vars->map[vars->next_x][vars->next_y] == 'E')
	{
		if (vars->collect == vars->collect_map)
		{
			ft_printf("\nBravo, vous avez termine le jeu !");
			close_window(vars);
		}
	}
}

void	move_player(t_vars *vars)
{
	update_player(vars);
	if (vars->map[vars->next_x][vars->next_y] == 'R')
	{
		ft_printf("\nAie !, la Team Rocket vous a eue...");
		close_window(vars);
	}
	else
	{
		vars->next_x = vars->x;
		vars->next_y = vars->y;
	}
}
