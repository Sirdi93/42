/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:24:01 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/24 18:39:59 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static t_status	ft_print_hundredth(t_list *dict, t_list **result, char *str)
{
	char	c[2];
	char	*res;

	c[0] = str[0];
	if (c[0] == '0')
		return (no_print);
	c[1] = '\0';
	res = ft_list_find_word(dict, c);
	if (!res)
		return (invalid_number);
	ft_list_push_front(result, res, NULL);
	res = ft_list_find_word(dict, "100");
	if (!res)
		return (invalid_number);
	ft_list_push_front(result, res, NULL);
	return (print);
}

static t_status	ft_print_tenth(t_list *dict, t_list **result, char *str, int i)
{
	char	c[3];
	char	*res;

	c[0] = str[i];
	c[2] = '\0';
	if (str[i] == '0')
		return (no_print);
	if (str[i] == '1')
		c[1] = str[i + 1];
	else
		c[1] = '0';
	res = ft_list_find_word(dict, c);
	if (!res)
		return (invalid_number);
	ft_list_push_front(result, res, ft_strndup(c, 0, 2));
	return (print);
}

static t_status	ft_print_unit(t_list *dict, t_list **result, char *str, int len)
{
	int			i;
	char		c[2];
	char		*res;

	i = (len > 1) + (len == 3);
	if (str[i] == '0' || (len > 1 && str[i - 1] == '1'))
		return (no_print);
	c[0] = str[i];
	c[1] = '\0';
	res = ft_list_find_word(dict, c);
	if (!res)
		return (invalid_number);
	ft_list_push_front(result, res, ft_strndup(c, 0, 1));
	return (print);
}

static t_status	ft_print_block(t_list *dict, t_list **result, char *str, int l)
{
	int			printed;
	t_status	status;

	printed = 0;
	if (l == 3)
		status = ft_print_hundredth(dict, result, str);
	if (status == invalid_number)
		return (status);
	else if (status == print)
		printed = 1;
	if (l > 1)
		status = ft_print_tenth(dict, result, str, (l == 3));
	if (status == invalid_number)
		return (status);
	else if (status == print)
		printed = 1;
	status = ft_print_unit(dict, result, str, l);
	if (status == invalid_number)
		return (status);
	if (status == print || printed)
		return (print);
	return (no_print);
}

t_status	ft_print_word(t_list *dict, t_list **result, char *str)
{
	int			nb_block;
	int			block_size;
	char		*block;
	char		*res;
	t_status	status;

	nb_block = ft_count_blocks(str);
	if (nb_block > 13)
		return (invalid_number);
	block_size = ft_strlen(str) % 3;
	if (!block_size)
		block_size = 3;
	block = ft_strndup(str, 0, block_size);
	status = ft_print_block(dict, result, block, block_size);
	if (status == invalid_number)
		return (invalid_number);
	free(block);
	res = ft_list_find_word(dict, g_blocks_to_str[nb_block]);
	if (res && status == print)
		ft_list_push_front(result, res, NULL);
	if (nb_block > 1)
		status = ft_print_word(dict, result, str + block_size);
	return (status);
}
