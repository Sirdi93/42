/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:50:32 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/24 19:00:21 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_check_nonprintable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 32 || str[i] > 126) && !ft_isspace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_duplicate(t_list *list, char *nbr)
{
	char	*word;

	word = ft_list_find_word(list, nbr);
	if (word)
	{
		free(word);
		free(nbr);
		return (1);
	}
	return (0);
}

t_status	ft_check_argument(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (invalid_number);
		i++;
	}
	if (i == 0)
		return (invalid_number);
	return (valid_number);
}

t_status	ft_check_initial_keys(t_list *list)
{
	int		i;
	char	*word;

	i = 0;
	while (i < 29)
	{
		word = ft_list_find_word(list, g_initial_keys[i]);
		if (!word)
			return (missing_key);
		free(word);
		i++;
	}
	i = 2;
	while (i < 14)
	{
		word = ft_list_find_word(list, g_blocks_to_str[i]);
		if (!word)
			return (missing_key);
		free(word);
		i++;
	}
	return (complete_dict);
}
