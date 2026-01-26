# `7MM"""Mq.`7MM          db  `7MM          
#   MM   `MM. MM                MM          
#   MM   ,M9  MMpMMMb.  `7MM    MM  ,pW"Wq. 
#   MMmmdM9   MM    MM    MM    MM 6W'   `Wb
#   MM        MM    MM    MM    MM 8M     M8
#   MM        MM    MM    MM    MM YA.   ,A9
# .JMML.    .JMML  JMML..JMML..JMML.`Ybmd9' 

# === Project name ===
NAME		= philo

# === Compiler and Flags ===
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=thread
EXPLICIT 	:= 0

# === Directories ===
UTILS_DIR	= utils
SRC_DIR		= src
INC_DIR		= include
OBJ_DIR		= .obj

# === Utils files ===
UTILS_FILES	= ft_atou_safe.c ft_itoa.c ft_strlcpy.c ft_strlen.c ft_utoa.c

# === Source files ===
SRC_FILES	= main.c error.c monitor.c print_action.c routine.c \
			  sim_helper.c simulation.c \
			  $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))

# === Object files ===
OBJ_FILES	= $(SRC_FILES:.c=.o)

# === Includes ===
INCLUDES	= -I$(INC_DIR)

# === Paths ===
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
DEP			= $(OBJ:.o=.d)

# === Escape codes ===
RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
RED			= \033[31m
PURPLE		= \033[35m
GRAY		= \033[90m
UP			= \033[A
CLEAR		= \033[2K

# === Build rules ===
BUILD		?= Default
DEBUG_MSG	:=

ifeq ($(BUILD), debug)
CFLAGS		+= -g -DDEBUG=1
EXPLICIT	:= 1
DEBUG_MSG	:= @echo "$(PURPLE)DEBUG mode is activated.$(RESET)"
else ifneq ($(BUILD), Default)
$(error Unknown BUILD option: '$(BUILD)'. Valid options are: c98, debug, Default)
endif

# === Default target ===
all: $(NAME)

# === Compilation rules ===
# - Executable -
$(NAME): $(OBJ)
	@echo "$(BLUE)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

# - Objects -
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@echo "$(GRAY)$(CC) $(CFLAGS) -c $< -o $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@if [ "$(EXPLICIT)" = "0" ]; then \
		printf "$(UP)$(CLEAR)$(UP)$(CLEAR)"; \
	fi

# === Cleaning rules ===
# - clean -
clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		echo "$(RED)Removing object files...$(RESET)"; \
	else \
		echo "$(YELLOW)No object files to remove.$(RESET)"; \
	fi

# - fclean -
fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo "$(RED)Removing executable $(NAME)...$(RESET)"; \
	else \
		echo "$(YELLOW)No executable $(NAME) to remove.$(RESET)"; \
	fi

# - re -
re: fclean all

# === Help ===
help:
	@echo "Makefile for $(NAME)\n"
	@echo "Available targets:"
	@echo "  all     - Compile the project (default)"
	@echo "  clean   - Remove object files"
	@echo "  fclean  - Remove object files and executable"
	@echo "  re      - Recompile the project"
	@echo "  help    - Display this help message\n"
	@echo "Build options:"
	@echo "  BUILD=debug  - compile with debug information\n"
	@echo "Set EXPLICIT=1 to show detailed compilation output."

.PHONY: all clean fclean re help