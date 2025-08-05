/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:03:55 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/02 17:34:41 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#include "error_utils.h"

#include "args_helper.h"

static ssize_t	parse(char **args, bool is_quoted)
{
	ssize_t len;

	if (!*args)
		return (print_error(ERR_LOC, ERR_BAD_ARGS, SILENT), -1);
	if (**args != '"' && is_quoted)
		return (print_error(ERR_LOC, ERR_START_QUOTE, SILENT), -1);
	else if (is_quoted)
		(*args)++;
	len = 0;
	while (**args && **args != '"')
	{
		if (**args == ' ' && !is_quoted)
			return (len);
		else if (**args == '\\')
			(*args)++;
		if (!(**args))
			return (print_error(ERR_LOC, ERR_BAD_ESC, SILENT), -1);
		len++;
		(*args)++;
	}
	if (**args != '"' && is_quoted)
		return (print_error(ERR_LOC, ERR_END_QUOTE, SILENT), -1);
	else if (is_quoted)
		(*args)++;
	return (len);
}

ssize_t get_arg_length(char **args, char *str)
{
	ssize_t len;
	ssize_t parsed;
	char	*ptr;

	if (!*args)
		return (-1);
	len = 0;
	while (**args && **args != ' ' && **args != '\t' && **args != '\n')
	{
		if (str)
			ptr = &str[len];
		else
			ptr = NULL;
		if (**args == '"')
			parsed = parse(args, ptr, true);
		else
			parsed = parse(args, ptr, false);
		if (parsed < 0)
			return (print_error(ERR_LOC, ERR_BAD_ARGS, SILENT), -1);
		len += parsed;
	}
	if (str)
		str[len] = '\0';
	return (len);
}

ssize_t count_args(char *args)
{
	ssize_t count;

	if (!args)
		return (-1);
	count = 0;
	while (*args)
	{
	while (*args == ' ' || *args == '\t' || *args == '\n')
		args++;
		if (*args)
		{
			if (parse_arg(&args, NULL) < 0)
				return (print_error(ERR_LOC, ERR_BAD_ARGS, SILENT), -1);
			count++;
		}
	}
	return (count);
}


#include <stdio.h>
#include <string.h>

// Structure to hold test case and expected result
// typedef struct s_test_case {
// 	const char *input;
// 	ssize_t expected_count;
// }	t_test_case;

// int main(void)
// {
// 	t_test_case tests[] = {
// 		// Basic cases
// 		{"foo bar baz", 3},
// 		{"   foo     bar   ", 2},
// 		{"\"\"", 1},
// 		{"\"foo\"", 1},
// 		{"\"foo bar\"", 1},
// 		{"foo \"bar baz\"", 2},
// 		{"foo \"bar baz\" qux", 3},

// 		// Escaped characters
// 		{"foo\\ bar baz", 2},
// 		{"\"foo\\\\bar\"", 1},
// 		{"\"foo\\\"bar\"", 1},
// 		{"foo\\\\ bar", 2},
// 		{"foo \"bar\\\\\\\"baz\"", 2},

// 		// Invalid cases (should return -1)
// 		{"\"foo bar", -1},
// 		{"foo \"bar baz", -1},
// 		{"foo \"bar\\", -1},
// 		{"foo \"bar\\\"", -1},

// 		// Mixed quoted/unquoted
// 		{"\"foo\"\"bar\"", 1},
// 		{"foo\"bar\"", 1},
// 		{"\"foo\"bar\"baz\"", 1},
// 		{"\"\"foo\"\"", 1},
// 		{"\"foo\"\"bar\" baz", 2},

// 		// Edge cases
// 		{"   ", 0},
// 		{"\"\" \"\" \"\"", 3},
// 		{"foo \"\" bar", 3},

// 		{NULL, 0} // Sentinel to mark end
// 	};

// 	for (int i = 0; tests[i].input != NULL; i++)
// 	{
// 		char *input = strdup(tests[i].input); // Make a mutable copy
// 		char *cursor = input; // Because arg_count expects char **
// 		ssize_t result = args_count(&cursor);

// 		printf("Test %2d: %-30s | Expected: %2zd | Got: %2zd | %s\n",
// 			i + 1,
// 			tests[i].input,
// 			tests[i].expected_count,
// 			result,
// 			(result == tests[i].expected_count) ? "✅" : "❌");

// 		free(input);
// 	}
// 	return (0);
// }

int	main(void)
{
const char *tests[] = {
	"\"foo bar\"baz",                   // mix of quoted and unquoted with no space
	"foo\"bar\"baz",                   // alternating unquoted/quoted/unquoted
	"\"foo \\\"bar\\\" baz\"",         // quoted string with escaped quotes
	"\"multi\nline\"",                 // newline in quoted string (undefined for shell, but good for robustness)
	"\"\\\"quoted\\\"\"",              // double escaped quotes
	"\"a b c\"   \"d e f\"   g",       // multiple quoted + unquoted
	"\"nested \\\"quotes\\\" inside\"",// escaped quotes inside quotes
	"foo\\ bar\\ baz",                // all escaped spaces
	"\"foo\\\\bar\"",                 // double backslash in quoted
	"\"\"",                           // empty quoted string
	"   ",                            // just spaces
	"",                               // empty input
	"\"ends with quote\"",            // valid
	"no_closing_quote \"oops",        // should return NULL
	"\"concat\"\"this\"\"all\"",      // three quoted strings with no space
	"\\\"escaped\\\" alone",          // escaped quotes at beginning
	"\"test\\",                       // ends with backslash inside quote (should fail)
	"foo\\",                          // ends with backslash outside quote
	NULL
};

	for (int i = 0; tests[i]; i++)
	{
		printf("Input: [%s]\n", tests[i]);
		char *input = (char *)tests[i]; // cast away const
		char **split = split_args(input);

		if (!split)
		{
			printf("  -> Parsing failed (NULL returned)\n\n");
			continue;
		}

		printf("  Split result:\n");
		for (int j = 0; split[j]; j++)
			printf("    [%s]\n", split[j]);
		printf("\n");

		free_split(split);
	}
	return 0;
}
