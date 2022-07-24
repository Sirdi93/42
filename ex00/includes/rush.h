/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:17:15 by ple-lez           #+#    #+#             */
/*   Updated: 2022/07/24 18:19:14 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

extern char	*g_blocks_to_str[14];
extern char	*g_initial_keys[29];

typedef struct s_list
{
	struct s_list	*next;
	char			*word;
	char			*nbr;
}					t_list;

typedef enum e_status
{
	arg_error,
	valid_number,
	invalid_number,
	print,
	no_print,
	missing_key,
	complete_dict,
	no_dict,
	wrong_format
}				t_status;

int			ft_isnum(char c);
int			ft_isspace(char c);
int			ft_strlen(char *str);
int			ft_split_size(char **str);
int			ft_count_blocks(char *str);
int			ft_is_initial_key(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_check_nonprintable(char *str);
int			ft_is_duplicate(t_list *list, char *nbr);

void		ft_putstr(char *str);
void		ft_free_split(char **str);
void		ft_free_list(t_list *node);
void		ft_free_words(char *s1, char *s2);
void		ft_print_list(t_list *node, t_list *prev);
void		ft_list_push_front(t_list **begin_list, char *word, char *nbr);
void		ft_cleanup(t_status status, t_list *dict, t_list *res, char *nbr);

char		*ft_atoa(char *str, int *i);
char		*ft_parse_argument(char *str);
char		*ft_strndup(char *str, int start, int end);
char		*ft_list_find_word(t_list *node, char *nbr);
char		*ft_strjoin(int size, char **strs, char sep);

char		**ft_split(char *str, char sep);

t_status	ft_check_argument(char *str);
t_status	ft_check_initial_keys(t_list *list);
t_status	ft_parse_dict(t_list **begin_list, char *path);
t_status	ft_print_word(t_list *node, t_list **result, char *str);
t_status	ft_init(t_list **dict, int argc, char **argv, char **nbr);

#endif
