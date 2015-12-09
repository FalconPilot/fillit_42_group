/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:05:43 by alallema          #+#    #+#             */
/*   Updated: 2015/12/09 16:48:54 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include <main.h>
#include <stdio.h>

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
	}/*
{
	t_tetr *courant; 
	courant = tetr; 
	while (courant != NULL)
	{ 
		printf("%p - %s\n", courant, courant->pattern[0]); 
		courant = courant->next; 
	}*/
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
		{
			tab[j][k] = s[i];
			i++;
			k++;
		}
		tab[j][k] = '\0';
		i++;
		j++;
		if (i == 21)
		{
			tab[j] = NULL;
			tetr = ft_create_elem(tab);
			tab = (char **)malloc(sizeof(char*) * 5);
			j = 0;
		}
		if (i % 21 == 0 && i != 21)
		{
			tab[j] = NULL;
			ft_lst_pushback(&tetr, tab);
			tab = (char **)malloc(sizeof(char*) * 5);
			j = 0;
		}
		k = 0;
	}
	ft_print_list(tetr);
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
		if (buf != '.' && buf != '#' && buf != '\n' && buf != '\0')
			return ;
		i++;
	}
	close(fd);
	fd = open(av, O_RDONLY);
	tab = (char *)malloc(sizeof(char) * i + 1);
	while (read(fd, tab, (i + 1)))
		ft_create_lst(tab, i);
	close(fd);
}
