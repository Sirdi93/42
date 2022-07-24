/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:10:08 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/24 18:19:05 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_split_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

static int	ft_count_words(char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == '\0' || str[i + 1] == sep))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_split_words(char **res, char *str, char sep)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (str[i] == sep)
			i++;
		else
		{
			j = 0;
			while (str[i + j] && str[i + j] != sep)
				j++;
			res[w] = ft_strndup(str, i, i + j);
			i += j;
			w++;
		}
	}
	return (res);
}

char	**ft_split(char *str, char sep)
{
	int		words;
	char	**res;

	words = ft_count_words(str, sep);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = 0;
	res = ft_split_words(res, str, sep);
	return (res);
}
