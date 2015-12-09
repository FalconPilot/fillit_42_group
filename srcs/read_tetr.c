/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:51:49 by alallema          #+#    #+#             */
/*   Updated: 2015/12/09 19:41:25 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include <main.h>

void	ft_print_list(t_tetr *tetr)
{
	int	i;

	i = 0;
	while (tetr)
	{
		while (tetr->pattern[i])
		{
			ft_putstr(tetr->pattern[i]);
			ft_putchar('\n');
			i++;
		}
		tetr = tetr->next;
		i = 0;
	}
}

t_tetr	*ft_create_lst(char *s, int n)
{
	t_tetr	*tetr;
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char*) * 5);
	while (s && i < n)
	{
		tab[j] = (char *)malloc(sizeof(char) * 5);
		while (s[i] != '\n' && i < n)
			tab[j][k++] = s[i++];
		tab[j][k] = '\0';
		i++;
		j++;
		if (i == 20)
		{
			tab[j] = NULL;
			tetr = ft_create_elem(tab);
			tab = (char **)malloc(sizeof(char*) * 5);
			j = 0;
		}
		if (i != 20 && j == 5 && k == 4)
		{
			tab[j] = NULL;
			ft_lst_pushback(&tetr, tab);
			tab = (char **)malloc(sizeof(char*) * 5);
			j = 0;
		}
		k = 0;
	}
	return (tetr);
}

void	ft_create_tab(char *av)
{
	int		fd;
	char	buf;
	char	*tab;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_putstr("invalid file");
	while (read(fd, &buf, 1))
	{
		i++;
	}
	close(fd);
	fd = open(av, O_RDONLY);
	tab = (char *)malloc(sizeof(char) * i + 1);
	while (read(fd, tab, (i + 1)))
		ft_print_list(ft_create_lst(tab, i));
	close(fd);
}
