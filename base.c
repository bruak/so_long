/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:55:04 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/12 13:44:07 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

void	fd_check_is_null_true(t_map *all_data, int fd)
{
	if (fd < 0)
	{
		ft_putstr_fd("Error, folder does not open.\n", 2);
		close(fd);
		exit(1);
	}
	if (read(fd, NULL, 0) == -1)
	{
		ft_putstr_fd("Error, folder does not open.\n", 2);
		close(fd);
		map_error_and_free(all_data, 0);
		exit(1);
	}
}

void	is_not_expected_arg_name(char *arg, char *expected)
{
	int	i;
	int	j;

	i = (int)ft_strlen(arg) - 1;
	j = (int)ft_strlen(expected) - 1;
	while (arg[i] && expected[j])
	{
		if (arg[i] != expected[j])
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("Usage: ./so_long [map.ber]\n", 2);
			exit(1);
		}
		i--;
		j--;
	}
}

void	full_zero_for_new_struct(t_map *all_data)
{
	all_data->map_x = 0;
	all_data->map_y = 0;
	all_data->exit_count = 0;
	all_data->player_count = 0;
	all_data->coin_count = 0;
	all_data->player_x = 0;
	all_data->player_y = 0;
	all_data->exit_x_location = 0;
	all_data->exit_y_location = 0;
	all_data->player_steps = 0;
	all_data->map = NULL;
	all_data->control_copy_for_map = NULL;
	all_data->mlx_ptr = NULL;
	all_data->win = NULL;
	all_data->player_image = NULL;
	all_data->coin_image = NULL;
	all_data->exit_image = NULL;
	all_data->floor_image = NULL;
}

void	control_map_on_copied_map(t_map *all_data, int fd, char *mapname_for_fd)
{
	int		y_len;
	char	*line;

	y_len = map_size(fd);
	if_file_empty(all_data, y_len);
	all_data->map = (char **)malloc(sizeof(char *) * (y_len));
	all_data->control_copy_for_map = (char **)malloc(sizeof(char *) * (y_len));
	map_malloc_control(all_data);
	fd = open(mapname_for_fd, O_RDONLY);
	fd_check_is_null_true(all_data, fd);
	while (get_next_line(fd, &line) > 0)
	{
		all_data->map[all_data->map_y] = ft_strdup(line);
		all_data->control_copy_for_map[all_data->map_y] = ft_strdup(line);
		map_malloc_control(all_data);
		map_width_control_is_samelen(all_data, fd);
		free(line);
		all_data->map_y++;
	}
	close(fd);
	p_e_c_01_control(all_data);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	all_data;

	if (ac != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Usage: ./so_long [map.ber]\n", 2);
		return (1);
	}
	is_not_expected_arg_name(av[1], ".ber");
	fd = open(av[1], O_RDONLY);
	fd_check_is_null_true(&all_data, fd);
	full_zero_for_new_struct(&all_data);
	control_map_on_copied_map(&all_data, fd, av[1]);
	game_controls_and_start(&all_data);
	free_all(av);
	return (0);
}
