# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpallies <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 12:56:26 by rpallies          #+#    #+#              #
#    Updated: 2015/12/04 14:56:36 by rpallies         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
STD =		\033[39m

NAME =		fillit
EXEC =		main.c

LDIR =		./libs/
LIBS =		-lft

IDIR =		./incs/
INCS =		libft.h

SDIR =		./srcs/
SRCS =		read_tetr.c

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)

FLAG =		-Wall -Wextra -Werror -I$(IDIR)

all: $(NAME)

$(NAME): header $(OBJS)
	@echo "  ${BLU}+Compilation:${STD} $@"
	@gcc $(EXEC) $(OBJS) -L$(LDIR) $(LIBS) -o $(NAME)
	@echo "  ${YEL}Compilation terminee !${STD}"

%.o: $(SDIR)%.c
	@echo " ${GRE}+Compilation :${STD} $^"
	@gcc $^ $(FLAG) -c
	@mv $@ $(ODIR)$@

header:
	@clear
	@echo "${YEL}"
	@echo "  ==================="
	@echo "  |  Projet Fillit  |"
	@echo "  ==================="
	@echo "${STD}"

norme: header
	@echo "${GRE}  Verification de la norme${STD}\n"
	@norminette $(SRCS) libft.h
	@echo "${RED}  \nTotal errors :${STD}" $(shell norminette $(SRCS) $(INCS) | grep -v "Norme" | wc -l)

clean: header
	@echo " ${RED}-Nettoyage des fichiers objet...${STD}"
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo " ${RED}-Nettoyage de l'exécutable...${STD}"

re: fclean all
