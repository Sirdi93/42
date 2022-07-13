/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:43:23 by igallet           #+#    #+#             */
/*   Updated: 2022/07/13 12:33:03 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)

{
	int	i;

	i = 0;
	if (src[i] > dest[size])
		src[i] = dest[size -1];
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (src[i] == dest[size])
	{
		dest[i] = '\0';
		i++;
	}
	return (*dest);
}
