/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:08:30 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/07 18:08:35 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t	counter;
	char	*pointer_to_dest_start;
	size_t	src_len;

	pointer_to_dest_start = dst;
	src_len = ft_strlen(src);
	counter = 0;
	while (counter < len)
	{
		if (counter < src_len)
		{
			*dst = *src;
			src++;
		}
		else
			*dst = '\0';
		dst++;
		counter++;
	}
	return (pointer_to_dest_start);
}
