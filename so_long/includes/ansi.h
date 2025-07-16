/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:00:35 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/09 18:19:58 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_H
# define ANSI_H

# define ANSI_ESC	"\033["

# define ANSI_RESET			ANSI_ESC "0m"
# define ANSI_BOLD			ANSI_ESC "1m"
# define ANSI_UNDERLINE		ANSI_ESC "4m"
# define ANSI_BLINK			ANSI_ESC "5m"
# define ANSI_REVERSE		ANSI_ESC "7m"
# define ANSI_HIDDEN		ANSI_ESC "8m"
# define ANSI_STRIKETHROUGH	ANSI_ESC "9m"

# define ANSI_BLACK			ANSI_ESC "30m"
# define ANSI_RED			ANSI_ESC "31m"
# define ANSI_GREEN			ANSI_ESC "32m"
# define ANSI_YELLOW		ANSI_ESC "33m"
# define ANSI_BLUE			ANSI_ESC "34m"
# define ANSI_MAGENTA		ANSI_ESC "35m"
# define ANSI_CYAN			ANSI_ESC "36m"
# define ANSI_WHITE			ANSI_ESC "37m"

# define ANSI_BBLACK		ANSI_ESC "90m"
# define ANSI_BRED			ANSI_ESC "91m"
# define ANSI_BGREEN		ANSI_ESC "92m"
# define ANSI_BYELLOW		ANSI_ESC "93m"
# define ANSI_BBLUE			ANSI_ESC "94m"
# define ANSI_BMAGENTA		ANSI_ESC "95m"
# define ANSI_BCYAN			ANSI_ESC "96m"
# define ANSI_BWHITE		ANSI_ESC "97m"

# define ANSI_BG_BLACK		ANSI_ESC "40m"
# define ANSI_BG_RED		ANSI_ESC "41m"
# define ANSI_BG_GREEN		ANSI_ESC "42m"
# define ANSI_BG_YELLOW		ANSI_ESC "43m"
# define ANSI_BG_BLUE		ANSI_ESC "44m"
# define ANSI_BG_MAGENTA	ANSI_ESC "45m"
# define ANSI_BG_CYAN		ANSI_ESC "46m"
# define ANSI_BG_WHITE		ANSI_ESC "47m"

# define ANSI_BBG_BLACK		ANSI_ESC "100m"
# define ANSI_BBG_RED		ANSI_ESC "101m"
# define ANSI_BBG_GREEN		ANSI_ESC "102m"
# define ANSI_BBG_YELLOW	ANSI_ESC "103m"
# define ANSI_BBG_BLUE		ANSI_ESC "104m"
# define ANSI_BBG_MAGENTA	ANSI_ESC "105m"
# define ANSI_BBG_CYAN		ANSI_ESC "106m"
# define ANSI_BBG_WHITE		ANSI_ESC "107m"

#endif