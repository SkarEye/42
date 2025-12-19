#  _______  _______  _______ 
# |       ||       ||       |
# |       ||    _  ||    _  |
# |       ||   |_| ||   |_| |  ___   ___
# |      _||    ___||    ___| |   | |_  |
# |     |_ |   |    |   |     | | | |_  |
# |_______||___|    |___|     |___| |___|
# === Project name ===
DIR			= ex03
NAME		= shiny_little_sentient_robot

# === Compiler and Flags ===
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -MMD -MP
EXPLICIT 	:= 0

# === Directories ===
SRC_DIR		= ./
INC_DIR		= ./
OBJ_DIR		= .obj

# === Source files ===
SRC_FILES	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

# === Object files ===
OBJ_FILES	= $(SRC_FILES:.cpp=.o)

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

ifeq ($(BUILD), c98)
CFLAGS		+= -std=c++98
else ifeq ($(BUILD), debug)
CFLAGS		+= -g -std=c++98 -DDEBUG=1
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
	$(DEBUG_MSG)

# - Objects -
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@echo "$(GRAY)$(CC) $(CFLAGS) -c $< -o $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@if [ $(EXPLICIT) -eq 0 ]; then \
		printf "$(UP)$(CLEAR)$(UP)$(CLEAR)"; \
	fi

# - Dependencies -
-include $(DEP)

# === Cleaning rules ===
# - clean -
clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		echo "$(RED)Removing object files from $(DIR)...$(RESET)"; \
	else \
		echo "$(YELLOW)No object files to remove from $(DIR).$(RESET)"; \
	fi

# - fclean -
fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo "$(RED)Removing executable $(NAME) from $(DIR)...$(RESET)"; \
	else \
		echo "$(YELLOW)No executable $(NAME) to remove from $(DIR).$(RESET)"; \
	fi

# - re -
re: fclean all

# === Help ===
help:
	@echo "Makefile for $(NAME) in $(DIR)\n"
	@echo "Available targets:"
	@echo "  all     - Compile the project (default)"
	@echo "  clean   - Remove object files"
	@echo "  fclean  - Remove object files and executable"
	@echo "  re      - Recompile the project"
	@echo "  help    - Display this help message\n"
	@echo "Build options:"
	@echo "  BUILD=c98    - Compile with C++98 standard"
	@echo "  BUILD=debug  - Compile with debug information\n"
	@echo "Set EXPLICIT=1 to show detailed compilation output."

.PHONY: all clean fclean re help