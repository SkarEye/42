CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I get_next_line
GNL = get_next_line/gnl.a

SRC = main.c
OBJ = $(SRC:.c=.o)
NAME = test

all: $(NAME)

$(NAME): $(OBJ) $(GNL)
	$(CC) $(CFLAGS) $(OBJ) $(GNL) -o $(NAME)

$(GNL):
	make -C get_next_line

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C get_next_line clean

fclean: clean
	rm -f $(NAME)
	make -C get_next_line fclean

re: fclean all

.PHONY: all clean fclean re