/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:11:16 by igallet           #+#    #+#             */
/*   Updated: 2022/07/18 19:13:53 by igallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char s1, char s2)
{
	while (s1 && s1 == s2)
	{
		s1++;
		s2++;
	}
	return (s1 - s2);
}

void	ft_sort_params(int i, int b, char **argv)
{	
	int		valeur_retour;
	char	*swap;

	while (argv[i])
	{
		while (argv[b])
		{
			valeur_retour = ft_strcmp(*argv[i], *argv[b]);
			if (valeur_retour > 0)
			{
				swap = argv[i];
				argv[i] = argv[b];
				argv[b] = swap;
			}
			b++;
		}
		i++;
		b = i + 1;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	v;

	(void) argc;
	v = '\n';
	i = 1;
	ft_sort_params(1, (i + 1), argv);
	while (argv[i])
	{
		ft_putstr(argv[i]);
		write(1, &v, 1);
		i++;
	}
}
