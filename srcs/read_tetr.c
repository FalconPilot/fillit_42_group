/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:46:52 by alallema          #+#    #+#             */
/*   Updated: 2015/12/05 16:48:40 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include "main.h"

t_tetr	*ft_check_tab(char *s, int n)
{
	t_tetr	*tetr;
	char	**tab;
	int		i;
	int		j;
	int 	k;

	i = 0;
	j = 0;
	k = 0;
	ft_putstr(s);
	tab = (char **)malloc(sizeof(char*) * 5);
	while (!s && i < n)
	{
		tab[j] = (char *)malloc(sizeof(char) * 5);
		while (s[i] != '\n' && i % 4 == 0 && i < n)
		{
			tab[j][k] = s[i];
			i++;
			k++;
		}
		tab[j][k] = '\n';
		k = 0;
		j++;
		if (j == 4)
		{
			tetr = ft_create_elem(tab);
			j = 0;
		}
		if (j % 4 == 0 && j != 4)
		{
			ft_lst_pushback(&tetr, tab);
			j = 0;
		}
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
	fd = open(&av[0], O_RDONLY);
	if (fd == -1)
		ft_putstr("invalid file");
	while (read(fd, &buf, 1))
	{
		if (buf != '.' && buf != '#' && buf != '\n' && buf != '\0')
			return;
		i++;
	}
	ft_putnbr(i);
	ft_putchar('\n');
	close(fd);
	fd = open(&av[0], O_RDONLY);
	tab = (char *)malloc(sizeof(char) * i + 1);
	while (read(fd, tab, (i + 1)))
		ft_check_tab(tab, i);
	close(fd);
}
