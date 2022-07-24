/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:57:37 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/24 16:05:37 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_isspace(char c)
{
	if (c >= '\t' && c <= '\r')
		return (1);
	return (c == ' ');
}

int	ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_atoa(char *str, int *i)
{
	int		j;
	char	*res;

	*i = 0;
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] != '+' && !ft_isnum(str[*i]))
		return (NULL);
	if (str[*i] == '+')
		(*i)++;
	while (str[*i] == '0' && ft_isnum(str[*i + 1]))
		(*i)++;
	j = *i;
	while (ft_isnum(str[j]))
		j++;
	if (*i == j)
		return (NULL);
	res = ft_strndup(str, *i, j);
	*i = j;
	return (res);
}

int	ft_count_blocks(char *str)
{
	int	len;
	int	res;

	len = ft_strlen(str);
	res = len / 3;
	if (len % 3)
		res++;
	return (res);
}

int	ft_is_initial_key(char *str)
{
	int	i;

	i = 0;
	while (i < 29)
	{
		if (ft_strcmp(str, g_initial_keys[i]) == 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < 14)
	{
		if (ft_strcmp(str, g_blocks_to_str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
