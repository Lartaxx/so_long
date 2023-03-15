/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:35:06 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/15 21:52:42 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 800, 600, "Affichage des touches");

    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, (1L<<0), closeWindow, &vars);
    mlx_loop(vars.mlx);
    return (0);
}