/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:08:15 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/07 18:08:16 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int a)
{
	int	i;

	i = (int)ft_strlen(str);
	while (i >= 0)
	{
		if (*(str + i) == (char)a)
			return ((char *)str + i);
		i--;
	}
	return (0);
}
