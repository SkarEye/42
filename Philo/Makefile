# `7MM"""Mq.`7MM          db  `7MM
#   MM   `MM. MM                MM
#   MM   ,M9  MMpMMMb.  `7MM    MM  ,pW"Wq.
#   MMmmdM9   MM    MM    MM    MM 6W'   `Wb
#   MM        MM    MM    MM    MM 8M     M8
#   MM        MM    MM    MM    MM YA.   ,A9
# .JMML.    .JMML  JMML..JMML..JMML.`Ybmd9'

# === Project name ===
NAME_MAND	= philo
NAME_BONUS	= philo_bonus

# === Compiler and Flags ===
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
EXPLICIT 	?= 0

# === Directories ===
UTILS_DIR	= utils
MAND_DIR	= mandatory
BONUS_DIR	= bonus
SRC_DIR		= src
INC_DIR		= include
OBJ_DIR		= .obj

# === Utils files ===
UTILS_SRC	= ft_atou_safe.c ft_itoa.c ft_strlcpy.c ft_strlen.c ft_utoa.c
UTILS_SRC	:= $(addprefix $(UTILS_DIR)/$(SRC_DIR)/, $(UTILS_SRC))

# === Mandatory Source files ===
MAND_SRC	= main.c error.c monitor.c print_action.c routine.c sim_helper.c \
			  simulation.c
MAND_SRC	:= $(addprefix $(MAND_DIR)/$(SRC_DIR)/, $(MAND_SRC)) \
			  $(UTILS_SRC)

# === Bonus Source files ===
BONUS_SRC	= main.c error.c monitor.c print_action.c routine.c sim_helper.c \
			  simulation.c spawn.c
BONUS_SRC	:= $(addprefix $(BONUS_DIR)/$(SRC_DIR)/, $(BONUS_SRC)) \
			  $(UTILS_SRC)
			
# === Build mode selection ===
MODE		?= mandatory

ifeq ($(MODE), mandatory)
NAME		= $(NAME_MAND)
SRC			= $(MAND_SRC)
OBJ_SUBDIR	= $(MAND_DIR)
INC_FLAGS	= -I$(INC_DIR) -I$(MAND_DIR)/$(INC_DIR) -I$(UTILS_DIR)/$(INC_DIR)
else ifeq ($(MODE), bonus)
NAME		= $(NAME_BONUS)
SRC			= $(BONUS_SRC)
OBJ_SUBDIR	= $(BONUS_DIR)
INC_FLAGS	= -I$(INC_DIR) -I$(BONUS_DIR)/$(INC_DIR) -I$(UTILS_DIR)/$(INC_DIR)
else
$(error Unknown MODE: '$(MODE)'. (use mandatory or bonus))
endif

# === Object files ===
OBJ			= $(addprefix $(OBJ_DIR)/$(OBJ_SUBDIR)/,$(SRC:.c=.o))
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
CFLAGS		+= -g3 -fsanitize=thread -DDEBUG=1
EXPLICIT	:= 1
DEBUG_MSG	:= @echo "$(PURPLE)DEBUG mode is activated.$(RESET)"
else ifneq ($(BUILD), Default)
$(error Unknown BUILD option: '$(BUILD)'. Valid options are: c98, debug, Default)
endif

# === Default target ===
all: $(NAME)

# === Bonus target ===
bonus:
	@$(MAKE) MODE=bonus re

# === Compilation rules ===
# - Executable -
$(NAME): $(OBJ)
	@echo "$(BLUE)Linking [$(NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)$(NAME) compiled successfully.$(RESET)"
	$(DEBUG_MSG)


# - Objects -
$(OBJ_DIR)/$(OBJ_SUBDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@echo "$(GRAY)$(CC) $(CFLAGS) $(INC_FLAGS) -MMD -c $< -o $@$(RESET)"
	@$(CC) $(CFLAGS) $(INC_FLAGS) -MMD -c $< -o $@
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
	@if [ -f $(NAME_MAND) ]; then \
		rm -f $(NAME_MAND); \
		echo "$(RED)Removing executable $(NAME_MAND)...$(RESET)"; \
	else \
		echo "$(YELLOW)No executable $(NAME_MAND) to remove.$(RESET)"; \
	fi
	@if [ -f $(NAME_BONUS) ]; then \
		rm -f $(NAME_BONUS); \
		echo "$(RED)Removing executable $(NAME_BONUS)...$(RESET)"; \
	else \
		echo "$(YELLOW)No executable $(NAME_BONUS) to remove.$(RESET)"; \
	fi

# - re -
re: fclean all

# === Dependencies ===
-include $(DEP)

# === Help ===
help:
	@echo "Makefile for $(NAME_MAND)\n"
	@echo "Available targets:"
	@echo "  all     - Compile the project (default)"
	@echo "  clean   - Remove object files"
	@echo "  fclean  - Remove object files and executable"
	@echo "  re      - Recompile the project"
	@echo "  help    - Display this help message\n"
	@echo "Build options:"
	@echo "  BUILD=debug  - compile with debug information\n"
	@echo "Set EXPLICIT=1 to show detailed compilation output."

.PHONY: all clean fclean re help bonus