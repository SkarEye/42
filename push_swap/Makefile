NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.

OPS			= ./operations
SRCS		= push_swap.c \
			node_utils.c \
			stack_utils.c \
			int_tab_utils.c \
			$(OPS)/push.c \
			$(OPS)/rotate.c \
			$(OPS)/rev_rotate.c \
			$(OPS)/swap.c \
			radix_sort.c
			
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re