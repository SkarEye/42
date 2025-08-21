/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   going_too_far.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:39:36 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/08/19 16:41:50 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  // to be rm-ed
#include "structures.h"

# define FLAG_PA 1
# define FLAG_PB 2
# define FLAG_RA 4
# define FLAG_RB 8
# define FLAG_RRA 16
# define FLAG_RRB 32
# define FLAG_SA 64
# define FLAG_SB 128

void    print_stacks(t_stack *a, t_stack *b)
{
	t_node  *na = a ? a->head : NULL;
	t_node  *nb = b ? b->head : NULL;

	printf("   A\t\tB\n");
	printf("  ---\t\t---\n");
	while (na || nb)
	{
		if (na)
		{
			printf("%5d, ", na->value);
			printf("%5zu", na->index);
			na = na->next;
		}
		else
			printf("     ");
		printf("\t");
		if (nb)
		{
			printf("%5d", nb->value);
			nb = nb->next;
		}
		printf("\n");
	}
	printf("  ---\t\t---\n\n");
}




int	*create_int_tab_from_stack(t_stack *stack)
{
	int		*tab;
	t_node	*current;
	size_t	i;

	if (!stack || stack->size == 0)
		return (NULL);
	tab = malloc(sizeof(int) * stack->size);
	if (!tab)
		return (NULL);
	current = stack->head;
	i = 0;
	while (current)
	{
		tab[i++] = current->value;
		current = current->next;
	}
	return (tab);
}