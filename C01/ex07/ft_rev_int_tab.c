/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:31:39 by igallet           #+#    #+#             */
/*   Updated: 2022/07/12 03:12:30 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)

{
	int	x;
	int	y;
	int	swap;

	x = 0;
	y = size - 1;
	while (x < size / 2)
	{
		swap = tab[x];
		tab[x] = tab[y];
		tab[y] = swap;
		x++;
		y--;
	}
}
