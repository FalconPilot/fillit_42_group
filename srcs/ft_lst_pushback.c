/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:51:33 by alallema          #+#    #+#             */
/*   Updated: 2015/12/05 16:35:25 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

void	ft_lst_push_back(t_tetr **begin_list, char **data)
{
	t_tetr	*elem;

	elem = *begin_list;
	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
	}
	else
	{
		while (elem->next != NULL)
				elem = elem->next;
		elem->next = ft_create_elem(data);
	}
}

