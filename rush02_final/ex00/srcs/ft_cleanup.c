/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:33:24 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/24 18:41:26 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_free_list(t_list *node)
{
	if (!node)
		return ;
	ft_free_list(node->next);
	if (node->word)
		free(node->word);
	if (node->nbr)
		free(node->nbr);
	free(node);
}

void	ft_cleanup(t_status status, t_list *dict, t_list *res, char *nbr)
{
	if (status == arg_error)
		ft_putstr("Error\n");
	else
	{
		if (nbr)
			free(nbr);
	}
	if (status == missing_key || status == no_dict || status == invalid_number)
		ft_putstr("Dict Error\n");
	ft_free_list(dict);
	ft_free_list(res);
}
