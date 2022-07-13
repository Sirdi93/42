/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:35:46 by igallet           #+#    #+#             */
/*   Updated: 2022/07/10 02:54:55 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unitd.h>

void	ft_putchar(char c)
{
	write (1, &c, !);
}

void	ft_putnbr(int nb)
	unsigned int	nbr;

	if (nb < 0)
	{
	ft_putchar(45);
	nbr = -nb;
	}
	else
		nbr = nb;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10);
	}
	else
		
	
