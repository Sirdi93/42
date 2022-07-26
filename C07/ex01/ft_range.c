/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:24:30 by igallet           #+#    #+#             */
/*   Updated: 2022/07/26 17:08:34 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	i;
	int	calc;

	i = 0;
	calc = max - min;
	dest = malloc(sizeof(int) * calc);
	if (min >= max)
		return (0);
	while (min < max)
	{
		dest[i] = min;
		i++;
		min = min + 1;
	}
	return (dest);
}
