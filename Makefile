##
## Makefile for makefile in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_philo
## 
## Made by Fanny Tavart
## Login   <fanny.tavart@epitech.net>
## 
## Started on  Mon Mar  6 12:12:26 2017 Fanny Tavart
## Last update Sat Mar 18 19:45:08 2017 Ronan Boiteau
##

CC		= gcc

RM		= rm -f

NAME		= philo

CFLAGS		= -W -Wextra
CFLAGS		+= -Werror
CFLAGS		+= -I ./include

SRCS_MY		= my/
SRCS_FMY	= my_atoi.c

SRCS_DIR	= src/
SRCS_FILES	= get_args.c		\
		  thread_functions.c	\
		  init_functions.c	\
		  check_actions.c	\
		  philo_activities.c	\
		  get_min_activity.c	\
		  main.c

SRCS		= $(addprefix $(SRCS_MY), $(SRCS_FMY)) \
		  $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS) -L. -lriceferee -lpthread -D_REENTRANT

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
