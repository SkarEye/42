#  ______  _     _    _    _     _       _    _  _  _        ______  
# (_____ \| |   | |  | |  | |   | |     | |  | || || |  /\  (_____ \ 
#  _____) ) |   | |   \ \ | |__ | |      \ \ | || || | /  \  _____) )
# |  ____/| |   | |    \ \|  __)| |       \ \| ||_|| |/ /\ \|  ____/ 
# | |     | |___| |_____) ) |   | |   _____) ) |___| | |__| | |      
# |_|      \______(______/|_|   |_|  (______/ \______|______|_|      

# === Project name ===
NAME		:= push_swap

# === Compiler and Flags ===
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iincludes -MMD
RM			:= rm -f
MKDIR		:= mkdir -p

# === Object folder ===
OBJ_DIR		:= .objects/

# === Source files ===
OPS			:= ./operations/
ALGOS		:= ./algorithms/
UTILS		:= ./utils/
SRC		:= push_swap.c \
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

# === Object and Dependency files ===
OBJ		:= $(SRC:%.c=$(OBJ_DIR)%.o)
DEP		:= $(OBJ:.o=.d)

# === Default target ===
all: $(NAME)


# === Linking ===
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# === Compilation rule ===
$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# === Include dependencies ===
-include $(DEP)

# === Cleaning ===
clean:
	$(RM) $(OBJ) $(DEP)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re