/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:12:20 by alallema          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/12/09 19:37:30 by alallema         ###   ########.fr       */
=======
/*   Updated: 2015/12/09 17:14:45 by rpallies         ###   ########.fr       */
>>>>>>> ea2f2479a9c5a012c82ebe1d516961a350ff98b8
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFSIZE		1

typedef struct			s_tetr
{
	int					id;
	char				**pattern;
	struct s_tetr		*next;
}						t_tetr;

void					ft_lst_pushback(t_tetr **begin, char **data);
t_tetr					*ft_create_elem(char **pattern);
t_tetr					*ft_check_tab(char *s, int n);
void					ft_create_tab(char *av);

void    				error_display(int errid);
int						check_tetr(int fd);

#endif
