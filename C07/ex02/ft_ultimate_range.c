/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:32:32 by igallet           #+#    #+#             */
/*   Updated: 2022/07/20 23:34:04 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	taille_tab;
	int	*tab;

	i = 0;
	taille_tab = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(int) * (taille_tab));
	if (tab == NULL)
		return (-1);
	i = 0;
	while (i < taille_tab)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (i);
}
