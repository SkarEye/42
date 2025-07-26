NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.

OPS			= ./operations/
ALGOS		= ./algorithms/
UTILS		= ./utils/
SRCS		= push_swap.c \
			$(UTILS)node_utils.c \
			$(UTILS)stack_utils.c \
			$(UTILS)int_tab_utils.c \
			$(UTILS)algo_utils.c \
			$(OPS)push.c \
			$(OPS)rotate.c \
			$(OPS)rev_rotate.c \
			$(OPS)swap.c \
			$(ALGOS)radix_sort.c \
			$(ALGOS)greedy_sort.c \
			$(ALGOS)xtra_greedy_sort.c \
			$(ALGOS)fatboi_sort.c \
			
OBJS		= $(SRCS:.c=.o)

HEADER 		= push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

algorithms/fatboi_sort.o : algorithms/fatboi_sort.c push_swap.h

$(OPS)%.o: $(OPS)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re