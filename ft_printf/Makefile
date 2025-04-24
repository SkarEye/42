CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I ft_printf
PF = ft_printf/ft_pf.a

SRC = main.c
OBJ = $(SRC:.c=.o)
NAME = test

all: $(NAME)

$(NAME): $(OBJ) $(PF)
	$(CC) $(CFLAGS) $(OBJ) $(PF) -o $(NAME)

$(PF):
	make -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re