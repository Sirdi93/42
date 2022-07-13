/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:04:28 by igallet           #+#    #+#             */
/*   Updated: 2022/07/13 15:48:43 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)

{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (str[i] != to_find[y])
	{
		i++ ;
		y++;
	}
	if (str[i] == '\0')
		return (0);
	return (str);
}
