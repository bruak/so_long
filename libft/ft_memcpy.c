/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:10:15 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/07 18:10:16 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *b, const void *a, size_t len)
{
	size_t	i;

	if (len == 0 || b == a)
		return (b);
	i = 0;
	while (i < len)
	{
		((unsigned char *) b)[i] = ((unsigned char *) a)[i];
		i++;
	}
	return (b);
}
