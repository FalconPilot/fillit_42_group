/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:57:13 by alallema          #+#    #+#             */
/*   Updated: 2015/12/09 19:37:47 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

t_tetr		*ft_create_elem(char **pattern)
{
	t_tetr	*elem;

	elem = (t_tetr*)malloc(sizeof(t_tetr));
	if (elem != NULL)
	{
		elem->pattern = pattern;
		elem->next = NULL;
	}
	return (elem);
}
