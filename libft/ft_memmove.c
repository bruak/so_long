/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:10:11 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/07 18:10:12 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *sour, size_t len)
{
	if (dest == 0 && sour == 0)
		return (0);
	if (dest < sour)
		ft_memcpy(dest, sour, len);
	else if (dest > sour)
	{
		while (len--)
			*((unsigned char *)(dest + len)) = *((unsigned char *)(sour + len));
	}
	return (dest);
}
