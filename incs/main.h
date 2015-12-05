#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFSIZE		1

<<<<<<< HEAD
<<<<<<< HEAD
typedef struct			s_tetr
{
	int					id;
	char				**pattern;
	struct	s_tetr		*next;
}						t_tetr;

void					ft_lst_pushback(t_tetr **begin, char **data);
t_tetr					*ft_create_elem(char **pattern);
t_tetr					*ft_check_tab(char *s, int n);
void					ft_create_tab(char *av);

int						check_tetr(int fd);
=======
typedef struct		s_tetr
{
	int				id;
	char			**pattern;
	struct	s_tetr	*next;
}					t_tetr;

void				ft_lst_pushback(t_tetr **begin, char **data);
t_tetr				*ft_create_elem(char **pattern);
void				ft_create_tab(char *av);
>>>>>>> d9d0d6afedafc9d291952a3f69f3136467bede09
=======
typedef struct		s_tetr
{
	int				id;
	char			**pattern;
	struct	s_tetr	*next;
}					t_tetr;

void				ft_lst_pushback(t_tetr **begin, char **data);
t_tetr				*ft_create_elem(char **pattern);
void				ft_create_tab(char *av);
>>>>>>> d9d0d6afedafc9d291952a3f69f3136467bede09

#endif
