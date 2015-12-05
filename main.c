/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:50:20 by alallema          #+#    #+#             */
/*   Updated: 2015/12/05 16:49:28 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "main.h"

int		main(int ac, char *av)
{
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
