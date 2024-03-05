/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:09:59 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/11 16:53:24 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>

char	**free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

void	if_empty_file_to_abort(t_map *all_data, int all_y_len)
{
	(void)all_y_len;
	(void)all_data;
	exit(1);
}

void	if_there_just_new_line(int x)
{
	(void)x;
	write(2, "Error, there is just new line, no map.\n", 40);
	exit(1);
}
