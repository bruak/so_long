/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:03:27 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/12 13:38:48 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <unistd.h>

void	map_width_control_is_samelen(t_map *all_map, int fd)
{
	static int	tmp;

	if (all_map->map_y == 0)
	{
		tmp = (int)ft_strlen(all_map->map[all_map->map_y]);
		all_map->map_x = tmp;
	}
	else if (tmp != (int)ft_strlen(all_map->map[all_map->map_y]))
	{
		write(2, "Map's broken, fix it bro!\n", 26);
		close(fd);
		map_error_and_free(all_map, all_map->map_y);
	}
}

void	map_error_and_free(t_map *all_map, int map_y_value)
{
	while (map_y_value >= 0 && all_map->map[map_y_value])
	{
		free(all_map->map[map_y_value]);
		free(all_map->control_copy_for_map[map_y_value]);
		map_y_value--;
	}
	write(2, "Error!\n", 7);
	exit(1);
}

int	map_size(int fd)
{
	int		i;
	char	*ptr;

	ptr = NULL;
	i = 0;
	while (get_next_line(fd, &ptr) > 0)
	{
		i++;
		free(ptr);
	}
	free(ptr);
	return (i);
}

void	free_map_all_of_them(t_map *all_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all_map->map)
	{
		free(all_map->map);
		i++;
	}
	free(all_map->map);
	while (all_map->control_copy_for_map)
	{
		free(all_map->control_copy_for_map);
		j++;
	}
	(void)i;
	(void)j;
	free(all_map->control_copy_for_map);
}

void	map_malloc_control(t_map *all_map)
{
	if (!(all_map->map))
		free_map_all_of_them(all_map);
	else if (!(all_map->control_copy_for_map))
		free_map_all_of_them(all_map);
}
