/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:22:07 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/24 17:31:23 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_status	ft_init(t_list **dict, int argc, char **argv, char **nbr)
{
	char		*path;
	t_status	status;

	path = "./dict/numbers.dict";
	if (argc == 2)
		*nbr = argv[1];
	else if (argc == 3)
	{
		path = argv[1];
		*nbr = argv[2];
	}
	else
		return (arg_error);
	status = ft_check_argument(*nbr);
	if (status == invalid_number)
		return (arg_error);
	*nbr = ft_parse_argument(*nbr);
	status = ft_parse_dict(dict, path);
	return (status);
}
