/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:07:56 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/05 17:13:21 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_HPP
#define ANSI_HPP

# define ANSI_RESET			"\001\033[0m\002"
# define ANSI_BOLD			"\001\033[1m\002"
# define ANSI_ITALIC		"\001\033[3m\002"
# define ANSI_UNDERLINE		"\001\033[4m\002"
# define ANSI_BLINK			"\001\033[5m\002"
# define ANSI_REVERSE		"\001\033[7m\002"
# define ANSI_HIDDEN		"\001\033[8m\002"
# define ANSI_STRIKETHROUGH	"\001\033[9m\002"

# define ANSI_BLACK			"\001\033[30m\002"
# define ANSI_RED			"\001\033[31m\002"
# define ANSI_GREEN			"\001\033[32m\002"
# define ANSI_YELLOW		"\001\033[33m\002"
# define ANSI_BLUE			"\001\033[34m\002"
# define ANSI_MAGENTA		"\001\033[35m\002"
# define ANSI_CYAN			"\001\033[36m\002"
# define ANSI_WHITE			"\001\033[37m\002"

# define ANSI_BBLACK		"\001\033[90m\002"
# define ANSI_BRED			"\001\033[91m\002"
# define ANSI_BGREEN		"\001\033[92m\002"
# define ANSI_BYELLOW		"\001\033[93m\002"
# define ANSI_BBLUE			"\001\033[94m\002"
# define ANSI_BMAGENTA		"\001\033[95m\002"
# define ANSI_BCYAN			"\001\033[96m\002"
# define ANSI_BWHITE		"\001\033[97m\002"

# define ANSI_BG_BLACK		"\001\033[40m\002"
# define ANSI_BG_RED		"\001\033[41m\002"
# define ANSI_BG_GREEN		"\001\033[42m\002"
# define ANSI_BG_YELLOW		"\001\033[43m\002"
# define ANSI_BG_BLUE		"\001\033[44m\002"
# define ANSI_BG_MAGENTA	"\001\033[45m\002"
# define ANSI_BG_CYAN		"\001\033[46m\002"
# define ANSI_BG_WHITE		"\001\033[47m\002"

# define ANSI_BBG_BLACK		"\001\033[100m\002"
# define ANSI_BBG_RED		"\001\033[101m\002"
# define ANSI_BBG_GREEN		"\001\033[102m\002"
# define ANSI_BBG_YELLOW	"\001\033[103m\002"
# define ANSI_BBG_BLUE		"\001\033[104m\002"
# define ANSI_BBG_MAGENTA	"\001\033[105m\002"
# define ANSI_BBG_CYAN		"\001\033[106m\002"
# define ANSI_BBG_WHITE		"\001\033[107m\002"

void	print_message(const char *object, const char *message, bool newline);
void	print_warning(const char *message, bool newline);
void	print_error(const char *message, bool newline);
void	print_success(const char *message, bool newline);
void	print_info(const char *message, bool newline);
void	print_debug(const char *message, bool newline);
void	print_nl(void);

#endif
