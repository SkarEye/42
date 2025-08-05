/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:15:16 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/02 18:44:03 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "utils.h"

static ssize_t	count_words(const char *str, char c)
{
	ssize_t	count;
	size_t	i;

	if (!str)
		return (-1);
	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*make_word(const char *str, size_t *parsed, char c)
{
	char	*word;
	size_t	i;

	if (*parsed < ft_strlen(str))
		return (NULL); //Cannot write in str
	while (str[*parsed] && str[*parsed] != c)
		(*parsed)++;
	word = (char *)malloc((*parsed + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (str[*parsed] && str[*parsed] != c)
		word[i++] = str[(*parsed)++];
	word[i] = '\0';
	return (word);
}

void	free_split(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	ssize_t	count;
	size_t	n;
	size_t	i;

	count = count_words(str, c);
	if (count < 0)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	n = 0;
	i = 0;
	while (n < (size_t)count)
	{
		if (str[i] == c)
			i++;
		split[n] = make_word(str, &i, c);
		if (!split[n])
			return (free_split(split), NULL);
	}
	split[n] = NULL;
	return (split);
}
