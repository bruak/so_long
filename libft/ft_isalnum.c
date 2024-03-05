/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:07:35 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/11 17:00:19 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int ch)
{
	int	alpha;
	int	digit;

	alpha = ft_isalpha(ch);
	digit = ft_isdigit(ch);
	if (alpha == 1 || digit == 1)
		return (1);
	else
		return (0);
}
