#ifndef MAIN_H
# define MAIN_H

typedef struct	s_tetr
{
	int			id;
	char		*pattern;
	struct	s_tetr		*next;
}				t_tetr;

void			ft_lst_pushback(t_tetr *begin, char *data);
t_tetr			*ft_create_elem(char *pattern);

#endif
