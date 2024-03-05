/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:00:31 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/11 16:59:11 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	wall_control_on_frame(t_map *all_maps, int y, int x)
{
	int	for_zero;

	for_zero = 1;
	if (y == 0 && all_maps->map[y][x] != '1')
		map_error_and_free(all_maps, y);
	if (x == 0 && all_maps->map[y][x] != '1')
		map_error_and_free(all_maps, y);
	if (y == (all_maps->map_y - for_zero) && all_maps->map[y][x] != '1')
		map_error_and_free(all_maps, y);
	if (x == (all_maps->map_x - for_zero) && all_maps->map[y][x] != '1')
		map_error_and_free(all_maps, y);
}

void	pec01_counter(t_map *all_maps, int y, int x)
{
	int		for_zero;

	for_zero = 1;
	if (all_maps->map[y][x] == 'P')
		player_counter(all_maps, y, x);
	if (all_maps->map[y][x] == 'E')
		exit_counter(all_maps, y, x);
	if (all_maps->map[y][x] == 'C')
		coin_counter(all_maps, y, x);
	if (y == all_maps->map_y - for_zero && (all_maps->player_count != 1
			|| all_maps->exit_count != 1 || all_maps->coin_count == 0))
	{
		write(2, "Error, there is no player or exit or coin\n", 43);
		map_error_and_free(all_maps, (all_maps->map_y - for_zero));
	}
}

void	control_every_achievement(t_map *all_maps, int y, int x)
{
	int		for_zero;

	for_zero = -1;
	if (all_maps->map[y][x] == 'P')
		player_counter(all_maps, y, x);
	if (all_maps->map[y][x] == 'E')
		exit_counter(all_maps, y, x);
	if (all_maps->map[y][x] == 'C')
		coin_counter(all_maps, y, x);
	if (y == all_maps->map_y - for_zero && (all_maps->player_count != 1
			|| all_maps->exit_count != 1 || all_maps->coin_count == 0))
	{
		write(2, "Error, there is no player or exit or coin\n", 43);
		map_error_and_free(all_maps, (all_maps->map_y - for_zero));
	}
}

void	every_coin_to_reach_control(char **fake_control_map, int y, int x)
{
	if (fake_control_map[y][x] == '\0')
		if_there_just_new_line(x);
	if (fake_control_map[y][x] == 'E')
		fake_control_map[y][x] = '1';
	if (fake_control_map[y][x] == '-' || fake_control_map[y][x] == '1' )
		return ;
	fake_control_map[y][x] = '-';
	every_coin_to_reach_control(fake_control_map, y + 1, x);
	every_coin_to_reach_control(fake_control_map, y - 1, x);
	every_coin_to_reach_control(fake_control_map, y, x + 1);
	every_coin_to_reach_control(fake_control_map, y, x - 1);
}

void	p_e_c_01_control(t_map *all_maps)
{
	int	x;
	int	y;
	int	for_begin_zero;

	for_begin_zero = 1;
	y = 0;
	while (y <= (all_maps->map_y - for_begin_zero))
	{
		x = 0;
		while (x <= (all_maps-> map_x - for_begin_zero))
		{
			wall_control_on_frame(all_maps, y, x);
			pec01_counter(all_maps, y, x);
			anything_other_than_pec01(all_maps, y, x);
			x++;
		}
		y++;
	}
	every_coin_to_reach_control(all_maps->control_copy_for_map,
		all_maps->player_y, all_maps->player_x);
	is_there_any_coin_unreachable(all_maps);
}
