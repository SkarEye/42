/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:48:17 by macarnie          #+#    #+#             */
/*   Updated: 2025/07/11 17:01:11 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "structures.h"
#include "list_utils.h"

void	free_list(t_list **list)
{
	t_list	*current;
	t_list	*next_node;

	if (!list || !*list)
		return ;
	current = *list;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*list = NULL;
}

bool	add_to_list(t_list **list, void *content)
{
	t_list	*new_node;
	t_list	*current;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (free_list(list), 0);
	new_node->content = content;
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return (true);
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (true);
}
