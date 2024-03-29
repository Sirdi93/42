/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:46:59 by igallet           #+#    #+#             */
/*   Updated: 2022/07/11 22:15:30 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)

{
	int	i;

	i = 0;
	while (str[i] >= 32 && str[i] <= 126)
	{
		i++;
		return (0);
	}
	if (str[i] == '\0')
		return (1);
}
