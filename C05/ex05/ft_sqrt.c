/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:32:01 by igallet           #+#    #+#             */
/*   Updated: 2022/07/19 21:00:48 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(long int nb)
{
	long int	a;

	a = 0;
	while (a * a <= nb)
	{
		if (a * a == nb)
		{
			return (a);
		}	
		a++;
	}
	return (0);
}