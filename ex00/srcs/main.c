/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:16:20 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/24 19:06:14 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*g_blocks_to_str[14] = {
	"",
	"",
	"1000",
	"1000000",
	"1000000000",
	"1000000000000",
	"1000000000000000",
	"1000000000000000000",
	"1000000000000000000000",
	"1000000000000000000000000",
	"1000000000000000000000000000",
	"1000000000000000000000000000000",
	"1000000000000000000000000000000000",
	"1000000000000000000000000000000000000"
};

char	*g_initial_keys[29] = {
	"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
	"10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
	"20", "30", "40", "50", "60", "70", "80", "90", "100"
};

int	main(int argc, char **argv)
{
	char		*word;
	t_list		*dict;
	t_list		*result;
	t_status	status;

	dict = NULL;
	result = NULL;
	status = ft_init(&dict, argc, argv, &word);
	if (status == arg_error || status == missing_key
		|| status == no_dict || status == invalid_number)
	{
		ft_cleanup(status, dict, result, word);
		return (0);
	}
	status = print;
	if (ft_strcmp(word, "0") == 0)
		ft_list_push_front(&result, ft_list_find_word(dict, word), NULL);
	else
		status = ft_print_word(dict, &result, word);
	if (status == print || status == no_print)
		ft_print_list(result, NULL);
	ft_cleanup(status, dict, result, word);
	return (0);
}
