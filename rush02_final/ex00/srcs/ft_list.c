/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:46:56 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/24 18:45:17 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static t_list	*ft_create_elem(char *word, char *nbr)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	res->next = NULL;
	res->word = word;
	res->nbr = nbr;
	return (res);
}

void	ft_list_push_front(t_list **begin_list, char *word, char *nbr)
{
	t_list	*node;

	node = ft_create_elem(word, nbr);
	node->next = *begin_list;
	*begin_list = node;
}

char	*ft_list_find_word(t_list *node, char *nbr)
{
	if (!node)
		return (NULL);
	if (ft_strcmp(node->nbr, nbr) == 0)
		return (ft_strndup(node->word, 0, ft_strlen(node->word)));
	return (ft_list_find_word(node->next, nbr));
}

static int	ft_print_dash(t_list *node)
{
	if (node->next->nbr && ft_strlen(node->next->nbr) == 2)
		if (node->next->nbr[0] != '1')
			if (node->nbr && ft_strlen(node->nbr) == 1)
				return (1);
	return (0);
}

void	ft_print_list(t_list *node, t_list *prev)
{
	if (!node)
		return ;
	ft_print_list(node->next, node);
	if (node->next)
	{
		if (ft_print_dash(node))
			ft_putstr("-");
		else
			ft_putstr(" ");
	}
	ft_putstr(node->word);
	if (!prev)
		ft_putstr("\n");
}
