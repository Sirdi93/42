/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:55:02 by igallet           #+#    #+#             */
/*   Updated: 2022/07/12 18:39:46 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_strcapitalize(char *str)
{
	int	i;
	int	m;

	i = 0;
	m = 1;
	while (str[i])
	{
		if (!((str[i] >= 32) && (str[i] <= 47 \
			|| str[i] >= 58) && (str[i] <= 64)))
		{
			if (str[i] >= 'a' && str[i] <= 'z' && m == 1)
			{
				str[i] = str[i] - 'a' + 'A';
				m = 0;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z' && m == 0)
				str[i] = str[i] + 'a' - 'A';
		}
		else
			m = 1;
		i++ ;
	}
	return (*str);
}
