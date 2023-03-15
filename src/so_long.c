/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:35:06 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/15 20:50:33 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	so_long(t_vars *vars)
// {
// 	vars->mlx = mlx_init();
// 	vars->win = mlx_new_image(vars->mlx, 500, 500);
// 	mlx_put_image_to_window(vars->mlx, mlx_new_window(vars->mlx, 500, 500, "so_long"), vars->win, 0, 0);
// 	mlx_key_hook(vars->win, key_hook, &vars);
// 	mlx_hook(vars->win, ON_DESTROY, (1L<<0), closeWindow, &vars);
// 	mlx_loop(vars->mlx);
// }

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_image(vars.mlx, 500, 500);
	//mlx_put_image_to_window(vars.mlx, mlx_new_window(vars.mlx, 500, 500, "so_long"), vars.win, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, ON_DESTROY, (1L<<0), closeWindow, &vars);
	mlx_loop(vars.mlx);
	return (0);
}