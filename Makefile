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
