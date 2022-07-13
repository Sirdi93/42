/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:30:26 by igallet           #+#    #+#             */
/*   Updated: 2022/07/10 01:29:12 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	comb[3];

	comb[0] = 0;
	while (comb[0] <= 9)
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= 9)
		{
			comb[2] = comb[1] + 1;
			while (comb[2] <= 9)
			{
				ft_putchar(comb[0] + 48);
				ft_putchar(comb[1] + 48);
				ft_putchar(comb[2] + '0');
				if (comb[0] < 7)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				comb[2]++;
			}
			comb[1]++;
		}
		comb[0]++;
	}
}
