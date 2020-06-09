##
## EPITECH PROJECT, 2019
## PSU_minishell1_2019
## File description:
## Makefile
##

NAME		=	ai

LD		=	@ld
CC		=	@gcc
DIROBJ		=	objects
EXTENSION	=	.c

SRC			=	$(wildcard $(addprefix lib/my/, *)$(EXTENSION))
SRC			+=	$(wildcard $(addprefix src/, *)$(EXTENSION))
NOM			=	$(basename $(notdir $(SRC)))
OBJ			=	$(SRC:.c=.o)
SRC-CRIT	=	$(wildcard $(addprefix tests/, *)$(EXTENSION))
OBJ-CRIT	=	$(SRC-CRIT:$(EXTENSION)=.o)

NCURSFLAGS	+=	-lncurses
LDFLAGS		+=	-g3
CFLAGS		+=	-Iinclude -W -Wall -Wextra -fno-builtin -g
CRITFLAGS	=	-lcriterion --coverage
CGRAPHICS	=	-lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-graphics

END		=	\033[0m
BOLD		=	\033[1m
GREY		=	\033[30m
RED		=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PURPLE		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(LDFLAGS) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo -e "$(GREEN)=========($(BOLD) COMPLETED $(END)$(GREEN))=========$(END)"

test_run:	$(OBJ-CRIT)
	@$(CC) $(CFLAGS) $(CRITFLAGS) $(OBJ-CRIT)
	@echo -e "$(GREEN)=========($(BOLD) COMPLETED $(END)$(GREEN))=========$(END)"
	./a.out

clean:
	@find . -type f \( -iname "*~" \) -delete
	@$(RM) $(OBJ)
	@$(RM) $(OBJ-CRIT)
	@echo -e "$(RED)==========($(BOLD) CLEANED $(END)$(RED))==========$(END)"

fclean:	clean
	@$(RM) -r $(DIROBJ)
	@$(RM) $(NAME)
	@$(RM) a.out

re:	fclean all

$(DIROBJ):
	@mkdir -p $@ \
	&& echo -e "$(GREEN)[OK]\t$(CYAN)Creating:$(WHITE)$(BOLD)" $(DIROBJ) "$(END)" \
	|| echo -e "$(RED)[KO]\tCan't create:$(BOLD)" $(DIROBJ) "$(END)"

$(DIROBJ)/%.o:	src/%$(EXTENSION) | $(DIROBJ)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< \
	&& echo -e "$(GREEN)[OK]\t$(CYAN)Compiling:$(WHITE)$(BOLD)" $< "$(END)" \
	|| echo -e "$(RED)[KO]\tCan't compile:$(BOLD)" $< "$(END)"

.PHONY: all test_run clean fclean re