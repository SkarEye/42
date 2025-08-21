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
SRC_DIR		:= ./src/
OPS			:= ./operations/
ALGOS		:= ./algorithms/
UTILS		:= ./utils/
SRC		:=	push_swap.c \
			$(SRC_DIR)$(UTILS)int_tab_utils.c \
			$(SRC_DIR)$(UTILS)node_utils.c \
			$(SRC_DIR)$(UTILS)stack_utils.c \
			$(SRC_DIR)$(OPS)push.c \
			$(SRC_DIR)$(OPS)rev_rotate.c \
			$(SRC_DIR)$(OPS)rotate.c \
			$(SRC_DIR)$(OPS)swap.c \
			$(SRC_DIR)$(ALGOS)algo_helper.c \
			$(SRC_DIR)$(ALGOS)small_sort.c \
			$(SRC_DIR)$(ALGOS)radix_sort.c \
			$(SRC_DIR)$(ALGOS)greedy_sort.c \
			$(SRC_DIR)$(ALGOS)xtra_greedy_sort.c \
			$(SRC_DIR)$(ALGOS)fatboi_sort.c \
			$(SRC_DIR)error_utils.c

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
	@$(MKDIR) $(dir $@)
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