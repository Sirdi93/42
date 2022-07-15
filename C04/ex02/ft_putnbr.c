/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:53:50 by igallet           #+#    #+#             */
/*   Updated: 2022/07/14 14:19:57 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	div;

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	div = 10;
	while (div <= nb)
	{
		div *= 10;
	}
	while (nb > 10)
	{
		div = div / 10;
		ft_putchar(nb / div + 48);
		nb = nb % div;
	}
	ft_putchar(nb + 48);
	ft_putchar('\n');
}
