/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:51:14 by lbrillar          #+#    #+#             */
/*   Updated: 2022/07/11 12:18:29 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	drawline(char open, char mid, char close, int x)
{
	
	ft_putchar(open);
	x--;
	while (x - 1 > 0)
	{
		ft_putchar(mid);
		x--;
	}
	if (x == 1)
		ft_putchar(close);
}

void	rush(int x, int y)
{

	drawline('A', 'B', 'C', x);
	ft_putchar('\n');
	y--;
	while (y - 1 > 0)
	{
		drawline('B', ' ', 'B', x);
		ft_putchar('\n');
		y--;
	}
	if (y == 1)
	{
		drawline('C', 'B', 'A', x);
		ft_putchar('\n');
	}
}
