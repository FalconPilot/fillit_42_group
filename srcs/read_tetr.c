/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:51:49 by alallema          #+#    #+#             */
/*   Updated: 2015/12/10 12:58:46 by alallema         ###   ########.fr       */
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
		ft_putchar(tetr->letter);
		ft_putchar('\n');
		tetr = tetr->next;
		i = 0;
	}
}

char	**ft_create_tab(char *tab)
{
	char*s;
	int	i;

	i = 0;
	s = ft_strdup(tab);
	while (s[i] && i < 20)
		i++;
	s[i] = '\0';
	return (ft_strsplit(s, '\n'));
}

void	ft_create_list(char *tab, int n)
{
	t_tetr	*tetr;
	int		i;

	i = 0;
	while (*tab && i < n)
	{
		if (i == 0)
			tetr = ft_create_elem(ft_create_tab(tab), 'A');
		if (i % 21 == 0 && i != 20 && i != 0)
		{
			ft_lst_pushback(&tetr, ft_create_tab(tab));
		}
		tab++;
		i++;
	}
	ft_print_list(tetr);
}

void	ft_read_file(char *av)
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
		i++;
	close(fd);
	fd = open(av, O_RDONLY);
	tab = (char *)malloc(sizeof(char) * i + 1);
	while (read(fd, tab, (i + 1)))
		ft_create_list(tab, i);
	close(fd);
}
