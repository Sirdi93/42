/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:08:41 by igallet           #+#    #+#             */
/*   Updated: 2022/07/19 21:00:00 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(long int nb)
{
	long int	n;

	n = 2;
	if (nb < 2)
		return (0);
	while (n < nb)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}

int	ft_find_next_prime(long int nb)
{
	long int	n;

	n = nb;
	while (ft_is_prime(n) == 0)
		n++;
	return (n);
}
