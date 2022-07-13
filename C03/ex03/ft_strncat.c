/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:41:54 by igallet           #+#    #+#             */
/*   Updated: 2022/07/13 17:34:49 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)

{
	unsigned int	i;
	unsigned int	y;

	y = 0;
	i = 0;
	while (dest[i] != '\0')
		i++ ;
	while (y != nb)
	{
		dest[i] = src[y];
		i++ ;
		y++ ;
	}
	dest = dest + '\0';
	return (dest);
}
