/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:35:06 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/16 10:35:45 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
    t_vars vars;

    size_of_map(&vars);
    malloc_tab(&vars);
    if (map_have_errors(&vars) == 0)
        return (0);
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, vars.width * 64, vars.height * 64, "So Long");
    vars.moves = 0;
    get_player_position(&vars);
    mlx_hook(vars.win, 2, 1, buttonPressed, &vars);
    mlx_loop_hook(vars.mlx, print_map, &vars);
    mlx_hook(vars.win, 17, 1, closeWindow, &vars);
    mlx_loop(vars.mlx);
    return (0);
}