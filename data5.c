/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:24 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/12 14:09:18 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include <unistd.h>
#include "libft/libft.h"

void	close_image_for_esc_key(t_map *all_maps)
{
	if (all_maps->exit_image)
		mlx_destroy_image(all_maps->mlx_ptr, all_maps->exit_image);
	if (all_maps->wall_image)
		mlx_destroy_image(all_maps->mlx_ptr, all_maps->wall_image);
	if (all_maps->player_image)
		mlx_destroy_image(all_maps->mlx_ptr, all_maps->player_image);
	if (all_maps->floor_image)
		mlx_destroy_image(all_maps->mlx_ptr, all_maps->floor_image);
	if (all_maps->coin_image)
		mlx_destroy_image(all_maps->mlx_ptr, all_maps->coin_image);
	if (all_maps->mlx_ptr)
		mlx_destroy_window(all_maps->mlx_ptr, all_maps->win);
}

void	player_moves(t_map *all_data, int x, int y)
{
	if (all_data->map[all_data->player_y + y][all_data->player_x + x] == '1')
		return ;
	if (all_data->coin_count == 0 && all_data->map[all_data->player_y + y]
		[all_data->player_x + x] == 'E')
		for_esc(all_data, 42, 2);
	else if (all_data->map[all_data->player_y + y]
		[all_data->player_x + x] == 'E')
		return ;
	if (all_data->map[all_data->player_y + y][all_data->player_x + x] == 'C')
		all_data->coin_count--;
	all_data->map[all_data->player_y][all_data->player_x] = '0';
	all_data->player_x += x;
	all_data->player_y += y;
	all_data->map[all_data->player_y][all_data->player_x] = 'P';
	all_data->player_steps++;
	image_to_window_locationby_location(all_data);
	write(1, "Steps ", 6);
	ft_putnbr_fd(all_data->player_steps, 1);
	write(1, "\n", 1);
}

int	when_window_down(t_map *all_data_to_free)
{
	for_esc(all_data_to_free, 0, all_data_to_free->map_y);
	return (1);
}

void	anything_other_than_pec01(t_map *all_maps, int y, int x)
{
	if (all_maps->map[y][x] != '1' && all_maps->map[y][x] != '0'
	&& all_maps->map[y][x] != 'P' && all_maps->map[y][x] != 'E'
	&& all_maps->map[y][x] != 'C')
	{
		write(2, "Error, there is a wrong character in map\n", 42);
		map_error_and_free(all_maps, y);
	}
}

void	if_file_empty(t_map *all_data, int all_y_len)
{
	if (all_y_len == 0)
	{
		write(2, "Error, file is empty\n", 22);
		if_empty_file_to_abort(all_data, all_y_len);
	}
}
