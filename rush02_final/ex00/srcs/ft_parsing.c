/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:25:33 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/24 18:18:55 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static char	*ft_parse_word(char *str, int start, int end)
{
	char	*word;
	char	**strs;

	word = ft_strndup(str, start, end);
	strs = ft_split(word, ' ');
	free(word);
	word = ft_strjoin(ft_split_size(strs), strs, ' ');
	ft_free_split(strs);
	return (word);
}

static t_status	ft_parse_numbers(t_list **list, char *str)
{
	int		i;
	int		j;
	char	*word;
	char	*nbr;

	nbr = ft_atoa(str, &i);
	if (!nbr || ft_is_duplicate(*list, nbr))
		return (invalid_number);
	while (str[i] != ':')
	{
		if (str[i] == '\0' || str[i] == '\n')
			return (wrong_format);
		i++;
	}
	while (str[i] == ' ' || str[i] == ':')
		i++;
	j = i;
	while (str[j] != '\n')
		j++;
	word = ft_parse_word(str, i, j);
	if (ft_is_initial_key(nbr))
		ft_list_push_front(list, word, nbr);
	else
		ft_free_words(word, nbr);
	return (valid_number);
}

static t_status	ft_parse_line(t_list **list, int size, int fd)
{
	char		*res;
	t_status	status;

	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (no_dict);
	status = valid_number;
	read(fd, res, size);
	res[size] = '\0';
	if (res[0] && res[0] != '\n')
	{
		if (ft_check_nonprintable(res))
			return (wrong_format);
		status = ft_parse_numbers(list, res);
	}
	free(res);
	return (status);
}

t_status	ft_parse_dict(t_list **list, char *path)
{
	int			size;
	int			size_fd;
	int			read_fd;
	char		c;
	t_status	status;

	size = 0;
	size_fd = open(path, O_RDONLY);
	read_fd = open(path, O_RDONLY);
	if (size_fd < 0 || read_fd < 0)
		return (no_dict);
	while (read(size_fd, &c, 1))
	{
		size++;
		if (c == '\n' || c == '\0')
		{
			status = ft_parse_line(list, size, read_fd);
			if (status == invalid_number || status == wrong_format)
				return (status);
			size = 0;
		}
	}
	return (ft_check_initial_keys(*list));
}

char	*ft_parse_argument(char *str)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (i == ft_strlen(str))
		res = ft_strndup("0", 0, 1);
	else
		res = ft_strndup(str, i, ft_strlen(str));
	return (res);
}
