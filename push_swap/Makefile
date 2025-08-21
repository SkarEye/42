#  ______  _     _    _    _     _       _    _  _  _        ______  
# (_____ \| |   | |  | |  | |   | |     | |  | || || |  /\  (_____ \ 
#  _____) ) |   | |   \ \ | |__ | |      \ \ | || || | /  \  _____) )
# |  ____/| |   | |    \ \|  __)| |       \ \| ||_|| |/ /\ \|  ____/ 
# | |     | |___| |_____) ) |   | |   _____) ) |___| | |__| | |      
# |_|      \______(______/|_|   |_|  (______/ \______|______|_|      

# === Project name ===
NAME		:= push_swap
CHECKER		:= checker
LIB			:=libps.a

# === Compiler and Flags ===
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iincludes -MMD
AR			:= ar rcs
RM			:= rm -f
MKDIR		:= mkdir -p

# === Object folder ===
OBJ_DIR		:= .objects/

# === Source files ===
SRC_DIR		:= src/
OPS			:= operations/
ALGOS		:= algorithms/
UTILS		:= utils/
BONUS	:= bonus/
SRC			:= \
			$(SRC_DIR)$(UTILS)int_tab_utils.c \
			$(SRC_DIR)$(UTILS)node_utils.c \
			$(SRC_DIR)$(UTILS)stack_utils.c \
			$(SRC_DIR)error_utils.c \
			$(SRC_DIR)$(OPS)push.c \
			$(SRC_DIR)$(OPS)rev_rotate.c \
			$(SRC_DIR)$(OPS)rotate.c \
			$(SRC_DIR)$(OPS)swap.c \
			$(SRC_DIR)$(OPS)op_utils.c \
			$(SRC_DIR)$(ALGOS)algo_helper.c \
			$(SRC_DIR)$(ALGOS)small_sort.c \
			$(SRC_DIR)$(ALGOS)radix_sort.c \
			$(SRC_DIR)$(ALGOS)greedy_sort.c \
			$(SRC_DIR)$(ALGOS)xtra_greedy_sort.c \
			$(SRC_DIR)$(ALGOS)fatboi_sort.c \
			$(SRC_DIR)$(BONUS)get_next_line.c
SRC_PUSH	:= push_swap.c
SRC_CHECKER	:= checker.c

# === Object and Dependency files ===
OBJ			:= $(SRC:%.c=$(OBJ_DIR)%.o)
OBJ_PUSH	:= $(SRC_PUSH:%.c=$(OBJ_DIR)%.o)
OBJ_CHECKER	:= $(SRC_CHECKER:%.c=$(OBJ_DIR)%.o)

DEP			:= $(OBJ:.o=.d) $(OBJ_PUSH:.o=.d) $(OBJ_CHECKER:.o=.d)

# === Default target ===
all: $(NAME)

# === Bonus target ===
bonus: $(CHECKER)

# === Library ===
$(LIB): $(OBJ)
	$(AR) $@ $^

# === Executables ===
$(NAME): $(OBJ_PUSH) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

$(CHECKER): $(OBJ_CHECKER) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

# === Compilation rule ===
$(OBJ_DIR)%.o: %.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# === Include dependencies ===
-include $(DEP)

# === Cleaning ===
clean:
	$(RM) $(OBJ) $(OBJ_PUSH) $(OBJ_CHECKER) $(DEP)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(CHECKER) $(LIB)

re: fclean all

.PHONY: all bonus clean fclean re