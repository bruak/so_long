/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:08:59 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/07 18:09:00 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *a, const char *b, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(b));
	i = 0;
	while (b[i] && i < size - 1)
	{
		a[i] = b[i];
		i++;
	}
	a[i] = 0;
	return (ft_strlen(b));
}
