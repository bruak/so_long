/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:37:03 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/12 14:10:10 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

void	player_counter(t_map *all_maps, int y, int x)
{
	all_maps->player_count++;
	all_maps->player_x = x;
	all_maps->player_y = y;
}

void	exit_counter(t_map *all_maps, int y, int x)
{
	all_maps->exit_count++;
	all_maps->exit_x_location = x;
	all_maps->exit_y_location = y;
}

void	coin_counter(t_map *all_maps, int y, int x)
{
	(void)y;
	(void)x;
	all_maps->coin_count++;
}

void	for_esc(t_map *all_maps, int error_code, int free_code)
{
	int	i;

	i = 0;
	if (error_code == 42)
		write(1, "You win\n", 8);
	else if (error_code == ESC || error_code == 0)
		write(1, "Game Cancelled\n", 15);
	while ((i < all_maps->map_y && free_code != 1))
		free(all_maps->map[i++]);
	while (i < all_maps->map_y && free_code != 1)
		free(all_maps->control_copy_for_map[i++]);
	close_image_for_esc_key(all_maps);
	exit(1);
}

int	control_keys_for_player(int key_value, t_map *all_data)
{
	if (key_value == ESC)
		for_esc(all_data, ESC, 2);
	else if (key_value == W)
		player_moves(all_data, 0, -1);
	else if (key_value == A)
		player_moves(all_data, -1, 0);
	else if (key_value == S)
		player_moves(all_data, 0, 1);
	else if (key_value == D)
		player_moves(all_data, 1, 0);
	return (1);
}
