/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:53:27 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/24 18:17:48 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	ft_get_size(int size, char **strs)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < size)
	{
		res += ft_strlen(strs[i]);
		i++;
	}
	res += (size - 1);
	return (res);
}

char	*ft_strjoin(int size, char **strs, char sep)
{
	char	*res;
	int		res_size;
	int		word;
	int		res_i;
	int		strs_i;

	if (!size)
		return ((char *)malloc(0));
	res_size = ft_get_size(size, strs);
	res = (char *)malloc(sizeof(char) * (res_size + 1));
	word = 0;
	res_i = 0;
	while (word < size)
	{
		strs_i = 0;
		while (strs[word][strs_i])
			res[res_i++] = strs[word][strs_i++];
		if (word < size - 1)
			res[res_i++] = sep;
		word++;
	}
	res[res_i] = '\0';
	return (res);
}
