/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:46:52 by alallema          #+#    #+#             */
/*   Updated: 2015/12/04 19:05:35 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libft.h>

void	ft_print_words_tables(char **tab);

void	ft_check_tab(char *s)
{
	ft_putstr(s);
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
		i++;
	ft_putnbr(i);
	ft_putchar('\n');
	fd = open(&av[0], O_RDONLY);
	tab = (char *)malloc(sizeof(char) * i + 1);
	while (read(fd, tab, (i + 1)))
		ft_check_tab(tab);
	close(fd);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("error\n");
	}
	if (ac == 2)
	{
		ft_create_tab(av[1]);
	}
	return (0);
}
